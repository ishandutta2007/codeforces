import java.io.*;
import java.util.*;

public class wattomech {
  private static InputReader in;
  private static PrintWriter out;
  
  public static long mod1 = 1000000007, mod2 = 500000003;
  public static long pow3[][];
  static class HashedString {
    public long hc1, hc2;
    public HashedString(String k) {
      hc1 = 0;
      hc2 = 0;
      for (char c : k.toCharArray()) {
        int id = c - 'a';
        hc1 = (3 * hc1 + id) % mod1;
        hc2 = (3 * hc2 + id) % mod2;
      }
    }
    
    public HashedString(long hc1, long hc2) {
      this.hc1 = hc1;
      this.hc2 = hc2;
    }
    
    @Override
    public int hashCode() {
      return new Long(hc1 * 3210121 + hc2).hashCode();
    }
    
    @Override
    public boolean equals (Object other) {
      if (!(other instanceof HashedString)) return false;
      HashedString hs = (HashedString)other;
      return hs.hc1 == hc1 && hs.hc2 == hc2;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt();
    pow3 = new long[2][1000000];
    pow3[0][0] = 1; pow3[1][0] = 1;
    for (int i = 1; i < pow3[0].length; i++) {
      pow3[0][i] = (pow3[0][i-1] * 3) % mod1;
      pow3[1][i] = (pow3[1][i-1] * 3) % mod2;
    }
    
    
    HashSet<HashedString>[] hs = new HashSet[10000000];
    for (int i = 0; i < N; i++) {
      String m = in.next();
      int len = m.length();
      if (hs[len] == null) hs[len] = new HashSet<HashedString>();
      hs[len].add(new HashedString(m));
    }
    
    StringBuilder bf = new StringBuilder();
    for (int i = 0; i < M; i++) {
      String m = in.next();
      int len = m.length();
      if (hs[len] == null) {
        bf.append("NO\n");
        continue;
      }
      
      HashedString q = new HashedString(m);
      boolean found = false;
      outer : for (int j = 0; j < m.length(); j++) {
        int oval = m.charAt(j)-'a';
        int idx = m.length()-j-1;
        for (int k = 0; k < 3; k++) {
          if (oval == k) continue;
          long hc1 = (q.hc1 - (oval * pow3[0][idx]) % mod1 + (k * pow3[0][idx]) % mod1 + mod1) % mod1;
          long hc2 = (q.hc2 - (oval * pow3[1][idx]) % mod2 + (k * pow3[1][idx]) % mod2 + mod2) % mod2;
          if (hs[len].contains(new HashedString(hc1,hc2))) {
            found = true;
            break outer;
          }
        }
      }
      if (found) bf.append("YES\n"); else bf.append("NO\n");
    }
    
    out.print(bf);
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