import java.io.*;
import java.util.*;

public class Main {
  private static Reader in;
  private static PrintWriter out;

  static class Interval implements Comparable<Interval> {
    public int a, b, id;

    public Interval(int a, int b, int id) {
      this.a = a;
      this.b = b;
      this.id = id;
    }

    public int compareTo(Interval other) {
      return a == other.a ? b - other.b : a - other.a;
    }
  }

  private static int[] eadj, elast, eprev;
  private static int eidx;

  private static void addEdge(int a, int b) {
    eadj[eidx] = b;
    eprev[eidx] = elast[a];
    elast[a] = eidx++;
    eadj[eidx] = a;
    eprev[eidx] = elast[b];
    elast[b] = eidx++;
  }

  private static int[] ans, queue;

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);

    int N = in.nextInt();
    if (N == 1) {
      out.println(1);
      out.close();
      System.exit(0);
    }

    PriorityQueue<Interval> pq = new PriorityQueue<Interval>();
    for (int i = 0; i < N; i++) {
      int a = in.nextInt(), b = in.nextInt();
      pq.add(new Interval(a, b, i));
    }

    eadj = new int[2 * N];
    elast = new int[N];
    eprev = new int[2 * N];
    eidx = 0;
    Arrays.fill(elast, -1);

    while (pq.size() > 1) {
      Interval a = pq.poll(), b = pq.poll();
      if (b.a > a.b) {
        pq.add(b);
        continue;
      }
      addEdge(a.id, b.id);
      if (a.b > b.b) {
        pq.add(new Interval(b.b + 1, a.b, a.id));
      } else if (a.b < b.b) {
        pq.add(new Interval(a.b + 1, b.b, b.id));
      }
    }

    ans = new int[N];
    queue = new int[N];
    int front = 0, back = 0;
    for (int i = 0; i < N; i++)
      if (ans[i] == 0) {
        ans[i] = 1;
        queue[back++] = i;
        while (front < back) {
          int node = queue[front++];
          for (int e = elast[node]; e != -1; e = eprev[e]) {
            if (ans[eadj[e]] != 0)
              continue;
            ans[eadj[e]] = -ans[node];
            queue[back++] = eadj[e];
          }
        }
      }

    out.print (ans[0] == -1 ? 0 : 1);
    for (int i = 1; i < N; i++)
      out.print(" " + (ans[i] == -1 ? 0 : 1));


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
      int cnt = 0, c;
      while ((c = read()) != -1) {
        if (c == '\n')
          break;
        buf[cnt++] = (byte) c;
      }
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