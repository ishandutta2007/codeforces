import java.io.*;
import java.util.*;

public class candies {
  private static InputReader in;
  private static PrintWriter out;
  public static long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
  
  public static long lcm(long a, long b) {
    return a / gcd(a,b) * b;
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    long C = in.nextInt();
    long Wr = in.nextInt();
    long Wb = in.nextInt();
    long Hr = in.nextInt();
    long Hb = in.nextInt();
    if (Hr < Hb) {
      long t = Hr; Hr = Hb; Hb = t;
      t = Wr; Wr = Wb; Wb = t;
    }

    long h = lcm(Hr, Hb);
    long left = C % h;
    long times = C / h;
    if (times > 0) {
      times--;
      left += h;
    }
    long res = times * Math.max(h / Hr * Wr, h / Hb * Wb);
    long add = 0;
    for (long i = 0; i * Hr <= left; i++) {
      long rem = left - i * Hr;
      add = Math.max(add, i * Wr + rem / Hb * Wb);
    }
    
    out.println(res+add);
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