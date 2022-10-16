import java.io.*;
import java.util.*;

public class robinhood {
  private static InputReader in;
  private static PrintWriter out;
  public static long[] arr;
  public static long[] psum;
  
  public static long f(int from, int to) {
    if (from > to) return 0;
    long ans = psum[to];
    if (from > 0) ans -= psum[from-1];
    return ans;
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt(), k = in.nextInt();
    long sum = 0;
    arr = new long[n];
    for (int i = 0; i < n; i++) {
      arr[i] = in.nextInt();
      sum += arr[i];
    }
    for (int i = 0; i < n; i++) {
      int j = (int)(Math.random()*(i+1));
      if(i==j) continue;
      long t = arr[i]; arr[i] = arr[j]; arr[j] = t;
    }
    Arrays.sort(arr);
    psum = new long[n];
    psum[0] = arr[0];
    for (int i = 1; i < n; i++) {
      psum[i] = psum[i-1] + arr[i];
    }
    long mn = sum/n, mx = sum/n;
    if (sum%n > 0) mx++;
    long loh = mx, hih = arr[n-1];
    while (loh < hih) {
      long mid = (loh+hih)/2;
      int pos = Arrays.binarySearch(arr, mid);
      if (pos < 0) pos = -pos-1;
      long days = f(pos, n-1) - mid * (n-pos);
      if (days <= k) hih = mid;
      else loh = mid+1;
    }
    long lol = arr[0], hil = mn;
    while (lol < hil) {
      long mid = (lol+hil+1)/2;
      int pos = Arrays.binarySearch(arr, mid);
      if (pos < 0) pos = -pos-2;
      long days = mid * (pos+1) - f(0, pos);
      if (days <= k) lol = mid;
      else hil = mid-1;
    }
    out.println(loh-lol);
    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }


}