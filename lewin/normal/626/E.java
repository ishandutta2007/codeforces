import java.io.*;
import java.util.*;

public class simpleskewness {
  private static InputReader in;
  private static PrintWriter out;
  public static int n;
  public static long[] x, xs;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    n = in.nextInt();
    
    x = new long[n+1];
    for (int i = 1; i <= n; i++) x[i] = in.nextInt();
    Arrays.sort(x);
    
    xs = new long[n+1];
    for (int i = 1; i <= n; i++) {
      xs[i] = xs[i-1] + x[i];
    }
    long best = 0;
    int bpos = 1;
    long blen = 1;
    for (int median = 1; median <= n; median++) {
      int lo = 0, hi = Math.min(median-1, n-median);
      while (hi - lo > 10) {
        int m1 = (2 * lo + hi) / 3, m2 = (lo + 2 * hi) / 3;
        long f1 = eval(median, m1), f2 = eval(median, m2);
        if (f1 * (2 * m2 + 1) > f2 * (2 * m1 + 1)) hi = m2;
        else lo = m1;
      }
      for (int w = lo; w <= hi; w++) {
        long curs = x[median] + (xs[median-1] - xs[median-w-1]) + (xs[n] - xs[n-w]);
        long clen = 1+2*w;
        
        if ((curs - x[median] * clen) * blen > best * clen) {
          best = curs - x[median] * clen;
          blen = clen;
          bpos = median;
        }
      }
    }
    
    out.println(blen);
    long ext = (blen-1)/2;
    for (int i = bpos; i >= bpos - ext; i--) {
      out.print(x[i]+" ");
    }
    for (int i = n; i >= n-ext+1; i--) {
      out.print(x[i]+" ");
    }
    out.println();
    out.close();
    System.exit(0);
  }
  
  public static long eval(int med, int length) {
    return x[med] + (xs[med-1] - xs[med-length-1]) + (xs[n] - xs[n-length]);
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