import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public int mod = 1000000007;
        public int x1;
        public int x2;
        public int y1;
        public int y2;
        public int k;
        public int MAXB = 32;
        public int[][] dpc;
        public int[][] dps;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            x1 = in.nextInt() - 1;
            y1 = in.nextInt() - 1;
            x2 = in.nextInt() - 1;
            y2 = in.nextInt() - 1;
            k = in.nextInt() - 1;
            dpc = new int[MAXB][1 << 5];
            dps = new int[MAXB][1 << 5];
            for (int i = 0; i < MAXB; i++) {
                Arrays.fill(dpc[i], -1);
                Arrays.fill(dps[i], -1);
            }
            dfs(MAXB - 1, 0, 0, 0, 0, 0);
            out.println((dps[MAXB - 1][0] + dpc[MAXB - 1][0]) % mod);
        }

        public void dfs(int bit, int gx, int lx, int gy, int ly, int lk) {
            int cm = getMask(gx, lx, gy, ly, lk);
            if (dpc[bit][cm] != -1) return;

            int cx1 = (x1 >> bit) & 1;
            int cx2 = (x2 >> bit) & 1;
            int cy1 = (y1 >> bit) & 1;
            int cy2 = (y2 >> bit) & 1;
            int ck = (k >> bit) & 1;
            dpc[bit][cm] = 0;
            dps[bit][cm] = 0;
            for (int xb = 0; xb <= 1; xb++) {
                for (int yb = 0; yb <= 1; yb++) {
                    if (xb == 0 && cx1 == 1 && gx == 0) continue;
                    if (xb == 1 && cx2 == 0 && lx == 0) continue;
                    if (yb == 0 && cy1 == 1 && gy == 0) continue;
                    if (yb == 1 && cy2 == 0 && ly == 0) continue;
                    int bitk = xb ^ yb;
                    if (bitk == 1 && ck == 0 && lk == 0) continue;

                    int ngx = gx | (xb > cx1 ? 1 : 0);
                    int ngy = gy | (yb > cy1 ? 1 : 0);
                    int nlx = lx | (xb < cx2 ? 1 : 0);
                    int nly = ly | (yb < cy2 ? 1 : 0);
                    int nlk = lk | (bitk < ck ? 1 : 0);

                    if (bit > 0) {
                        dfs(bit - 1, ngx, nlx, ngy, nly, nlk);
                        int ms = getMask(ngx, nlx, ngy, nly, nlk);
                        dps[bit][cm] = (int) ((dps[bit][cm] + dps[bit - 1][ms] + 1L * dpc[bit - 1][ms] * (bitk << bit)) % mod);
                        dpc[bit][cm] += dpc[bit - 1][ms];
                        if (dpc[bit][cm] >= mod) dpc[bit][cm] -= mod;
                    } else {
                        dps[bit][cm] += bitk << bit;
                        dpc[bit][cm]++;
                    }
                }
            }
        }

        public int getMask(int gx, int lx, int gy, int ly, int lk) {
            int msk = gx;
            msk <<= 1;
            msk |= lx;
            msk <<= 1;
            msk |= gy;
            msk <<= 1;
            msk |= ly;
            msk <<= 1;
            msk |= lk;
            return msk;
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

        public void println(int i) {
            writer.println(i);
        }

    }
}