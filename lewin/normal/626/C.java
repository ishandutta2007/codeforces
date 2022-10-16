import java.io.*;
import java.util.*;

public class blocktowers {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int n = in.nextInt();
    int m = in.nextInt();
    
    long lo = 0, hi = 100000000;
    while(lo<hi) {
      long mid = (lo+hi)/2;
      long num2 = mid/2;
      long num3 = mid/3;
      long numo = mid/6;
      num2 -= numo;
      num3 -= numo;
      if (Math.max(n - num2, 0) + Math.max(m - num3, 0) <= numo) hi = mid;
      else lo = mid+1;
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