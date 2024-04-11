import java.io.*;
import java.util.*;

public class degenmat {
  private static InputReader in;
  private static PrintWriter out;
  public static double EPS = 1e-6;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    double a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
    double lo = 0, hi = 1000000000;
    for (int iter = 0; iter < 200; iter++) {
      double mid = (lo + hi) / 2.;
      
      double la = a - mid, ua = a + mid;
      double lb = b - mid, ub = b + mid;
      double lc = c - mid, uc = c + mid;
      double ld = d - mid, ud = d + mid;
      
      double[] m1 = get(la, ua, ld, ud);
      double[] m2 = get(lb, ub, lc, uc);
      double l1 = m1[0], u1 = m1[1], l2 = m2[0], u2 = m2[1];
      
      if (l1 > l2) {
        double t;
        t = l1; l1 = l2; l2 = t;
        t = u1; u1 = u2; u2 = t;
      }
      
      if (u1 >= l2) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    
    out.printf("%.15f\n", lo);
    out.close();
    System.exit(0);
  }
  
  public static double[] get(double l1, double u1, double l2, double u2) {
    double a = l1 * l2, b = l1 * u2, c = u1 * l2, d = u1 * u2;
    double lo = Math.min(Math.min(a,b), Math.min(c,d));
    double hi = Math.max(Math.max(a,b), Math.max(c,d));
    return new double[] {lo,hi};
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