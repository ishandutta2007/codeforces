import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class distributingparts {
  private static Reader in;
  private static PrintWriter out;
  
  static class Range implements Comparable<Range> {
    public int a, b, c, id;
    public Range(int a, int b, int id) {
      this.a = a;
      this.b = b;
      this.id = id;
    }
    
    public Range(int a, int b, int c, int id) {
      this.a = a;
      this.b = b;
      this.c = c;
      this.id = id;
    }
    
    public int compareTo(Range other) {
      return other.a - a;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    Range[] r = new Range[N];
    for (int i = 0; i < N; i++)
      r[i] = new Range(in.nextInt(), in.nextInt(), i);
    Arrays.sort(r);
    
    int M = in.nextInt();
    Range[] r2 = new Range[M];
    for (int i = 0; i < M; i++)
      r2[i] = new Range (in.nextInt(), in.nextInt(), in.nextInt(), i+1);
    Arrays.sort(r2);
    
    int[] which = new int[N];
    Arrays.fill(which, -1);
    int idx = 0;
    TreeMap<Integer, LinkedList<Integer>> seen = new TreeMap<Integer, LinkedList<Integer>>();
    for (int i = 0; i < M; i++) {
      while (idx < N && r[idx].a >= r2[i].a) {
        if (!seen.containsKey(r[idx].b)) {
          seen.put(r[idx].b, new LinkedList<Integer>());
        }
        seen.get(r[idx].b).add(r[idx].id);
        idx++;
      }
      int left = r2[i].c;
      while (true) {
        if (left <= 0) break;
        Entry<Integer, LinkedList<Integer>> m = seen.floorEntry(r2[i].b);
        if (m == null) break;
        LinkedList<Integer> k = m.getValue();
        while (k.size() > 0 && left-- > 0) {
          which[k.removeFirst()] = r2[i].id;
        }
        if (k.size() == 0) seen.remove(m.getKey());
      }
    }
    boolean ok = true;
    for (int i = 0; i < N; i++) if (which[i] == -1) {
      ok = false;
      break;
    }
    if (!ok) out.println("NO");
    else {
      out.println("YES");
      out.print(which[0]);
      for (int i = 1; i < N; i++)
        out.print(" "+which[i]);
      out.println();
    }
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