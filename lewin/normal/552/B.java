import java.io.*;
import java.util.*;

public class vanyabooks {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int[] pow = new int[10];
    pow[0] = 1;
    for (int i = 1; i <= 9; i++) pow[i] = pow[i-1]*10;
    long res = 0;
    for (int i = 9; i >= 0; i--) {
      if (N >= pow[i]) {
        res += ((long)(N - pow[i] + 1)) * (i+1);
        N = pow[i]-1;
      }
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