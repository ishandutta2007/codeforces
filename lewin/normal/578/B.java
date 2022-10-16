import java.io.*;
import java.util.*;

public class orgame {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt(), k = in.nextInt(), x = in.nextInt();
    long[] arr = new long[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    long mult = 1;
    while (k-- > 0) mult *= x;
    long[] suff = new long[n], pref = new long[n];
    pref[0] = arr[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i-1] | arr[i];
    suff[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--) suff[i] = suff[i+1] | arr[i];
    long ret = 0;
    for (int i = 0; i < n; i++) {
      long m = (arr[i] * mult) | (i == 0 ? 0 : pref[i-1]) | (i == n-1 ? 0 : suff[i+1]);
      ret = Math.max(m, ret);
    }
    
    out.println(ret);
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