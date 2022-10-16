import java.io.*;
import java.util.*;

public class bots {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    long[] fact = new long[2*n+2];
    long[] inv = new long[2*n+2];
    long[] invfact = new long[2*n+2];
    inv[1] = 1;
    for (int i = 2; i <= 2*n+1; i++) {
      inv[i] = (mod - mod/i) * inv[mod % i] % mod;
    }
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= 2*n+1; i++) {
      fact[i] = i * fact[i-1] % mod;
      invfact[i] = inv[i] * invfact[i-1] % mod;
    }
    
    long ans = 0;
    for (int i = 1; i <= n+1; i++) {
      ans = (ans + fact[n+i] * invfact[i] % mod * invfact[n]) % mod;
    }
    out.println(ans);
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