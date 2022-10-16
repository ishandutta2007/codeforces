import java.io.*;
import java.util.*;

public class exam {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    if (N <= 2) {
      out.println("1\n1");
      out.close();
      System.exit(0);
    }
    if (N == 3) {
      out.println("2\n1 3");
      out.close();
      System.exit(0);
    }
    out.println(N);
    out.print(2);
    for (int i = 4; i <= N; i+=2)out.print(" "+i);
    for (int i = 1; i <= N; i+=2)out.print(" "+i);
    out.println();
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