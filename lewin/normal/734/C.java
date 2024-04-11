import java.io.*;
import java.util.*;

public class agraph {
  private static InputReader in;
  private static PrintWriter out;
  
  static class Type1 implements Comparable<Type1> {
    public long a,b;
    public Type1(long a, long b) {
      this.a = a;
      this.b = b;
    }
    
    public int compareTo(Type1 other) {
      return Long.compare(b, other.b);
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    long n = in.nextInt();
    int m = in.nextInt(), k = in.nextInt();
    long x = in.nextInt(), s = in.nextInt();
    long[] as = new long[m];
    long[] bs = new long[m];
    for (int i = 0; i < m; i++) as[i] = in.nextInt();
    for (int i = 0; i < m; i++) bs[i] = in.nextInt();
    Type1[] ts = new Type1[m+1];
    for (int i =0 ; i < m; i++) ts[i] = new Type1(as[i], bs[i]);
    ts[m] = new Type1(x, 0);
    Arrays.sort(ts);
    long[] mina = new long[m+1];
    mina[0] = ts[0].a;
    for (int i = 1; i <= m; i++) {
      mina[i] = Math.min(mina[i-1], ts[i].a);
    }
    
    long[] cs = new long[k];
    long[] ds = new long[k];
    for (int i = 0; i < k; i++) cs[i] = in.nextInt();
    for (int i = 0; i < k; i++) ds[i] = in.nextInt();
    
    
    long cans = n*x;
    int cptr = m;
    while (cptr > 0 && ts[cptr].b > s) cptr--;
    cans = Math.min(cans, n*mina[cptr]);
    for (int i = 0; i < k; i++) {
      if (ds[i] > s) break;
      long leftover = s - ds[i];
      while (cptr > 0 && ts[cptr].b > leftover) cptr--;
      long need = Math.max(n-cs[i],0);
      cans = Math.min(cans, need*mina[cptr]);
    }
    
    out.println(cans);
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