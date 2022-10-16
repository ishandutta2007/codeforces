import java.io.*;
import java.util.*;

public class touristnote {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int M = in.nextInt();
    int[] x = new int[M];
    int[] t = new int[M];
    for (int i = 0; i < M; i++) {
      x[i] = in.nextInt();
      t[i] = in.nextInt();
    }
    for (int i = 0; i < M-1; i++) {
      if (Math.abs(t[i+1] - t[i]) > x[i+1] - x[i]) {
        out.println("IMPOSSIBLE");
        out.close();
        System.exit(0);
      }
    }
    
    out.println(maxHeight(N, 1, x, t));
    out.close();
    System.exit(0);
  }
  
  public static long maxHeight(int N, int K, int[] x, int[] t) {
    int M = x.length;
    long[] pos = new long[M];
    long[] maxHeight = new long[M];
    for (int i = 0; i < M; i++) {
      pos[i] = x[i];
      maxHeight[i] = t[i];
    }
    
    long res = Math.max(maxHeight[0] + pos[0]-1, maxHeight[M-1] + (long)(N-pos[M-1]) * (long)K);
    for (int i = 0; i < M-1; i++) {
      res = Math.max(res, getBetween(maxHeight[i], maxHeight[i+1], pos[i], pos[i+1], K));
    }
    return res;
  }
  
  public static long getBetween(long h1, long h2, long p1, long p2, long K) {
    if (h1<h2) {long t = h1; h1 = h2; h2 = t;}
    long s = p2-p1-1;
    long lo = 0, hi = s;
    while (hi-lo > 10) {
      long mid = (lo+hi)>>1;
      long f = h1+mid*K - (h2+(s-mid)*K);
      if (f < -K) lo = mid+1;
      else hi = mid;
    }
    
    long ret = 0;
    for (long a = lo; a <= hi; a++) {
      long m1 = h1+a*K, m2 = h2+(s-a)*K;
      if (Math.abs(m1-m2) > K) continue;
      ret = Math.max(ret, Math.max(m1,m2));
    }
    return ret;
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