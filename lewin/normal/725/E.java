import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class TooMuchMoney {
  private static InputReader in;
  private static PrintWriter out;
  public static int[] freq = new int[2000010];
  public static TreeSet<Integer> ts = new TreeSet<>();
  public static void add(int num) {
    if (++freq[num] == 1) {
      ts.add(num);
    }
  }
  public static void rem(int num) {
    if (--freq[num] == 0) {
      ts.remove(num);
    }
  }

  public static boolean ok(int c) {
    int lasttake = c;
    while (c > 0) {
      Integer x = ts.floor(Math.min(lasttake-1,c));
      if (x == null) return false;
      c = Math.max(c - x * freq[x], c % x);
      lasttake = x;
    }
    return true;
  }
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int c = in.nextInt();
    int n = in.nextInt();
    int[] ww = new int[n];
    for (int i = 0; i < n; i++) {
      ww[i] = in.nextInt();
      int j = (int)(Math.random()*(i+1));
      if (j != i) {
        int t = ww[i];
        ww[i] = ww[j];
        ww[j] = t;
      }
    }
    Arrays.sort(ww);
    long rr = 0;
    boolean qq = true;
    for (int i = 0; i < n; i++) {
      if (qq && ww[i] <= rr+1) {
        rr += ww[i];
      } else {
        qq = false;
      }
      add(ww[i]);
    }
    if (c - ww[n-1] <= rr) {
      out.println("Greed is good");
    } else {
      int ans = 0;
      for (int add = 1; add <= c; add++) {
        add(add);
        if (!ok(c)) {
          ans = add;
          break;
        }
        rem(add);
      }
      out.println(ans==0?"Greed is good":ans);
    }
    out.close();
    System.exit(0);
  }
  
  public static int[] t;
  public static void set(int i, int value) {
    for (; i < t.length; i |= i + 1)
      t[i] = Math.min(t[i], value);
  }

  public static int min(int i) {
    int res = 1 << 30;
    for (; i >= 0; i = (i & (i + 1)) - 1)
      res = Math.min(res, t[i]);
    return res;
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