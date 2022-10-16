import java.io.*;
import java.util.*;

public class booleanfunc {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;
  public static char[] ch;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    ch = in.next().toCharArray();
    long[] root = parse(0, ch.length-1);
    int mask = 0, eq = 0;
    int n = in.nextInt();
    for (int i = 0; i < n; i++) {
      int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt(), e = in.nextInt();
      int pos = (a << 3) | (b << 2) | (c << 1) | (d << 0);
      mask |= 1 << pos;
      eq |= e << pos;
    }
    long res = 0;
    for (int j = 0; j < 1 << 16; j++) {
      if ((j & mask) == eq) {
        res = (res + root[j]) % mod;
      }
    }
    out.println(res);
    out.close();
    System.exit(0);
  }
  
  public static void t(long[] a, int b, int sgn) {
    if (sgn == 1) {
      for (int j = 0; j < 16; j++) {
        for (int k = 0; k < 1 << 16; k++) {
          if (((k>>j) & 1) == b) {
            a[k] += a[k^(1<<j)];
            if (a[k] >= mod) a[k] -= mod;
          }
        }
      }
    } else {
      for (int j = 0; j < 16; j++) {
        for (int k = 0; k < 1 << 16; k++) {
          if (((k>>j) & 1) == b) {
            a[k] += mod-a[k^(1<<j)];
            if (a[k] >= mod) a[k] -= mod;
          }
        }
      }
    }
  }
  
  public static long[] combine(long[] a, long[] b, int c) {
    t(a, c, 1); t(b, c, 1);
    
    long[] r = new long[1 << 16];
    for (int i = 0; i < 1 << 16; i++)
      r[i] = a[i] * b[i] % mod;
    
    t(r, c, -1);
    return r;
  }
  
  public static long[] parse(int from, int to) {
    long[] ret = new long[1 << 16];
    if (from == to) {
      char c = ch[from];
      if(c == 'A' || c == '?') ret[0b1111111100000000] = 1;
      if(c == 'B' || c == '?') ret[0b1111000011110000] = 1;
      if(c == 'C' || c == '?') ret[0b1100110011001100] = 1;
      if(c == 'D' || c == '?') ret[0b1010101010101010] = 1;
      if(c == 'a' || c == '?') ret[0b0000000011111111] = 1;
      if(c == 'b' || c == '?') ret[0b0000111100001111] = 1;
      if(c == 'c' || c == '?') ret[0b0011001100110011] = 1;
      if(c == 'd' || c == '?') ret[0b0101010101010101] = 1;
      return ret;
    }
    long[] left = null, right = null;
    char op = '?';
    int count = 0;
    for (int i = from; i <= to; i++) {
      if (ch[i] == '(') {
        count++;
      } else if (ch[i] == ')') {
        count--;
      }
      if (count == 0) {
        left = parse(from+1, i-1);
        right = parse(i+3, to-1);
        op = ch[i+1];
        break;
      }
    }
    
    long[] x1 = new long[1<<16];
    long[] x2 = new long[1<<16];
    if (op == '&' || op == '?') x1 = combine(Arrays.copyOf(left, 1 << 16), Arrays.copyOf(right, 1 << 16), 0);
    if (op == '|' || op == '?') x2 = combine(left, right, 1);
    for (int j = 0; j < 1 << 16; j++) {
      ret[j] = x1[j] + x2[j];
      if (ret[j] >= mod) ret[j] -= mod;
    }
    return ret;
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