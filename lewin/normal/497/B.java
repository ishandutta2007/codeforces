import java.io.*;
import java.util.*;

public class tennisgame {
  private static Reader in;
  private static PrintWriter out;
  
  static class Pair implements Comparable<Pair> {
    public int a, b;
    public Pair (int a, int b) {
      this.a = a;
      this.b = b;
    }
    
    public String toString() {
      return a+" "+b;
    }
    
    public int compareTo(Pair other) {
      return a == other.a ? b - other.b : a - other.a;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    
    N = in.nextInt();
    arr = new int[N+1];
    psum = new int[N+1];
    for (int i = 1; i <= N; i++) {
      arr[i] = in.nextInt();
      psum[i] =  psum[i-1] + (arr[i] == 1 ? 1 : 0);
    }
    ArrayList<Pair> ans = new ArrayList<Pair>();
    for (int i = 1; i <= N; i++) {
      int s = getVal(i);
      if (s > 0) ans.add(new Pair(s, i));
    }
    
    Collections.sort(ans);
    out.println(ans.size());
    for (Pair p : ans) out.println(p);
    out.close();
    System.exit(0);
  }
  
  public static int[] arr, psum;
  public static int N;
  public static int getVal (int t) {
    int a1 = 0, a2 = 0;
    int start = 1;
    while (start <= N) {
      int lo = start, hi = N;
      while (lo < hi) {
        int mid = (lo + hi) >> 1;
        int k = psum[mid] - psum[start-1];
        k = Math.max(k, mid - start + 1 - k);
        if (k < t) lo = mid + 1;
        else hi = mid;
      }
      int k = psum[lo] - psum[start-1];
      k = Math.max(k, lo - start + 1 - k);
      if (k < t) return -1;
      
      if (psum[lo]-psum[start-1] == t) {
        a1++;
      }
      else {
        a2++;
      }
      
      start = lo + 1;
    }
    if (a1 == a2) return -1;
    int max = Math.max(a1, a2);
    a1 = a2 = 0;
    start = 1;
    while (start <= N) {
      int lo = start, hi = N;
      while (lo < hi) {
        int mid = (lo + hi) >> 1;
        int k = psum[mid] - psum[start-1];
        k = Math.max(k, mid - start + 1 - k);
        if (k < t) lo = mid + 1;
        else hi = mid;
      }
      int k = psum[lo] - psum[start-1];
      k = Math.max(k, lo - start + 1 - k);
      if (k < t) return -1;
      
      if (psum[lo]-psum[start-1] == t) {
        a1++;
      }
      else {
        a2++;
      }
      start = lo + 1;

      if (a2 == max || a1 == max) {
        if (start > N) return max;
        else return -1;
      }
    }
    return Math.max(a1, a2);
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