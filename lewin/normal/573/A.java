import java.io.*;
import java.util.*;

public class bearpoker {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    int s = normalize(in.nextInt());
    for (int i = 1; i < n; i++) {
      if (normalize(in.nextInt()) != s) {
        out.println("No");
        out.close();
        System.exit(0);
      }
    }
    out.println("Yes");
    out.close();
    System.exit(0);
  }
  public static int normalize(int a) {
    while (a % 2 == 0) a /= 2;
    while (a % 3 == 0) a /= 3;
    return a;
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