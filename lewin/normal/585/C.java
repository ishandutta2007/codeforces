import java.io.*;
import java.util.*;

public class alicebobappleorange {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    long x = in.nextLong(), y = in.nextLong();
    
    String s = get(x, y, x < y);
    if (s.equals("-")) out.println("Impossible");
    else out.println(s);
    out.close();
    System.exit(0);
  }
  
  public static String get(long x, long y, boolean a) {
    if (x > y) return get(y, x, a);
    if (x == 1) return (y-1)+""+(a?"B":"A");
    
    long c = y % x;
    if (c == 0) return "-";
    
    String m = get(c, x, !a);
    if (m.equals("-")) return m;
    long w = y / x;
    StringBuilder ret = new StringBuilder();
    ret.append(w);
    ret.append(a?"B":"A");
    ret.append(m);
    return ret.toString();
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
    public long nextLong() {
      return Long.parseLong(next());
    }
  }


}