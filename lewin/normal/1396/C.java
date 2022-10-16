import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Optional;
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
        CMonsterInvaders solver = new CMonsterInvaders();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMonsterInvaders {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            long r1 = in.nextLong(), r2 = in.nextLong(), r3 = in.nextLong(), d = in.nextLong();
            int[] arr = in.readIntArray(n);
            long[][] costs = new long[2][n];
            for (int i = 0; i < n; i++) {
                costs[0][i] = arr[i] * r1 + r3;
                costs[1][i] = Math.min(r1 + r2, (arr[i] + 2) * r1);
            }
            long[][] dp = new long[5][n];
            AUtils.deepFill(dp, 1L << 60);
            dp[0][0] = costs[0][0];
            dp[1][0] = costs[1][0];
            dp[3][0] = costs[1][0];
            for (int i = 1; i < n; i++) {
                dp[0][i] = Math.min(dp[0][i - 1], dp[2][i - 1]) + d + costs[0][i];
                dp[1][i] = Math.min(dp[0][i - 1], dp[2][i - 1]) + d + costs[1][i];
                dp[2][i] = Math.min(dp[1][i - 1], dp[2][i - 1]) + 3 * d + costs[1][i];
                dp[3][i] = Math.min(dp[0][i - 1], dp[2][i - 1]) + d + costs[1][i];
                dp[4][i] = Math.min(dp[3][i - 1], dp[4][i - 1]) + 2 * d + costs[1][i];
            }
            out.println(AUtils.min(dp[0][n - 1], dp[2][n - 1], Math.min(dp[3][n - 2], dp[4][n - 2]) + 2 * d + costs[0][n - 1]));
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

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class AUtils {
        public static <E extends Comparable<E>> E min(E... arr) {
            return Arrays.stream(arr).min(E::compareTo).get();
        }

        public static void deepFill(long[][] x, long val) {
            for (long[] y : x) deepFill(y, val);
        }

        public static void deepFill(long[] x, long val) {
            Arrays.fill(x, val);
        }

    }
}