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
        ESegmentSum solver = new ESegmentSum();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESegmentSum {
        int mod = 998244353;
        String l;
        String r;
        int k;
        long[][][][][][] dp;
        int[] p10;

        long[] dfs(int curdig, int nonzero, int greater, int less, int mask) {
            if (Integer.bitCount(mask) > k) return new long[]{0, 0};
            if (curdig == l.length()) return new long[]{1, 0};
            if (dp[curdig][nonzero][greater][less][mask] != null)
                return dp[curdig][nonzero][greater][less][mask];

            long count = 0, sum = 0;
            for (int i = 0; i <= 9; i++) {
                if (greater == 0 && i < l.charAt(curdig) - '0') continue;
                if (less == 0 && i > r.charAt(curdig) - '0') continue;

                int nz = nonzero | (i != 0 ? 1 : 0);
                int ngreater = greater | (i > l.charAt(curdig) - '0' ? 1 : 0);
                int nless = less | (i < r.charAt(curdig) - '0' ? 1 : 0);
                int nmask = mask | (nz != 0 ? (1 << i) : 0);
                long[] q = dfs(curdig + 1, nz, ngreater, nless, nmask);
                count += q[0];
                if (count >= mod) count -= mod;
                sum = (sum + q[1] + q[0] * p10[l.length() - 1 - curdig] * i) % mod;
            }
            return dp[curdig][nonzero][greater][less][mask] = new long[]{count, sum};
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            l = in.next();
            r = in.next();
            while (l.length() < r.length()) {
                l = "0" + l;
            }
            k = in.nextInt();

            dp = new long[l.length()][2][2][2][1 << 10][];
            p10 = Utils.genPower(10, l.length(), mod);
            out.println(dfs(0, 0, 0, 0, 0)[1]);
        }

    }

    static class Utils {
        public static int[] genPower(int base, int len, int mod) {
            int[] ret = new int[len];
            ret[0] = 1;
            for (int i = 1; i < len; i++) ret[i] = (int) (1L * ret[i - 1] * base % mod);
            return ret;
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

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
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

    }
}