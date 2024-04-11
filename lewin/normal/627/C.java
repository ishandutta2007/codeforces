import java.io.*;
import java.util.*;

public class packagedelivery {
  private static InputReader in;
  private static PrintWriter out;
  
  static class Station implements Comparable<Station>{
    public long pos,cost;
    public Station(long pos, long cost) {
      this.pos = pos;
      this.cost = cost;
    }
    public int compareTo(Station other) {
      return Long.compare(pos,other.pos);
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int d = in.nextInt(), n = in.nextInt(), m = in.nextInt();
    
    Station[] s = new Station[m+2];
    s[0] = new Station(0,0);
    s[1] = new Station(d,0);
    for (int i = 0; i < m; i++) {
      int x = in.nextInt(), p = in.nextInt();
      s[i+2] = new Station(x,p);
    }
    Arrays.sort(s);
    
    if (s[m].pos+n < d) {
      out.println(-1);
      out.close();
      System.exit(0);
    }
    long[] next = new long[m+2];
    TreeSet<Long> xx = new TreeSet<>();
    Station[] ss = new Station[m+2];
    for (int i = 0; i <= m+1; i++) {
      ss[i] = new Station(i, s[i].cost);
    }
    Arrays.sort(ss, new Comparator<Station>() {
      public int compare(Station a, Station b) {
        if (a.cost == b.cost) return Long.compare(b.pos, a.pos);
        return Long.compare(a.cost, b.cost);
      }
    });
    xx.add((long)(m+2));
    for (int i = 0; i <= m+1; i++) {
      next[(int)(ss[i].pos)] = xx.higher(ss[i].pos);
      xx.add(ss[i].pos);
    }
    
    long cfuel = 0;
    long pp = 0;
    long res = 1l << 60;
    long cans = 0;
    for (int i = 0; i <= m; i++) {
      long travel = s[i].pos - pp;
      if (travel > cfuel) {
        out.println(-1);
        out.close();
        System.exit(0);
      }
      cfuel -= travel;
      long dend = d - s[i].pos;
      if (dend <= n) {
        long need = Math.max(0, dend - cfuel);
        res = Math.min(res, cans + need * s[i].cost);
      }
      int nlow = (int)next[i];
      if (s[nlow].pos-s[i].pos > cfuel) {
        long amt = Math.min(n, s[nlow].pos-s[i].pos)-cfuel;
        cans += amt * s[i].cost;
        cfuel += amt;
      }
      pp = s[i].pos;
    }

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