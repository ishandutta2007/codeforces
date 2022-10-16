import java.io.*;
import java.util.*;

public class Main {
    private static Reader in;
    private static PrintWriter out;
    private static int [] eadj, eprev, elast;
    private static int eidx;
    
    private static void addEdge (int a, int b) {
      eadj[eidx] = b; eprev[eidx] = elast[a]; elast[a] = eidx++;
      eadj[eidx] = a; eprev[eidx] = elast[b]; elast[b] = eidx++;
    }
    
    public static void main (String [] args) throws IOException {
        in = new Reader ();
        out = new PrintWriter (System.out, true);
        int N = in.nextInt();
        eadj = new int[2 * N];
        eprev = new int [2 * N];
        elast = new int[N];
        eidx = 0;
        Arrays.fill (elast, -1);
        for (int i = 0; i < N - 1; i++)
          addEdge (in.nextInt() - 1, in.nextInt() - 1);
        
        int[] queue = new int[N];
        int front = 0, back = 0;
        queue[back++] = 0;
        int[] par = new int[N];
        par[0] = -1;
        while (front < back) {
          int node = queue[front++];
          for (int e = elast[node]; e != -1; e = eprev[e]) {
            if (eadj[e] == par[node]) continue;
            queue[back++] = eadj[e];
            par[eadj[e]] = node;
          }
        }
        
        int[] initValues = new int[N];
        for (int i = 0; i < N; i++)
          initValues[i] = in.nextInt();
        int[] finalValues = new int[N];
        for (int i = 0; i < N; i++)
          finalValues[i] = in.nextInt();
        
        int[][] push = new int[2][N];
        ArrayList<Integer> moves = new ArrayList<Integer> ();
        for (int i = 0; i < N; i++) {
          int node = queue[i];
          initValues[node] ^= push[0][node];
          if (initValues[node] != finalValues[node]) {
            push[0][node] ^= 1;
            moves.add(node + 1);
          }
          for (int e = elast[node]; e != -1; e = eprev[e]) {
            push[1][eadj[e]] = push[0][node];
            push[0][eadj[e]] = push[1][node];
          }
        }
        
        out.println (moves.size());
        for (int k : moves)
          out.println (k);
        
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