import java.io.*;
import java.util.*;

public class awoeid {
  private static InputReader in;
  private static PrintWriter out;
  static class SegmentTree {
    public SegmentTree left,right;
    public int start,end,sum;
    public boolean zero;
    public SegmentTree(int start, int end) {
      this.start = start;
      this.end = end;
      zero = false;
      if (start != end) {
        int mid = (start+end)/2;
        left = new SegmentTree(start,mid);
        right = new SegmentTree(mid+1,end);
        this.sum = left.sum+right.sum;
      } else {
        this.sum = 1;
      }
    }
    
    public int query(int from, int to) {
      if (this.start == from && this.end == to) {
        return this.sum;
      }
      if (zero) return 0;
      int mid = (this.start+this.end)/2;
      if (mid >= to) return left.query(from,to);
      else if (mid < from) return right.query(from,to);
      else return left.query(from,mid)+right.query(mid+1,to);
    }
    
    public void set(int from, int to) {
      if (this.start == from && this.end == to) {
        this.zero = true;
        this.sum = 0;
        return;
      }
      int mid = (this.start+this.end)/2;
      if (mid >= to) left.set(from,to);
      else if (mid < from) right.set(from,to);
      else {
        left.set(from,mid);
        right.set(mid+1,to);
      }
      this.sum = left.sum+right.sum;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int n = in.nextInt(), q = in.nextInt();
    ArrayList<Integer>[] gg = new ArrayList[n];
    for (int i = 0; i < n; i++) gg[i] = new ArrayList<>();
    SegmentTree root = new SegmentTree(0,q+1);
    int idx = 0;
    int start = -1;
    while(q-->0) {
      int type = in.nextInt();
      int m = in.nextInt();
      switch(type) {
        case 1:
          gg[m-1].add(idx++);
          break;
        case 2:
          for (int r : gg[m-1]) {
            root.set(r,r);
          }
          gg[m-1].clear();
          break;
        case 3:
          start = Math.max(m-1, start);
          break;
      }
      out.println(start+1 > idx-1 ? 0 : root.query(start+1,idx-1));
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