import java.io.*;
import java.util.*;

public class drazilpark {
  private static InputReader in;
  private static PrintWriter out;
  public static int N,M;
  public static long[] d,h,pd;
  public static long[][] stepLeft, stepRight;
  public static long[] ml, mr;
  public static int LOGN = 18;
  
  public static long sumD(int from, int to) {
    if (from == to) return 0;
    else if (from > to) return sumD(from,N-1) + sumD(0, to) + d[N-1];
    else if (from == 0) return pd[to-1];
    else return pd[to-1] - pd[from-1];
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    M = in.nextInt();
    d = new long[N];
    h = new long[N];
    pd = new long[N];
    for (int i = 0; i < N; i++) d[i] = in.nextInt();
    pd[0] = d[0];
    for (int i = 1; i < N; i++) pd[i] = pd[i-1] + d[i];
    for (int i = 0; i < N; i++) h[i] = 2l * (long)in.nextInt();
    stepLeft = new long[LOGN][N];
    stepRight = new long[LOGN][N];
    for (int i = 0; i < N; i++) {
      stepLeft[0][i] = Math.max(h[i], i==0?(d[N-1]+h[N-1]):(d[i-1]+h[i-1]));
      stepRight[0][i] = Math.max(h[i],d[i]+(i==N-1?h[0]:h[i+1]));
    }
    int step = 1;
    for (int k = 1; k < LOGN; k++) {
      for (int i = 0; i < N; i++) {
        int ofr = (i + step) % N;
        stepRight[k][i] = Math.max(stepRight[k-1][i], sumD(i,ofr) + stepRight[k-1][ofr]);
        int ofl = (i + N - step) % N;
        stepLeft[k][i] = Math.max(stepLeft[k-1][i], sumD(ofl,i) + stepLeft[k-1][ofl]);
      }
      step = (step * 2) % N;
    }
    
    mr = new long[N];
    mr[0] = h[0];
    for (int i = 1; i < N; i++) {
      mr[i] = Math.max(mr[i-1], sumD(0,i) + h[i]); 
    }
    ml = new long[N];
    ml[N-1] = h[N-1];
    for (int i = N-2; i >= 0; i--) {
      ml[i] = Math.max(ml[i+1], sumD(i,N-1) + h[i]);
    }
    
    root = new SegmentTree(0, N-1);
    while (M-- > 0) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      out.println(solve((b+1)%N,(a+N-1)%N));
    }
    out.close();
    System.exit(0);
  }
  public static SegmentTree root;
  
  public static long solveBrute(int from, int to) {
    if (from > to) {
      long ret = Math.max(solveBrute(from,N-1), solveBrute(0, to));
      for (int i = from; i <= N-1; i++) for (int j = 0; j <= to; j++)
        ret = Math.max(sumD(i,j) + h[i] + h[j], ret);
      return ret;
    }
    
    long ret = 0;
    for (int i = from; i <= to; i++)
      for (int j = i+1; j <= to; j++)
        ret = Math.max(ret, sumD(i,j) + h[i] + h[j]);
    return ret;
  }
  
  public static long solve(int from, int to) {
    if (from > to) {
      long ret = Math.max(solve(from,N-1), solve(0, to));
      return Math.max(ret, ml[from] + mr[to] + d[N-1]);
    }
    
    return root.query(from,to);
  }
  
  static class SegmentTree {
    public SegmentTree left, right;
    public int start, end;
    public long val;
    
    public SegmentTree(int start, int end) {
      this.start = start;
      this.end = end;
      if (start != end) {
        int mid = (start + end) >> 1;
        left = new SegmentTree(start, mid);
        right = new SegmentTree(mid+1, end);
        val = Math.max(left.val, right.val);
        val = Math.max(val, combine(start, end));
      }
    }
    
    public long combine(int from, int to) {
      int mid = (start + end) >> 1;
      long sumr = 0, suml = 0;
      int cur = mid;
      long as = 0;
      for (int k = LOGN-1; k >= 0; k--) {
        if (cur - (1<<k) > from) {
          suml = Math.max(stepLeft[k][cur] + as, suml);
          as += sumD(cur-(1<<k), cur);
          cur -= 1<<k;
        }
      }
      if (cur > from) suml = Math.max(stepLeft[0][cur] + as, suml);
      if (cur == from) suml = h[cur];
      cur = mid+1;
      as = 0;
      for (int k = LOGN-1; k >= 0; k--) {
        if (cur + (1<<k) < to) {
          sumr = Math.max(stepRight[k][cur] + as, sumr);
          as += sumD(cur, cur+(1<<k));
          cur += 1<<k;
        }
      }
      if (cur < to) sumr = Math.max(stepRight[0][cur] + as, sumr);
      if (cur == to) sumr = h[cur];
      return suml+sumr+d[mid];
    }
    
    public long query(int s, int e) {
      if (start == s && end == e) return val;
      int mid = (start + end) >> 1;
      if (mid >= e) return left.query(s, e);
      else if (mid < s) return right.query(s, e);
      else {
        long ret = Math.max(left.query(s,mid), right.query(mid+1,e));
        return Math.max(ret, combine(s,e));
      }
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