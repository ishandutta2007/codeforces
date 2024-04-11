import java.io.*;
import java.util.*;

public class dzyphysics {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    int M = in.nextInt();
    int[] values = new int[N];
    for (int i = 0; i < N; i++) {
      values[i] = in.nextInt();
    }
    double best = 0;
    for (int i = 0; i < M; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1, c = in.nextInt();
      best = Math.max(best, (values[a]+values[b])/(double)c);
    }
    out.printf("%.15f\n", best);
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