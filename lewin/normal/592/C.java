import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class bigrace {
  private static InputReader in;
  private static PrintWriter out;
  public static long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    long t = in.nextLong();
    long w = in.nextLong();
    long b = in.nextLong();
    if (w > b) {long m = w; w = b; b = m;}
    long g = gcd(w,b);
    BigInteger bt = new BigInteger(""+t);
    BigInteger bw = new BigInteger(""+w);
    BigInteger bb = new BigInteger(""+b);
    BigInteger bg = bw.gcd(bb);
    BigInteger x = bw.multiply(bb).divide(bg);
    BigInteger div = bt.divide(x);
    BigInteger times = div.multiply(bw);
    BigInteger a2 = x.multiply(div).add(bw).subtract(BigInteger.ONE);
    BigInteger l = a2.compareTo(bt) < 0 ? a2 : bt;
    times = times.add(l.subtract(x.multiply(div)));
    BigInteger gg = bt.gcd(times);
    
    out.printf("%s/%s\n", times.divide(gg), bt.divide(gg));
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
    
    public long nextLong() {
      return Long.parseLong(next());
    }
  }


}