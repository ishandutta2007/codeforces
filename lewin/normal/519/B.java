import java.io.*;
import java.util.*;

public class abcomp {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    long sum = 0;
    for (int i = 0; i < N; i++)
      sum += in.nextInt();
    long s2 = 0;
    for (int i = 0; i < N-1; i++)
      s2 += in.nextInt();
    long s3 = 0;
    for (int i = 0; i < N-2; i++)
      s3 += in.nextInt();
    out.printf("%d\n%d\n", sum-s2, s2-s3);
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