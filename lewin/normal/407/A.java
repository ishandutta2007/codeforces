import java.io.*;
import java.util.*;

public class triangle {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int A = in.nextInt(), B = in.nextInt();
    for (int i = 1; i < A; i++) {
      int k = (int)Math.sqrt(A*A - i*i);
      if (k*k + i*i != A*A) continue;
      for (int j = 1; j < B; j++) {
        int m = (int)Math.sqrt(B*B - j*j);
        if (m*m + j*j != B*B) continue;
        
        if (i * j == k * m && i != j) {
          out.println("YES");
          out.println("0 0");
          out.println(i+" "+k);
          out.println(j+" "+(-m));
          out.close();
          System.exit(0);
        }
      }
    }
    out.println("NO");
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