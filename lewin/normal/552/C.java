import java.io.*;
import java.util.*;

public class vanyascale {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int w = in.nextInt(), m = in.nextInt();
    int carry = 0;
    while (m > 0) {
      if ((m%w)+carry == w-1 || (m%w)+carry == w) {
        carry = 1;
      } else if ((m%w)+carry == 1 || (m%w)+carry == 0) {
        carry = 0;
      } else {
        out.println("NO");
        out.close();
        System.exit(0);
      }
      m /= w;
    }
    out.println("YES");
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