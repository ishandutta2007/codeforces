import java.io.*;
import java.util.*;

public class superiorperiod {
  private static InputReader in;
  private static PrintWriter out;
  public static int n, arr[], g[];
  public static long count;
  public static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    n = in.nextInt();
    arr = new int[n+n];
    for (int i = 0; i < n; i++) {
      arr[i] = arr[i+n] = in.nextInt();
    }
    g = new int[n];
    for (int i = 1; i < n; i++)
      g[i] = gcd(i, n);
    
    count = 0;
    solve(1);
    for (int div = 2; div*div <= n; div++) {
      if (n % div == 0) {
        solve(div);
        if (div*div != n) solve(n/div);
      }
    }
    out.println(count);
    out.close();
    System.exit(0);
  }
  
  public static void solve(int div) {
    if (div == n) return;
    boolean[] ok = new boolean[n+n];
    for (int j = 0; j < div; j++) {
      int max = 0;
      for (int k = j; k < n+n; k += div)
        max = Math.max(max, arr[k]);
      for (int k = j; k < n+n; k += div)
        ok[k] |= arr[k] == max;
    }
    int[] cc = new int[n];
    for (int i = 1; i < n; i++) {
      cc[i] = cc[i-1] + ((g[i] == div) ? 1 : 0);
    }
    int far = 0;
    for (int j = 0; j < n; j++) {
      if (!ok[j]) continue;
      far = Math.max(far, j);
      while (far+1 < n+j && ok[far]) far++;
      count += cc[far-j];
    }
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