import java.io.*;
import java.util.*;

public class antman {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt(), s = in.nextInt()-1, e = in.nextInt()-1;
    long[][] dp = new long[2][n+1];
    long[] x = new long[n];
    for (int i = 0; i < n; i++) {
      x[i] = in.nextInt();
    }
    long[] a = new long[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    long[] b = new long[n];
    for (int i = 0; i < n; i++) {
      b[i] = in.nextInt();
    }
    long[] c = new long[n];
    for (int i = 0; i < n; i++) {
      c[i] = in.nextInt();
    }
    long[] d = new long[n];
    for (int i = 0; i < n; i++) {
      d[i] = in.nextInt();
    }
    
    long sub = 0;
    if (s < e) {
      sub = x[e] - x[s] + c[e] + b[s];
    } else {
      sub = x[s] - x[e] + d[e] + a[s];
    }
    
    Arrays.fill(dp[0], 1L << 50);
    dp[0][0] = 0;
    boolean set = false;
    boolean active = false;
    boolean dir = false;
    int cur = 1;
    for (int i = 0; i < n; i++) {
      Arrays.fill(dp[cur], 1L << 50);
      if (active) {
        set = true;
        if (i == s || i == e) active = false;
      }
      for (int arrive = 0; arrive <= 1; arrive++) {
        for (int leave = 0; leave <= 1; leave++) {
          if (i == s && (s < e == (arrive == 0))) continue;
          if (i == e && (s < e == (leave == 1))) continue;
          int netchange = 0;
          if (arrive == 0 && leave == 0) netchange = -1;
          else if (arrive == 1 && leave == 1) netchange = +1;
          dir = arrive == 0 && leave == 1;

          long cost = 0;
          if (leave == 0) cost += +x[i] + c[i];
          else cost += -x[i] + d[i];
          if (arrive == 0) cost += +x[i] + a[i];
          else cost += -x[i] + b[i];

          for (int balance = 0; balance <= n; balance++) {
            int nbalance = balance+netchange;
            if (balance == 0 && netchange == 0) continue;
            if (active && balance == 1 && netchange == 0 && (dir == (e < s))) continue;
            if (nbalance >= 0 && nbalance <= n)
              dp[cur][nbalance] = Math.min(dp[cur][nbalance], dp[1-cur][balance]+cost);
          }
        }
      }
      if (!set && !active) {
        if (i == s || i == e) active = true;
      }
      if (i != n-1) dp[cur][0] = 1L << 50;
      cur = 1-cur;
    }
    out.println(dp[1-cur][0] - sub);
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