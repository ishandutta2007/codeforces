import java.io.*;
import java.util.*;

public class lizardera {
  private static InputReader in;
  private static PrintWriter out;

  public static int[] l, m, w;
  public static String[] ttt = {"MW", "LW", "LM"};
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    l = new int[n];
    m = new int[n];
    w = new int[n];
    int suml = 0, summ = 0, sumw = 0;
    for (int i = 0; i < n; i++) {
      l[i] = in.nextInt();
      m[i] = in.nextInt();
      w[i] = in.nextInt();
      suml += l[i];
      summ += m[i];
      sumw += w[i];
    }
    int del1 = summ - suml;
    int del2 = sumw - suml;
    
    int h1 = n/2;
    
    HashMap<Long, Long> g1 = new HashMap<>();
    HashMap<Long, Long> g2 = new HashMap<>();
    gen(0, h1, g1, 0, 0, 0, 0);
    gen(h1, n, g2, 0, 0, 0, 0);
    long b1 = 0, b2 = 0;
    long best = 1l << 60;
    for (Long p : g1.keySet()) {
      long a = p/10000000000l, b = p - a * 10000000000l;
      long need = (del1-a)*10000000000l+del2-b;
      Long m = g2.get(need);
      if (m != null) {
        long sum = (g1.get(p) >> 30) + (g2.get(need) >> 30);
        if (sum < best) {
          best = sum;
          b1 = p;
          b2 = need;
        }
      }
    }
    if (best >= 1l << 60) {
      out.println("Impossible");
    } else {
      Long m = g2.get(b2) & ((1l << 30) - 1);
      int[] which = new int[n];
      for (int i = n-1; i >= h1; i--) {
        which[i] = (int)(m % 3);
        m /= 3;
      }
      m = g1.get(b1) & ((1l << 30) - 1);
      for (int i = h1-1; i >= 0; i--) {
        which[i] = (int)(m % 3);
        m /= 3;
      }
      for (int i = 0; i < n; i++) out.println(ttt[which[i]]);
      out.close();
      System.exit(0);
    }
    out.close();
    System.exit(0);
  }
  
  public static void gen(int from, int to, HashMap<Long, Long> g, int choices, int bb, int a1, int a2) {
    if (from == to) {
      long c = (a1-bb)*10000000000l + a2-bb;
      long m = ((long)bb << 30l) | choices;
      Long k = g.get(c);
      if (k == null || m < k) {g.put(c, m);}
      return;
    }
    gen(from+1, to, g, choices*3+0, bb+l[from],a1, a2);
    gen(from+1, to, g, choices*3+1, bb, a1+m[from], a2);
    gen(from+1, to, g, choices*3+2, bb, a1, a2+w[from]);
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