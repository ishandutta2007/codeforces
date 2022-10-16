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
        ECowAndTreats solver = new ECowAndTreats();
        solver.solve(1, in, out);
        out.close();
    }

    static class ECowAndTreats {
        int mod = 1000000007;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] s = in.readIntArrayAndDecrementOne(n);
            boolean[][] x = new boolean[5001][5001];
            int[][] pc = new int[5001][5001];
            ECowAndTreats.Cow[] cs = new ECowAndTreats.Cow[m];
            for (int i = 0; i < m; i++) {
                cs[i] = new ECowAndTreats.Cow(in.nextInt() - 1, in.nextInt());
                x[cs[i].f][cs[i].h] = true;
            }
            for (int i = 0; i < n; i++) {
                pc[i][0] = 0;
                for (int j = 1; j <= n; j++) {
                    pc[i][j] = pc[i][j - 1] + (x[i][j] ? 1 : 0);
                }
            }
            int[] counts = new int[n];
            for (int i = 0; i < n; i++) counts[s[i]]++;

            int[] cc = new int[n];
            long mxcount = 0, nways = 0;
            for (int i = 0; i < n; i++) {
                cc[s[i]]++;
                if (x[s[i]][cc[s[i]]]) {
                    int c = 1;
                    long ways = 0;
                    if (x[s[i]][cc[s[i]]]) {
                        ways++;
                        int o = counts[s[i]] - cc[s[i]];
                        int left = pc[s[i]][o];
                        if (o >= cc[s[i]]) left--;
                        if (left > 0) {
                            c++;
                            ways = left;
                        }
                    }
                    for (int j = 0; j < n; j++) {
                        if (s[i] == j) continue;
                        int before = cc[j];
                        int after = counts[j] - cc[j];
                        if (after < before) {
                            int t = after;
                            after = before;
                            before = t;
                        }
                        if (pc[j][before] > 0 && pc[j][after] > 1) {
                            c += 2;
                            ways = ways * pc[j][before] % mod * (pc[j][after] - 1) % mod;
                        } else if (pc[j][before] > 0 || pc[j][after] > 0) {
                            c++;
                            ways = ways * (pc[j][before] + pc[j][after]) % mod;
                        }
                    }

                    if (c > mxcount) {
                        mxcount = c;
                        nways = 0;
                    }
                    if (c == mxcount) {
                        nways = (nways + ways) % mod;
                    }
                }
            }
            int c = 0;
            long ways = 1;
            for (int i = 0; i < n; i++) {
                if (pc[i][counts[i]] > 0) {
                    c++;
                    ways = ways * pc[i][counts[i]] % mod;
                }
            }
            if (c == mxcount) nways = (nways + ways) % mod;

            out.println(mxcount + " " + nways);
        }

        static class Cow {
            public int f;
            public int h;

            public Cow(int f, int h) {
                this.f = f;
                this.h = h;
            }

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

        public int[] readIntArrayAndDecrementOne(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt() - 1;
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}