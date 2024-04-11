import java.io.*;
import java.util.*;

public class kingtheives {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    char[] c = in.next().toCharArray();
    for (int step = 1; step <= N; step++) {
      for (int start = 0; start + step*4 < N; start++) {
        if (c[start] == '*' && c[start+step] == '*' && c[start+2*step] == '*' && c[start+3*step] == '*'
            && c[start+4*step] == '*') {
          out.println("yes");
          out.close();
          System.exit(0);
        }
      }
    }
    out.println("no");
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