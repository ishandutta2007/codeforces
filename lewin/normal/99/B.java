import java.io.*;
import java.util.*;

public class B {
    private static Reader in;
    private static PrintWriter out;

    public static void main(String[] args) throws IOException {
        in = new Reader();
        out = new PrintWriter(System.out, true);
        
        int N = in.nextInt();
        Pair [] arr = new Pair [N];
        boolean equals = true;
        for (int i = 0; i < N; i++) {
            arr[i] = new Pair (i + 1, in.nextInt());
            if (i > 0 && arr[i].b != arr [i - 1].b) equals = false;
        }
        if (equals) {
            out.println ("Exemplary pages.");
            out.close();
            System.exit(0);
        }
        Arrays.sort (arr);
        equals = true;
        for (int i = 2; i < N - 1; i++) {
            if (arr[i].b != arr[i - 1].b) equals = false;
        }
        if (!equals) {
            out.println ("Unrecoverable configuration.");
            out.close();
            System.exit(0);
        }
        
        if (N == 2) {
            if ((arr[0].b + arr[1].b) % 2 != 0) {
                out.println ("Unrecoverable configuration.");
                out.close();
                System.exit(0);
            } else {
                int mid = (arr[0].b + arr[1].b) >> 1;
                out.printf ("%d ml. from cup #%d to cup #%d.\n", arr[1].b-mid, arr[0].a, arr[1].a);
                out.close();
                System.exit(0);
            }
        }
        
        if (arr[0].b + arr[arr.length-1].b != 2 * arr[1].b) {
            out.println ("Unrecoverable configuration.");
            out.close();
            System.exit(0);
        }
        out.printf ("%d ml. from cup #%d to cup #%d.\n", arr[arr.length-1].b-arr[1].b, arr[0].a, arr[arr.length-1].a);
        out.close();
            System.exit(0);
    }
    
    static class Pair implements Comparable <Pair> {
        public int a, b;
        
        public Pair (int a, int b) {
            this.a = a;
            this.b = b;
        }
        
        public int compareTo (Pair other) {
            return b - other.b;
        }
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