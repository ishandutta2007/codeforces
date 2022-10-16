import java.io.*;
import java.util.*;

public class Main {
  private static Reader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    coords = new long[8][3];
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 3; j++)
        coords[i][j] = in.nextInt();
    check = new long[8][3];
    dfs(0);
    
    out.println("NO");
    out.close();
    System.exit(0);
  }
  
  public static long[][] check, coords;
  
  public static long sq(long x){return x * x;}
  
  public static boolean isCube() {
    long v1 = -1, v2 = -1, v3 = -1;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = i + 1; j < 8; j++) {
        long key = sq(check[i][0] - check[j][0]) +
                   sq(check[i][1] - check[j][1]) +
                   sq(check[i][2] - check[j][2]);
        if (key == v1) c1++;
        else if (key == v2) c2++;
        else if (key == v3) c3++;
        else if (v1 == -1) {
          v1 = key;
          c1++;
        } else if (v2 == -1) {
          v2 = key;
          c2++;
        } else if (v3 == -1) {
          v3 = key;
          c3++;
        } else return false;
      }
    }
    int[] counts = new int[30];
    counts[c1]++; counts[c2]++; counts[c3]++;
    if (counts[4] != 1 || counts[12] != 2)
      return false;
    return true;
  }
  
  public static void dfs(int index) {
    if (index == 8) {
      if(isCube()) {
        out.println ("YES");
        for (int i = 0; i < 8; i++) {
          out.printf("%d %d %d\n", check[i][0], check[i][1], check[i][2]);
        }
        out.close();
        System.exit(0);
      }
      return;
    }
    
    check[index][0] = coords[index][0];
    check[index][1] = coords[index][1];
    check[index][2] = coords[index][2];
    dfs(index + 1);
    check[index][0] = coords[index][0];
    check[index][1] = coords[index][2];
    check[index][2] = coords[index][1];
    dfs(index + 1);
    check[index][0] = coords[index][1];
    check[index][1] = coords[index][0];
    check[index][2] = coords[index][2];
    dfs(index + 1);
    check[index][0] = coords[index][1];
    check[index][1] = coords[index][2];
    check[index][2] = coords[index][0];
    dfs(index + 1);
    check[index][0] = coords[index][2];
    check[index][1] = coords[index][0];
    check[index][2] = coords[index][1];
    dfs(index + 1);
    check[index][0] = coords[index][2];
    check[index][1] = coords[index][1];
    check[index][2] = coords[index][0];
    dfs(index + 1);
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