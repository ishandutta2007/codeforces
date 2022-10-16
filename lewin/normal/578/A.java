import java.io.*;
import java.util.*;

public class polyline {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    long a = in.nextInt(), b = in.nextInt();
    if (a < b) {
      out.println(-1);
    } else if (a == b) {
      out.printf("%.10f\n", (double)a);
    } else {
      double min = 1l << 60;
      {
        long lo = 0, hi = a;
        while (lo < hi) {
          long mid = (lo + hi + 1) / 2;
          if ((a - b) >= mid * b) lo = mid;
          else hi = mid-1;
        }
        if (lo % 2 == 1) lo--;
        if (lo != 0) min = (a - b) / (double)lo;
      }
      {
        long lo = 0, hi = a;
        while (lo < hi) {
          long mid = (lo + hi + 1) / 2;
          if ((a + b) >= mid * b) lo = mid;
          else hi = mid-1;
        }
        if (lo % 2 == 1) lo--;
        if (lo > 0) min = Math.min(min, (a + b) / (double)lo);
      }
      
      out.printf("%.10f\n", min);
    }
    
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