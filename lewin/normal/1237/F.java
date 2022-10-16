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
        FBalancedDominoPlacements solver = new FBalancedDominoPlacements();
        solver.solve(1, in, out);
        out.close();
    }

    static class FBalancedDominoPlacements {
        int mod = 998244353;

        int[] solve(boolean[] x) {
            int[][] ret = new int[x.length + 1][x.length / 2 + 1];
            ret[0][0] = 1;
            for (int i = 1; i <= x.length; i++) {
                for (int j = 0; j < x.length / 2 + 1; j++) {
                    ret[i][j] += ret[i - 1][j];
                    if (ret[i][j] >= mod) ret[i][j] -= mod;
                    if (j >= 1 && i >= 2 && !x[i - 1] && !x[i - 2]) {
                        ret[i][j] += ret[i - 2][j - 1];
                        if (ret[i][j] >= mod) ret[i][j] -= mod;
                    }
                }
            }
            return ret[x.length];
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int h = in.nextInt(), w = in.nextInt(), n = in.nextInt();
            boolean[] row = new boolean[h];
            boolean[] col = new boolean[w];
            for (int i = 0; i < n; i++) {
                int r1 = in.nextInt(), c1 = in.nextInt(), r2 = in.nextInt(), c2 = in.nextInt();
                r1--;
                c1--;
                r2--;
                c2--;
                row[r1] = row[r2] = col[c1] = col[c2] = true;
            }
            int[] r1 = solve(row), r2 = solve(col);
            int f1 = 0, f2 = 0;
            for (int i = 0; i < h; i++) if (!row[i]) f1++;
            for (int i = 0; i < w; i++) if (!col[i]) f2++;

            int[][] comb = Utils.getComb(4001, mod);
            long[] fact = new long[4001];
            fact[0] = 1;
            for (int i = 1; i < fact.length; i++) fact[i] = fact[i - 1] * i % mod;
            long ans = 0;
            for (int t1 = 0; t1 < r1.length; t1++) {
                if (r1[t1] == 0) continue;
                for (int t2 = 0; t2 < r2.length; t2++) {
                    if (r2[t2] == 0) continue;
                    int free1 = f1 - t1 * 2;
                    int free2 = f2 - t2 * 2;
                    if (free1 >= t2 && free2 >= t1) {
                        ans = (ans + 1L * comb[free1][t2] * comb[free2][t1] % mod * r1[t1] % mod * r2[t2] % mod * fact[t2] % mod * fact[t1]) % mod;
                    }
                }
            }
            out.println(ans);
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

    static class Utils {
        public static int[][] getComb(int sz, int mod) {
            int[][] comb = new int[sz][sz];
            for (int i = 0; i < sz; i++) {
                comb[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                    comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
                    if (comb[i][j] >= mod) comb[i][j] -= mod;
                }
            }
            return comb;
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