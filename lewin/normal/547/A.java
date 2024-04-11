import java.io.*;
import java.util.*;

public class mikefrog {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int M = in.nextInt();
    long h1 = in.nextInt(), a1 = in.nextInt();
    long x1 = in.nextInt(), y1 = in.nextInt();
    long h2 = in.nextInt(), a2 = in.nextInt();
    long x2 = in.nextInt(), y2 = in.nextInt();
    
    for (int i = 0; i < 10*M; i++) {
      if (h1 == a1 && h2 == a2) {
        out.println(i);
        out.close();
        System.exit(0);
      }
      
      h1 = (h1 * x1 + y1) % M;
      h2 = (h2 * x2 + y2) % M;
    }
    
    long c1 = -1, c2 = -1;
    long m1 = -1, m2 = -1;
    long oh1 = h1, oh2 = h2;
    if (h1 == a1) c1 = 0;
    if (h2 == a2) c2 = 0;
    
    for (int i = 1; i <= M; i++) {
      h1 = (h1 * x1 + y1) % M;
      if (c1 == -1 && h1 == a1) c1 = i;
      if (m1 == -1 && h1 == oh1) m1 = i;

      h2 = (h2 * x2 + y2) % M;
      if (c2 == -1 && h2 == a2) c2 = i;
      if (m2 == -1 && h2 == oh2) m2 = i;
    }
    
    if (c1 == -1 || c2 == -1 || m1 == -1 || m2 == -1) {
      out.println(-1);
      out.close();
      System.exit(0);
    }
    
    for (int i = 0; i < m1; i++) {
      if ((c2 + i * m2) % m1 == c1) {
        out.println(c2+i*m2+10*M);
        out.close();
        System.exit(0);
      }
    }
    
    out.println(-1);
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