import java.io.*;
import java.util.*;

public class treelandtour {
  private static Reader in;
  private static PrintWriter out;
  public static int[] eadj, eprev, elast;
  public static int eidx;
  
  public static int[] cost, pop;
  
  public static void addEdge(int a, int b) {
    eadj[eidx] = b; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }
  
  static class Node implements Comparable<Node> {
    public int a, b;
    public Node(int a, int b) {
      this.a = a;
      this.b = b;
    }
    public int compareTo(Node other) {
      return b - other.b;
    }
  }
  
  public static int[] start, end, which, depth;
  public static int[][] anc;
  public static int counter;
  public static void dfs(int node, int par) {
    anc[0][node] = par;
    start[node] = counter;
    depth[node] = par==-1?0:(depth[par]+1);
    which[counter++] = node;
    for (int e = elast[node]; e != -1; e = eprev[e]) {
      if (eadj[e] == par) continue;
      dfs(eadj[e], node);
    }
    end[node] = counter;
  }
  
  static class SegmentTree {
    public SegmentTree left, right;
    public int start, end, max;
    public SegmentTree(int start, int end) {
      this.start = start;
      this.end = end;
      
      if (start != end) {
        int mid = (start+end)/2;
        left = new SegmentTree(start, mid);
        right = new SegmentTree(mid+1, end);
      }
      max = 0;
    }
    public void update(int pos, int v) {
      if (start == pos && end == pos) {
        this.max = v;
        return;
      }
      int mid = (start+end)/2;
      if (mid >= pos) left.update(pos, v);
      else right.update(pos, v);
      max = Math.max(left.max, right.max);
    }
    
    public int query (int s, int e) {
      if (start == s && end == e) return max;
      int mid = (start+end)/2;
      if (mid >= e) return left.query(s, e);
      else if (mid < s) return right.query(s, e);
      else return Math.max(left.query(s,mid), right.query(mid+1,e));
    }
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    Node[] nodes = new Node[N];
    pop = new int[N];
    for (int i = 0; i < N; i++) {
      pop[i] = in.nextInt();
      nodes[i] = new Node(i, pop[i]);
    }
    
    eadj = new int[2*N];
    eprev = new int[2*N];
    elast = new int[N];
    eidx = 0;
    Arrays.fill(elast, -1);
    for (int i = 0; i < N-1; i++) {
      addEdge(in.nextInt()-1, in.nextInt()-1);
    }
    
    start = new int[N];
    end = new int[N];
    which = new int[N];
    depth = new int[N];
    counter = 0;
    anc = new int[15][N];
    dfs(0, -1);
    for (int i = 1; i < 15; i++) {
      for (int j = 0; j < N; j++) {
        anc[i][j] = anc[i - 1][j] == -1 ? -1 : anc[i - 1][anc[i - 1][j]];
      }
    }
    
    Arrays.sort(nodes);
    SegmentTree ic = new SegmentTree(0, N-1);
    int[] inc = new int[N];
    ArrayList<Pair> add = new ArrayList<Pair>();
    int prev = -1;
    for (int i = 0; i < N; i++) {
      int node = nodes[i].a;
      if (pop[node] != prev) {
        for (Pair p : add) ic.update(p.a, p.b);
        add = new ArrayList<Pair>();
      }
      prev = pop[node];
      inc[node] = ic.query(start[node], end[node]-1)+1;
      add.add(new Pair(start[node], inc[node]));
    }
    for (Pair p : add) ic.update(p.a, p.b);
    add = new ArrayList<Pair>();
    
    int[] dec = new int[N];
    SegmentTree dc = new SegmentTree(0, N-1);
    for (int i = N-1; i >= 0; i--) {
      int node = nodes[i].a;
      if (pop[node] != prev) {
        for (Pair p : add) dc.update(p.a, p.b);
        add = new ArrayList<Pair>();
      }
      prev = pop[node];
      dec[node] = dc.query(start[node], end[node]-1)+1;
      add.add(new Pair(start[node], dec[node]));
    }
    for (Pair p : add) dc.update(p.a, p.b);
    add = new ArrayList<Pair>();
    
    int max = 0;
    for (int i = 0; i < N; i++) {
      max = Math.max(max, Math.max(inc[i], dec[i]));
      for (int j = 0; j < N; j++) {
        if (pop[i] < pop[j]) {
          if (!((start[i]>=start[j]&&end[i]<=end[j])||
                (start[j]>=start[i]&&end[j]<=end[i]))) {
            int c = inc[i]+dec[j];
            int m = lca(i,j);
            if (pop[i] < pop[m] && pop[m] < pop[j]) c++;
            max = Math.max(max, c);
          }
        }
      }
    }
    
    out.println(max);
    out.close();
    System.exit(0);
  }
  
  static class Pair {
    public int a, b;
    public Pair (int a, int b) {
      this.a = a;
      this.b = b;
    }
  }
  
  public static int lca(int a, int b) {
    if (depth[a] < depth[b]) {
      a ^= b;
      b ^= a;
      a ^= b;
    }

    int diff = depth[a] - depth[b];
    for (int i = 0; i < anc.length && diff > 0; i++, diff >>= 1)
      if ((diff & 1) != 0)
        a = anc[i][a];

    if (a == b)
      return a;

    for (int i = anc.length - 1; i >= 0; i--)
      if (anc[i][a] != anc[i][b]) {
        a = anc[i][a];
        b = anc[i][b];
      }

    return anc[0][a];
  }

  static class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader() {
      din = new DataInputStream(System.in);
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException {
      din = new DataInputStream(new FileInputStream(file_name));
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException {
      byte[] buf = new byte[1024];
      int cnt = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      do {
        buf[cnt++] = c;
      } while ((c = read()) != '\n');
      return new String(buf, 0, cnt);
    }

    public String next() throws IOException {
      byte[] buf = new byte[1024];
      int cnt = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      do {
        buf[cnt++] = c;
      } while ((c = read()) > ' ');
      return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException {
      int ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (neg)
        return -ret;
      return ret;
    }

    public long nextLong() throws IOException {
      long ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (neg)
        return -ret;
      return ret;
    }

    public double nextDouble() throws IOException {
      double ret = 0, div = 1;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (c == '.')
        while ((c = read()) >= '0' && c <= '9')
          ret += (c - '0') / (div *= 10);
      if (neg)
        return -ret;
      return ret;
    }

    private void fillBuffer() throws IOException {
      bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
      if (bytesRead == -1)
        buffer[0] = -1;
    }

    private byte read() throws IOException {
      if (bufferPointer == bytesRead)
        fillBuffer();
      return buffer[bufferPointer++];
    }

    public void close() throws IOException {
      if (din == null)
        return;
      din.close();
    }
  }


}