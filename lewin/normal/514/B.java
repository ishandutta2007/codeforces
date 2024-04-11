import java.io.*;
import java.util.*;

public class hansololaser {
  private static InputReader in;
  private static PrintWriter out;
  
  public static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
  static class Pair {
    public int a,b;
    
    public Pair (int _a, int _b) {
      a = _a;
      b = _b;
      if (a < 0) {
        a = -a;
        b = -b;
      }
      if (a == 0) b = Math.abs(b);
      int g = gcd(a,Math.abs(b));
      if (g != 0) {
        a /= g;
        b /= g;
      }
    }
    
    public int hashCode() {
      return a*100001 + b;
    }
    
    public boolean equals(Object other) {
      if (!(other instanceof Pair)) return false;
      Pair p = (Pair)other;
      return p.a == a && p.b == b;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    int x0 = in.nextInt(), y0 = in.nextInt();
    HashSet<Pair> seen = new HashSet<Pair>();
    for (int i = 0; i < N; i++) {
      int a = in.nextInt()-x0, b = in.nextInt()-y0;
      seen.add(new Pair(a,b));
    }
    out.println(seen.size());
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