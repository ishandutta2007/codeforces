import java.io.*;
import java.util.*;

public class banner {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    String s = in.next();
    String t = "CODEFORCES";
    if (s.length() < t.length()) {
      out.println("NO");
      out.close();
      System.exit(0);
    }
    for (int i = 0; i <= t.length(); i++) {
      if (s.startsWith(t.substring(0, i)) && s.endsWith(t.substring(i))) {
        out.println("YES");
        out.close();
        System.exit(0);
      }
    }
    out.println("NO");
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