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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public String ss = "AGCT";

        public int get(int pos, int mod, int len) {
            int e1 = pos % mod, e2 = pos / mod;
            return e1 * (len / mod + 1) + e2 + 5;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] s = in.next().toCharArray();
            int q = in.nextInt();
            BIT[][] b = new BIT[4][11];
            for (int i = 0; i < 4; i++) for (int j = 0; j <= 10; j++) b[i][j] = new BIT(2 * s.length + 1010);
            for (int i = 0; i < s.length; i++) {
                for (int k = 1; k <= 10; k++) {
                    b[ss.indexOf(s[i])][k].update(get(i, k, s.length), +1);
                }
            }

            while (q-- > 0) {
                int type = in.nextInt();
                if (type == 1) {
                    int pos = in.nextInt() - 1;
                    char c = in.nextChar();
                    if (s[pos] != c) {
                        for (int k = 1; k <= 10; k++) {
                            b[ss.indexOf(s[pos])][k].update(get(pos, k, s.length), -1);
                            b[ss.indexOf(c)][k].update(get(pos, k, s.length), +1);
                        }
                        s[pos] = c;
                    }
                } else {
                    int l = in.nextInt() - 1, r = in.nextInt() - 1;
                    char[] e = in.next().toCharArray();
                    int res = 0;
                    for (int i = l; i <= r && i < l + e.length; i++) {
                        int from = i, to = i + ((r - i) / e.length) * e.length;
                        if (to + e.length <= r) to += e.length;
                        res += b[ss.indexOf(e[i - l])][e.length].query(get(to, e.length, s.length)) - b[ss.indexOf(e[i - l])][e.length].query(get(from, e.length, s.length) - 1);
                    }
                    out.println(res);
                }
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

        public void println(int i) {
            writer.println(i);
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

        public char nextChar() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            return (char) c;
        }

    }

    static class BIT {
        private long[] tree;
        private int N;

        public BIT(int N) {
            this.N = N;
            this.tree = new long[N + 3];
        }

        public long query(int K) {
            K += 2;
            long sum = 0;
            for (int i = K; i > 0; i -= (i & -i))
                sum += tree[i];
            return sum;
        }

        public void update(int K, long val) {
            K += 2;
            for (int i = K; i < tree.length; i += (i & -i))
                tree[i] += val;
        }

    }
}