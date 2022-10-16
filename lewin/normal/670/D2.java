import java.io.*;
import java.util.*;

public class magicpowder {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    long k = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int[] b = new int[n];
    for (int i = 0; i < n; i++) {
      b[i] = in.nextInt();
    }
    
    long lo = 0, hi = 10000000000L;
    while (lo < hi) {
      long mid = (lo+hi+1)>>1;
      long need = 0;
      for (int i = 0; i < n; i++) {
        need += Math.max(0, mid * (long)a[i] - b[i]);
        if (need > k) break;
      }
      if (need > k) hi = mid-1;
      else lo = mid;
    }
    out.println(lo);
    
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