import java.io.*;
import java.util.*;

public class yuradev {
  private static InputReader in;
  private static PrintWriter out;
  
  public static int N, K;
  public static int[] a;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    K = in.nextInt();
    a = new int[N];
    for (int i = 0; i < N; i++) a[i] = in.nextInt();
    out.println(solve(0, N-1));
    out.close();
    System.exit(0);
  }

  public static long solve(int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    long res = solve(l, m) + solve(m+1, r);
    int li = m, ri = m+1;
    int maxl = a[li], suml = a[li]%K, maxr = a[ri], sumr = a[ri]%K;
    Map m1 = new Map(), m2 = new Map();
    while (li >= l || ri <= r) {
      if (ri == r+1 || (li >= l && maxl <= maxr)) {
        m1.put(suml, m1.get(suml) + 1);
        res += m2.get((maxl - suml + K) % K);
        
        li--;
        if (li >= l) {
          maxl = Math.max(maxl, a[li]);
          suml = (suml + a[li]) % K;
        }
      } else {
        res += m1.get((maxr - sumr + K) % K);
        m2.put(sumr, m2.get(sumr) + 1);
        
        ri++;
        if (ri <= r) {
          maxr = Math.max(maxr, a[ri]);
          sumr = (sumr + a[ri]) % K;
        }
      }
    }
    return res;
  }
  
  static class Map extends HashMap<Integer, Integer> {
    public Integer get(Integer key) {
      return this.containsKey(key) ? super.get(key) : 0;
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