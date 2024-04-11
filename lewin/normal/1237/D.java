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
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DBalancedPlaylist solver = new DBalancedPlaylist();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBalancedPlaylist {
        public int LOG = 30;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            int[][] mx = new int[LOG][n];
            int[][] mn = new int[LOG][n];
            for (int i = 0; i < n; i++) {
                mx[0][i] = mn[0][i] = arr[i];
            }
            for (int level = 1; level < LOG; level++) {
                int jump = 1 << (level - 1);
                for (int i = 0, j = jump % n; i < n; i++, j++) {
                    if (j >= n) j -= n;
                    mx[level][i] = Math.max(mx[level - 1][i], mx[level - 1][j]);
                    mn[level][i] = Math.min(mn[level - 1][i], mn[level - 1][j]);
                }
            }
            for (int i = 0; i < n; i++) {
                int cp = i;
                long cj = 0;
                int cmx = arr[i];
                while (cj < 2 * n) {
                    boolean changed = false;
                    for (int j = LOG - 1; j >= 0; j--) {
                        if (2 * mn[j][cp] >= Math.max(cmx, mx[j][cp])) {
                            cmx = Math.max(cmx, mx[j][cp]);
                            cj += 1 << j;
                            changed = true;
                            cp += 1 << j;
                            cp %= n;
                        }
                    }
                    if (!changed) break;
                }
                out.println(cj >= 2 * n ? -1 : cj);
            }
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

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
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
}