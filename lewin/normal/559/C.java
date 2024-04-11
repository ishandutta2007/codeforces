import java.io.*;
import java.util.*;

public class randomizer {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;
  public static long[] fact, invfact, inv;
  static class Point implements Comparable<Point> {
    public int x,y;
    public Point (int x, int y) {
      this.x = x;
      this.y = y;
    }
    
    public int compareTo(Point other) {
      return (x+y) - (other.x+other.y);
    }
  }
  
  public static long comb(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % mod * invfact[n-k] % mod;
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int h = in.nextInt(), w = in.nextInt(), n = in.nextInt();
    fact = new long[h+w+1];
    invfact = new long[h+w+1];
    inv = new long[h+w+1];
    inv[0] = inv[1] = 1;
    for (int i = 2; i < inv.length; i++) {
      inv[i] = (mod - mod/i) * inv[mod % i] % mod;
    }
    fact[0] = 1; invfact[0] = 1;
    for (int i = 1; i < fact.length; i++) {
      fact[i] = fact[i-1] * i % mod;
      invfact[i] = invfact[i-1] * inv[i] % mod;
    }
    Point[] p = new Point[n+1];
    for (int i = 0; i < n; i++) {
      p[i] = new Point(in.nextInt()-1, in.nextInt()-1);
    }
    p[n] = new Point(h-1, w-1);
    Arrays.sort(p);
    
    long[] dp = new long[n+1];
    for (int i = 0; i <= n; i++) {
      dp[i] = comb(p[i].x+p[i].y,p[i].x);
      for (int j = 0; j < i; j++) {
        long cc = comb(p[i].x+p[i].y-p[j].x-p[j].y,p[i].x-p[j].x) * dp[j] % mod;
        dp[i] = (dp[i] + mod - cc) % mod;
      }
    }
    
    out.println(dp[n]);
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