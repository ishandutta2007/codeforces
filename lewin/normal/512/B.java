import java.io.*;
import java.util.*;

public class foxjump {
  private static InputReader in;
  private static PrintWriter out;
  public static int N, L[], C[];

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    N = in.nextInt();
    L = new int[N];
    C = new int[N];
    int q = 0;
    for (int i = 0; i < N; i++) { L[i] = in.nextInt(); q = gcd(q, L[i]); }
    for (int i = 0; i < N; i++) C[i] = in.nextInt();
    if (q != 1) {
      out.println(-1);
    } else {
      dp = new HashMap<State, Integer>();
      out.println(dfs(0, 0));
    }
    out.close();
    System.exit(0);
  }
  
  public static int gcd(int a, int b) {return b == 0 ? a : gcd(b,a%b);}
  
  public static HashMap<State, Integer> dp;
  public static int dfs(int idx, int g) {
    if (g == 1) return 0;
    if (idx == N) return 1 << 29;
    State s = new State(idx,g);
    if (dp.containsKey(s)) return dp.get(s);
    int res = 1 << 29;
    // include
    res = Math.min(res, C[idx] + dfs(idx+1, gcd(g, L[idx])));
    // not include
    res = Math.min(res, dfs(idx+1, g));
    dp.put(s, res);
    return res;
  }
  
  static class State {
    public int a,b;
    public State(int a, int b) {
      this.a = a;
      this.b = b;
    }
    
    public int hashCode() {
      return a*102931+b;
    }
    public boolean equals(Object other) {
      if (!(other instanceof State)) return false;
      State s = (State)other;
      return a == s.a && b == s.b;
    }
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