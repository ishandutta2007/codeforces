import java.io.*;
import java.util.*;

public class gamerobot {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int n = in.nextInt();
    int k = in.nextInt();
    int[] id = new int[n];
    for (int i = 0; i < n; i++) {
      id[i] = in.nextInt();
    }
    for (int block = 1; block <= n; block++) {
      if (k <= block) {
        out.println(id[k-1]);
        break;
      }
      k -= block;
    }
    

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