import java.io.*;
import java.util.*;

public class factoryrepairs {
  private static InputReader in;
  private static PrintWriter out;
  public static int n,k,a,b,q;
  
  static class SegmentTree {
    public SegmentTree left,right;
    public int start,end;
    public long suma,sumb;
    public SegmentTree(int start, int end) {
      this.start = start;
      this.end = end;
      if (start == end) {
        suma=sumb=0;
      } else {
        int mid = (start+end)/2;
        left = new SegmentTree(start, mid);
        right = new SegmentTree(mid+1, end);
        suma=sumb=0;
      }
    }
    
    public void update(int pos, int amt) {
      if (pos == start && pos == end) {
        suma = Math.min(a, suma+amt);
        sumb = Math.min(b, sumb+amt);
        return;
      }
      
      int mid = (start+end)>>1;
      if (pos <= mid) left.update(pos, amt);
      else right.update(pos, amt);
      this.suma = left.suma+right.suma;
      this.sumb = left.sumb+right.sumb;
    }
    
    public long query(int s, int e, int type) {
      if (e < s) return 0;
      if (start == s && end == e) {
        return type == 0 ? suma : sumb;
      }
      
      int mid = (start+end)>>1;
      if (mid >= e) return left.query(s,e,type);
      else if (mid < s) return right.query(s,e,type);
      else return left.query(s,mid,type)+right.query(mid+1,e,type);
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    n = in.nextInt();
    k = in.nextInt();
    a = in.nextInt();
    b = in.nextInt();
    q = in.nextInt();
    
    SegmentTree root = new SegmentTree(1,n);
    for (int i = 0; i < q; i++) {
      int type = in.nextInt();
      if (type == 1) {
        int d = in.nextInt(), a = in.nextInt();
        root.update(d,a);
      } else {
        int p = in.nextInt();
        long ans = root.query(1, p-1, 1) + root.query(p+k, n, 0);
        out.println(ans);
      }
    }
    
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