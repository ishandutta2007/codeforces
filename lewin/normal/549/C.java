import java.io.*;
import java.util.*;

public class paritygame {
  private static InputReader in;
  private static PrintWriter out;
  public static String EVEN = "Daenerys", ODD = "Stannis";

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int K = in.nextInt();
    int odd = 0, even = 0;
    for (int i = 0; i < N; i++) {
      int a = in.nextInt();
      if (a % 2 == 0) even++;
      else odd++;
    }
    
    int nturns = (N - K);
    int last = (N - K) % 2;
    int st = nturns / 2 + last, dt = nturns / 2;
    
    if (nturns == 0) {
      out.println(odd % 2 == 0 ? EVEN : ODD);
    } else if (last == 0) {
      if (st >= even && K % 2 == 1) out.println(ODD);
      else out.println(EVEN);
    } else {
      if (dt >= odd || (dt >= even && K % 2 == 0)) out.println(EVEN);
      else out.println(ODD);
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