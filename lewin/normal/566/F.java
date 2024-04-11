import java.io.*;
import java.util.*;

public class cliquediv {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    int maxt = 1000010;
    int[] max = new int[maxt];
    for (int i = 0; i < n; i++) {
      int a = in.nextInt();
      max[a]++;
      for (int j = a; j < maxt; j += a) {
        max[j] = Math.max(max[j], max[a]);
      }
    }
    int res = 0;
    for (int i = 0; i < maxt; i++)
      res = Math.max(max[i], res);
    
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