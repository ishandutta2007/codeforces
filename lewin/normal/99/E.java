import java.io.*;
import java.util.*;

public class E {
    private static Reader in;
    private static PrintWriter out;

    private static final double EPS = 1e-7;
    private static double a, b, l;
    
    public static void main(String[] args) throws IOException {
        in = new Reader();
        out = new PrintWriter(System.out, true);
        
        a = in.nextInt(); b = in.nextInt(); l = in.nextInt();
        
        if (l <= b) {
            out.printf ("%.7f\n", Math.min (a, l));
            out.close();
            System.exit(0);
        } else if (l <= a) {
            out.printf ("%.7f\n", Math.min (b, l));
            out.close();
            System.exit(0);
        }
        
        double lo = 0, hi = Math.PI / 2.;
        while (hi - lo >= 1e-9) {
            double mid1 = (2 * lo + hi) / 3., mid2 = (lo + 2 * hi) / 3.;
            double length1 = f(mid1), length2 = f(mid2);
            if (length1 < length2) hi = mid2;
            else lo = mid1;
        }
        
        if (f(lo) < EPS) {
            out.printf ("My poor head =(\n");
            out.close();
            System.exit(0);
        }
        
        out.printf ("%.7f\n", f(lo));
        out.close();
        System.exit(0);
    }
    
    private static double f (double angle) {
        double sin = Math.sin (angle), cos = Math.cos (angle);
        return a * cos + b * sin - l * cos * sin;
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