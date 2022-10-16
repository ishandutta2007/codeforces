
import java.util.*;
import java.io.*;

public class pigswolves {
    private static Reader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new Reader ();
        out = new PrintWriter (System.out, true);
        int N = in.nextInt(), M = in.nextInt();
        char [][] grid = new char [N + 2][M + 2];
        for (int i = 0; i <= N + 1; i++) grid [i][0] = grid [i][M + 1] = '.';
        for (int j = 0; j <= M + 1; j++) grid [0][j] = grid [N + 1][j] = '.';
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                grid [i][j] = in.nextChar();
        int count = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) {
                if (grid [i][j] == 'P') {
                    if (grid [i - 1][j] == 'W') {
                        count++;
                        grid [i - 1][j] = '.';
                    } else if (grid [i + 1][j] == 'W') {
                        count++;
                        grid [i + 1][j] = '.';
                    } else if (grid [i][j - 1] == 'W') {
                        count++;
                        grid [i][j - 1] = '.';
                    } else if (grid [i][j + 1] == 'W') {
                        count++;
                        grid [i][j + 1] = '.';
                    }
                }
            }
        out.println (count);
        out.close();
        System.exit(0);
    }
    
    static class Reader {
        final private int           BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte []         buffer;
        private int                 bufferPointer, bytesRead;
        
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
                if (c == '\n') break;
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
            if (neg) c = read ();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read ()) >= '0' && c <= '9');
            if (neg) return -ret;
            return ret;
        }
        
        public long nextLong () throws IOException {
            long ret = 0;
            byte c = read ();
            while (c <= ' ')
                c = read ();
            boolean neg = (c == '-');
            if (neg) c = read ();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read ()) >= '0' && c <= '9');
            if (neg) return -ret;
            return ret;
        }
        
        public double nextDouble () throws IOException {
            double ret = 0, div = 1;
            byte c = read ();
            while (c <= ' ')
                c = read ();
            boolean neg = (c == '-');
            if (neg) c = read ();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read ()) >= '0' && c <= '9');
            if (c == '.') while ((c = read ()) >= '0' && c <= '9')
                ret += (c - '0') / (div *= 10);
            if (neg) return -ret;
            return ret;
        }
        
        public char nextChar () throws IOException {
            byte c = read();
            while (c <= ' ') c = read();
            return (char)c;
        }
        
        private void fillBuffer () throws IOException {
            bytesRead = din.read (buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) buffer[0] = -1;
        }
        
        private byte read () throws IOException {
            if (bufferPointer == bytesRead) fillBuffer ();
            return buffer[bufferPointer++];
        }
        
        public void close () throws IOException {
            if (din == null) return;
            din.close ();
        }
    }
    
}