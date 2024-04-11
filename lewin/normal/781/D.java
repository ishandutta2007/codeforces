import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.BitSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            BitSet[][][] conn = new BitSet[2][61][n];
            for (int i = 0; i < 2; i++)
                for (int j = 0; j <= 60; j++) for (int k = 0; k < n; k++) conn[i][j][k] = new BitSet(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, c = in.nextInt();
                conn[c][0][a].set(b);
            }
            for (int level = 1; level <= 60; level++) {
                for (int k = 0; k < n; k++) {
                    for (int i = 0; i < n; i++) {
                        if (conn[0][level - 1][i].get(k)) {
                            conn[0][level][i].or(conn[1][level - 1][k]);
                        }
                        if (conn[1][level - 1][i].get(k)) {
                            conn[1][level][i].or(conn[0][level - 1][k]);
                        }
                    }
                }
            }

            long ans = 0;
            boolean[] alive = new boolean[n];
            alive[0] = true;
            int which = 0;
            for (int level = 60; level >= 0; level--) {
                boolean[] nxt = new boolean[n];
                boolean found = false;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (alive[i] && conn[which][level][i].get(j)) {
                            nxt[j] = true;
                            found = true;
                        }
                    }
                }
                if (found) {
                    which ^= 1;
                    alive = nxt;
                    ans |= 1L << level;
                }
            }
            if (ans > 1e18) out.println(-1);
            else out.println(ans);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}