import java.io.*;
import java.util.*;

public class restoringpainting {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
    long res = 0;
    for (int i = 1; i <= n; i++) {
      int s1 = a+b+i;
      int s2 = s1-a-c;
      int s3 = s1-b-d;
      int s4 = s1-c-d;
      if (s2 <= 0 || s2 > n || s3 <= 0 || s3 > n || s4 <= 0 || s4 > n) continue;
      res += n;
    }
    out.println(res);
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