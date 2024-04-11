import java.io.*;
import java.util.*;

public class childtoy {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    int M = in.nextInt();
    int[] f = new int[N];
    for (int i = 0; i < N; i++) {
      f[i] = in.nextInt();
    }
    
    long sum = 0;
    for (int i = 0; i < M; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      sum += Math.min(f[a], f[b]);
    }
    out.println(sum);
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