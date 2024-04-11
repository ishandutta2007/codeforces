import java.io.*;
import java.util.*;

public class polycarpusdice {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    long A = Long.parseLong(in.next());
    int[] d = new int[N];
    long s = 0;
    for (int i = 0; i < N; i++) {
      d[i] = in.nextInt();
      s += d[i];
    }
    
    for (int i = 0; i < N; i++) {
      if (i > 0) out.print(" ");
      long min = Math.max(1, A - (s - d[i]));
      long max = Math.min(d[i], A - (N - 1));
      out.print(d[i] - (max - min + 1));
    }
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