import java.io.*;
import java.util.*;

public class infseq {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    long a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
    if (a == b) out.println("YES");
    else if (c == 0) out.println(a==b?"YES":"NO");
    else out.println(((b-a>0)==(c>0)) && Math.abs(b-a)%Math.abs(c)==0?"YES":"NO");
    
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