import java.io.*;
import java.util.*;

public class gcdtable {
  private static InputReader in;
  private static PrintWriter out;
  public static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    int[] a = new int[n*n];
    for (int i = 0; i < n*n; i++) a[i] = in.nextInt();
    HashMap<Integer, Integer> mp = new HashMap<>();
    for (int i = 0; i < n*n; i++) {
      Integer r = mp.get(a[i]);
      if (r == null) r = 0;
      mp.put(a[i], r+1);
    }
    
    Arrays.sort(a);
    int[] ans = new int[n];
    int idx = 0;
    int last = n*n-1;
    for (int i = 0; i < n; i++) {
      while (mp.get(a[last]) == 0) last--;
      ans[idx++] = a[last];
      for (int j = idx-1; j >= 0; j--) {
        int k = gcd(ans[idx-1], ans[j]);
        int count = j == idx-1 ? 1 : 2;
        mp.put(k, mp.get(k) - count);
      }
    }
    out.print(ans[0]);
    for (int i = 1; i < n; i++)
      out.print(" "+ans[i]);
    out.println();
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