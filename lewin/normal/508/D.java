import java.io.*;
import java.util.*;

public class tanyapass {
  private static Reader in;
  private static PrintWriter out;
  
  public static int getIdx(char c) {
    if (c >= 'a' && c <= 'z') return c-'a';
    if (c >= 'A' && c <= 'Z') return c-'A'+26;
    return c-'0'+52;
  }
  public static char getChar(int idx) {
    if (idx < 26) return (char)(idx+'a');
    if (idx < 52) return (char)(idx-26+'A');
    return (char)(idx-52+'0');
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int sz = 70*70;
    int[][] grid = new int[sz][sz];
    int[] indeg = new int[sz], outdeg = new int[sz];
    for (int i = 0; i < N; i++) {
      char[] q = in.next().toCharArray();
      int a1 = getIdx(q[0])*70 + getIdx(q[1]);
      int a2 = getIdx(q[1])*70 + getIdx(q[2]);
      grid[a1][a2]++;
      indeg[a2]++;
      outdeg[a1]++;
    }
    
    boolean ok = true;
    int nonzero = -1;
    int start = -1, end = -1;
    for (int i = 0; i < sz; i++) {
      if (indeg[i] == outdeg[i]+1) {
        if (end != -1) ok = false;
        end = i;
      } else if (outdeg[i] == indeg[i]+1) {
        if (start != -1) ok = false;
        start = i;
      } else if (outdeg[i] != indeg[i]) {
        ok = false;
      }
      
      if (indeg[i] > 0) nonzero = i;
    }
    
    if (!ok) {
      out.println("NO");
      out.close();
      System.exit(0);
    }
    
    if (start == -1) {
      start = end = nonzero;
    }
    
    int[] fstack = new int[2*N];
    int[] bstack = new int[2*N];
    int fid = 0, bid = 0;
    fstack[fid++] = start;
    while (true) {
      int cur = fstack[fid-1];
      boolean found = false;
      for (int i = 0; i < sz; i++) {
        if (grid[cur][i] > 0) {
          grid[cur][i]--;
          fstack[fid++] = i;
          found = true;
          break;
        }
      }
      if (!found) break;
    }
    
    while (fid > 0) {
      int node = fstack[--fid];
      bstack[bid++] = node;
      if (fid > 0) while (true) {
        int cur = fstack[fid-1];
        boolean found = false;
        for (int i = 0; i < sz; i++) {
          if (grid[cur][i] > 0) {
            grid[cur][i]--;
            fstack[fid++] = i;
            found = true;
            break;
          }
        }
        if (!found) break;
      }
    }
    if (bid < N) {
      out.println("NO");
      out.close();
      System.exit(0);
    }
    
    char[] s = new char[N+2];
    s[0] = getChar(start/70);
    s[1] = getChar(start%70);
    for (int i = N-1; i >= 0; i--) {
      int node = bstack[i];
      s[N-i+1] = getChar(node%70);
    }
    out.println("YES");
    out.println(new String(s));
    out.close();
    System.exit(0);
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