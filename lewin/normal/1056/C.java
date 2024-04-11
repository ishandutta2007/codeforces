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
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CPickHeroes solver = new CPickHeroes();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPickHeroes {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] p = in.readIntArray(2 * n);
            int[] partner = new int[2 * n];
            Arrays.fill(partner, -1);
            CPickHeroes.Pair[] ps = new CPickHeroes.Pair[m];
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                partner[a] = b;
                partner[b] = a;
                ps[i] = new CPickHeroes.Pair(a, b);
            }
            int t = in.nextInt();
            boolean[] chosen = new boolean[2 * n];
            int left = 2 * n;
            if (t == 2) {
                while (left > 0) {
                    int x = in.nextInt() - 1;
                    chosen[x] = true;
                    left--;
                    if (partner[x] == -1) break;
                    out.println(partner[x] + 1);
                    chosen[x] = chosen[partner[x]] = true;
                    out.flush();
                    left--;
                }
            }
            while (left > 0) {
                boolean found = false;
                for (int i = 0; i < 2 * n; i++) {
                    if (!chosen[i] && partner[i] != -1) {
                        int b = p[i] > p[partner[i]] ? i : partner[i];
                        out.println(b + 1);
                        out.flush();
                        int x = in.nextInt() - 1;
                        chosen[b] = chosen[x] = true;
                        found = true;
                        left -= 2;
                    }
                }
                if (!found) break;
            }

            while (left > 0) {
                int mx = -1;
                for (int i = 0; i < 2 * n; i++) {
                    if (!chosen[i] && (mx == -1 || p[i] > p[mx])) {
                        mx = i;
                    }
                }
                if (mx == -1) break;
                out.println(mx + 1);
                chosen[mx] = true;
                left--;
                out.flush();
                if (left > 0) {
                    int x = in.nextInt() - 1;
                    left--;
                    chosen[mx] = chosen[x] = true;
                } else {
                    break;
                }
            }
        }

        static class Pair {
            public int a;
            public int b;

            public Pair(int a, int b) {
                this.a = a;
                this.b = b;
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

        public void flush() {
            writer.flush();
        }

        public void println(int i) {
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