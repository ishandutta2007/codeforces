import java.io.*;
import java.util.*;

public class Main {
    private static Reader in;
    private static PrintWriter out;
    
    static class Pair {
      public int a, b;
      public Pair (int a, int b) {
        this.a = a;
        this.b = b;
      }
      public String toString() {
        return a + " " + b;
      }
    }
    
    public static boolean [] isPrime;
    public static int [] prime;
    public static int idx, len;
    
    private static void generatePrimes () {
        isPrime = new boolean [len + 1];
        prime = new int [len + 1];
        if (len == 1) return;
        isPrime [2] = true; prime [idx++] = 2;
        int i;
        for (i = 3; i <= len; i += 2) isPrime [i] = true;
        for (i = 3; i * i <= len; i += 2) {
            if (isPrime [i]) {
                prime [idx++] = i;
                for (int j = i * i; j <= len; j += 2 * i)
                    isPrime [j] = false;
            }
        }
        for (; i <= len; i += 2)
            if (isPrime [i])
                prime [idx++] = i;
    }
    
    public static void main (String [] args) throws IOException {
        in = new Reader ();
        out = new PrintWriter (System.out, true);
        int N = in.nextInt();
        len = N;
        generatePrimes();
        int[] dp = new int [len + 1];
        int[] pr = new int [len + 1];
        Arrays.fill (dp, 1 << 29);
        dp[0] = 0;
        for (int i = 1; i <= len; i++) {
          for (int j = 0; j < idx && prime[j] <= i + 1; j++) {
            if (dp[i - prime[j] + 1] + 1 < dp[i]) {
              dp[i] = dp[i - prime[j] + 1] + 1;
              pr[i] = prime[j];
            }
          }
        }
        int[] arr = new int[N];
//        for (int i = 0; i < N; i++) {
//          arr[i] = i;
//        }
//        for (int i = 1; i < N; i++) {
//          int j = (int)(Math.random() * (i + 1));
//          if (i == j) continue;
//          int t = arr[j]; arr [j] = arr[i]; arr [i] = t;
//        }
        for (int i = 0; i < N; i++)
          arr[i] = in.nextInt() - 1;
        int[] pos = new int[N];
        for (int i = 0; i < N; i++)
          pos[arr[i]] = i;
        
        ArrayList<Pair> moves = new ArrayList<Pair> ();
        for (int i = 0; i < N; i++) {
          while (pos[i] > i) {
            int diff = pos[i] - i;
            int p = pr[diff];
            moves.add (new Pair (pos[i] + 2 - p, pos[i] + 1));
            int d = arr[pos[i] + 1 - p];
            int t = pos[i];
            pos[i] = pos[d];
            pos[d] = t;
            t = arr[pos[i]];
            arr[pos[i]] = arr[pos[d]];
            arr[pos[d]] = t;
          }
        }
        
        out.println (moves.size());
        for (Pair p : moves) out.println (p);
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