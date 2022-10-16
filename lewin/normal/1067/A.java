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
        AArrayWithoutLocalMaximums solver = new AArrayWithoutLocalMaximums();
        solver.solve(1, in, out);
        out.close();
    }

    static class AArrayWithoutLocalMaximums {
        int mod = 998244353;

        void psum(int[][] ps, int[][] nways) {
            for (int i = 0; i < 2; i++) {
                ps[i][0] = nways[i][0];
                for (int j = 1; j < nways[i].length; j++) {
                    ps[i][j] = ps[i][j - 1] + nways[i][j];
                    if (ps[i][j] >= mod) ps[i][j] -= mod;
                }
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            int maxn = 200;
            int[][] nways = new int[2][maxn + 1];
            int[][] ps = new int[2][maxn + 1];
            nways[1][0] = 1;
            psum(ps, nways);

            for (int i = 0; i < n; i++) {
                int[][] ndp = new int[2][maxn + 1];
                for (int k = 1; k <= maxn; k++) {
                    if (arr[i] == k || arr[i] == -1) {
                        { // prev == k
                            ndp[1][k] += nways[0][k];
                            if (ndp[1][k] >= mod) ndp[1][k] -= mod;
                            ndp[1][k] += nways[1][k];
                            if (ndp[1][k] >= mod) ndp[1][k] -= mod;
                        }
                        { // prev < k
                            ndp[0][k] += ps[1][k - 1];
                            if (ndp[0][k] >= mod) ndp[0][k] -= mod;
                            ndp[0][k] += ps[0][k - 1];
                            if (ndp[0][k] >= mod) ndp[0][k] -= mod;
                        }
                        { // prev > k
                            ndp[1][k] += ps[1][maxn];
                            if (ndp[1][k] >= mod) ndp[1][k] -= mod;
                            ndp[1][k] -= ps[1][k];
                            if (ndp[1][k] < 0) ndp[1][k] += mod;
                        }
                    }
                }
                nways = ndp;
                psum(ps, nways);
            }

            long sum = 0;
            for (int x : nways[1]) sum += x;
            out.println(sum % mod);
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
        private byte[] buf = new byte[1 << 20];
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