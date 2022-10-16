import java.io.*;
import java.util.*;

public class jumpball {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    char[] s = in.next().toCharArray();
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '<') {
        cur++;
      } else {
        break;
      }
    }
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == '>') {
        cur++;
      } else {
        break;
      }
    }
    out.println(cur);
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