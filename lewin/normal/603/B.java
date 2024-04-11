import java.io.*;
import java.util.*;

public class modarith {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    long p = in.nextInt(), k = in.nextInt();
    if (k == 1) {
      long res = 1;
      for(int j = 0; j < p; j++) res = (res * p) % mod;
      out.println(res);
      out.close();
      System.exit(0);
    }
    int cyclen = 0;
    long cur = k;
    do {
      ++cyclen;
      cur = (cur * k) % p;
    } while (cur != k);
    if ((p-1) % cyclen != 0) {
      out.println("AHGIHAG");
      System.exit(1);
    }
    long left = (p-1)/cyclen;
    long res = 1;
    while (left-->0) res = (res * p) % mod;
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