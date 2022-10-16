import java.io.*;
import java.util.*;

public class Main {
  private static BufferedReader in;
  private static PrintWriter out;
  
  public static int mod = 1000000007; 
  public static long mod_exp(long b, long e) {
    long r = 1;
    while (e > 0) {
      if ((e & 1) == 1) r = (r * b) % mod;
      b = (b * b) % mod;
      e >>= 1;
    }
    return r;
  }

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out, true);
    String s = in.readLine();
    int T = Integer.parseInt(in.readLine());
    String[][] rules = new String[T + 1][];
    rules[0] = new String[] {"0", s};
    for (int i = 1; i <= T; i++) {
      rules[i] = in.readLine().split("->");
      if (rules[i].length == 1) {
        rules[i] = new String[] {rules[i][0], ""};
      }
    }
    
    long[] len = new long[10];
    long[] val = new long[10];
    for (int i = 0; i < 10; i++) {
      len[i] = 1;
      val[i] = i;
    }
    
    for (int i = T; i >= 0; i--) {
      long[] nlen = new long[10];
      long[] nval = new long[10];
      System.arraycopy (len, 0, nlen, 0, 10);
      System.arraycopy (val, 0, nval, 0, 10);
      int k = Integer.parseInt(rules[i][0]);
      nval[k] = 0;
      nlen[k] = 0;
      char[] x = rules[i][1].toCharArray();
      for (int j = x.length - 1; j >= 0; j--) {
        int m = x[j] - '0';
        nval[k] = (nval[k] + val[m] * mod_exp(10, nlen[k])) % mod;
        nlen[k] = (nlen[k] + len[m]) % (mod - 1);
      }
      len = nlen;
      val = nval;
    }
    
    out.println (val[0]);
    out.close();
    System.exit(0);
  }
}