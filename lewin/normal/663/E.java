import java.io.*;
import java.util.*;

public class binarytable {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;
  public static long INV2 = 500000004;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    int m = in.nextInt();
    char[][] grid = new char[m][n];
    for (int i = 0; i < n; i++) {
      char[] s = in.next().toCharArray();
      for (int j = 0; j < m; j++) {
        grid[j][i] = s[j];
      }
    }
    long[] freq = new long[1<<n];
    long[] cost = new long[1<<n];
    for (int i = 0; i < 1 << n; i++) {
      int x = Integer.bitCount(i);
      cost[i] = Math.min(x, n-x);
    }
    for (int i = 0; i < m; i++) {
      int num = Integer.parseInt(new String(grid[i]), 2);
      int x = Integer.bitCount(num);
      freq[num]++;
    }
    int len = (1 << n);
    transform(freq, 0, len);
    transform(cost, 0, len);
    long[] ans = new long[1<<n];
    for (int i = 0; i < 1 << n; i++) {
      ans[i] = freq[i] * cost[i] % mod;
    }
    untransform(ans, 0, len);
    long min = 1 << 30;
    for (int xor = 0; xor < 1 << n; xor++) {
      min = Math.min(min, ans[xor]);
    }
    out.println(min);
    out.close();
    System.exit(0);
  }
  static void transform(long[] a, int x, int y) {
    if(x == y - 1) {
      return;
  }
  int l2 = (y-x)/2;
  int z = x + l2;
  transform(a,x,z);
  transform(a,z,y);
  for(int i = x;i<z;i++) {
    long x1 = a[i];
    long x2 = a[i+l2];
      a[i] = (x1 - x2 + mod) % mod;
      a[i+l2] = (x1 + x2 + mod) % mod;
  }
}

static void untransform(long[] a, int x, int y) {
  if(x == y - 1) {
      return;
  }
  int l2 = (y-x)/2;
  int z = x + l2;
  for(int i = x;i<z;i++) {
      long y1 = a[i];
      long y2 = a[i+l2];
      a[i] = (y1+y2) * INV2 % mod;
      a[i+l2] = (y2-y1 + mod) * INV2 % mod;
  }
  untransform(a,x,z);
  untransform(a,z,y);
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