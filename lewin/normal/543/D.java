import java.io.*;
import java.util.*;

public class roadimprovement {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;
  public static int N;
  public static int[] p, d;
  public static ArrayList<Integer>[] child;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    child = new ArrayList[N];
    p = new int[N];
    d = new int[N];
    for (int i = 0; i < N; i++) {
      child[i] = new ArrayList<>();
    }
    for (int i = 1; i < N; i++) {
      int par = in.nextInt()-1;
      d[i] = child[par].size();
      p[i] = par;
      child[par].add(i);
    }
    
    long[] nways = new long[N];
    for (int i = N-1; i >= 0; i--) {
      nways[i] = 1;
      for (int x : child[i]) {
        nways[i] = (nways[i] * (1 + nways[x])) % mod;
      }
    }
    long[][] prodpref = new long[N][];
    long[][] prodsuff = new long[N][];
    for (int i = 0; i < N; i++) {
      prodpref[i] = new long[child[i].size()];
      prodsuff[i] = new long[child[i].size()];
      for (int j = 0; j < child[i].size(); j++) {
        if (j == 0) prodpref[i][j] = 1 + nways[child[i].get(j)];
        else prodpref[i][j] = (prodpref[i][j-1] * (1 + nways[child[i].get(j)])) % mod;
      }
      for (int j = child[i].size()-1; j >= 0; j--) {
        if (j == child[i].size()-1) prodsuff[i][j] = 1 + nways[child[i].get(j)];
        else prodsuff[i][j] = (prodsuff[i][j+1] * (1 + nways[child[i].get(j)])) % mod;
      }
    }
    
    long[] top = new long[N];
    top[0] = 1;
    for (int i = 1; i < N; i++) {
      top[i] = top[p[i]];
      if (d[i] > 0) top[i] = (top[i] * prodpref[p[i]][d[i]-1]) % mod;
      if (d[i] < child[p[i]].size()-1) top[i] = (top[i] * prodsuff[p[i]][d[i]+1]) % mod;
      top[i] = (top[i] + 1) % mod;
    }
    for (int i = 0; i < N; i++) {
      if (i != 0) out.print(" ");
      out.print(top[i] * nways[i] % mod);
    }
    out.println();
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