import java.io.*;
import java.util.*;

public class Main {
    private static Reader in;
    private static PrintWriter out;
    
    static class Point {
      public double x, y;
      
      public Point (double x, double y) {
          this.x = x;
          this.y = y;
      }
  }
    
    private static long closestPair(Point[] points) {
      double min = 1l << 50;
      int left = 0;
      
      TreeSet <Point> curset = new TreeSet <Point>(
              new Comparator <Point> () {
                  public int compare (Point a, Point b) {
                      return (int)(Math.signum (a.y == b.y ? a.x - b.x : a.y - b.y));
                  }
              });
      
      double m = Math.sqrt(min);
      for (Point p : points) {
          while (p.x - points [left].x > min)
              curset.remove (points [left++]);
          for (Point next : curset.subSet (
                  new Point (p.x, p.y - m),
                  new Point (p.x, p.y + m))) {
              double temp = dist (p, next);
              if (temp < min) {
                  min = temp;
                  m = Math.sqrt(min);
              }
          }
          curset.add (p);
      }
      
      return (long)min;
  }
  
  private static double dist (Point p1, Point p2) {
      return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  }
    
    public static void main (String [] args) throws IOException {
        in = new Reader ();
        out = new PrintWriter (System.out, true);
        int N = in.nextInt();
        
        Point[] pts = new Point[N];
        long csum = 0;
        for (int i = 0; i < N; i++)
          pts[i] = new Point (i, csum += in.nextInt());
        out.println (closestPair(pts));
        out.close();
        System.exit(0);
    }
    
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte [] buffer;
        private int bufferPointer, bytesRead;
        
        public Reader () {
            din = new DataInputStream (System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        
        public Reader (String file_name) throws IOException {
            din = new DataInputStream (new FileInputStream (file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        
        public String readLine () throws IOException {
            byte [] buf = new byte[1024];
            int cnt = 0, c;
            while ((c = read ()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String (buf, 0, cnt);
        }
        
        public int nextInt () throws IOException {
            int ret = 0;
            byte c = read ();
            while (c <= ' ')
                c = read ();
            boolean neg = (c == '-');
            if (neg)
                c = read ();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read ()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
        
        public long nextLong () throws IOException {
            long ret = 0;
            byte c = read ();
            while (c <= ' ')
                c = read ();
            boolean neg = (c == '-');
            if (neg)
                c = read ();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read ()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
        
        public double nextDouble () throws IOException {
            double ret = 0, div = 1;
            byte c = read ();
            while (c <= ' ')
                c = read ();
            boolean neg = (c == '-');
            if (neg)
                c = read ();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read ()) >= '0' && c <= '9');
            if (c == '.')
                while ((c = read ()) >= '0' && c <= '9')
                    ret += (c - '0') / (div *= 10);
            if (neg)
                return -ret;
            return ret;
        }
        
        private void fillBuffer () throws IOException {
            bytesRead = din.read (buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
        
        private byte read () throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer ();
            return buffer[bufferPointer++];
        }
        
        public void close () throws IOException {
            if (din == null)
                return;
            din.close ();
        }
    }
}