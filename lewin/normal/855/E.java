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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public long[][][] count;

        public long solve(int base, int digits, int ones) {
            if (digits == 0) return ones == 0 ? 1 : 0;
            if (count[base][digits][ones] != -1) return count[base][digits][ones];
            long ret = 0;
            if (ones > 0) ret += ones * solve(base, digits - 1, ones - 1);
            if (ones < base) ret += (base - ones) * solve(base, digits - 1, ones + 1);
            return count[base][digits][ones] = ret;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int q = in.nextInt();
            count = new long[11][61][11];
            for (long[][] x : count) for (long[] y : x) Arrays.fill(y, -1);
            while (q-- > 0) {
                int base = in.nextInt();
                char[] s = Long.toString(in.nextLong(), base).toCharArray();
                char[] t = Long.toString(in.nextLong() + 1, base).toCharArray();
                out.println(solve(t, base) - solve(s, base));
            }
        }

        public long solve(char[] s, int base) {
            long ret = 0;
            int[] counts = new int[base];
            int odd = 0;
            if (s.length % 2 == 0) {
                for (int pref = 0; pref < s.length; pref++) {
                    for (int dig = (pref == 0 ? 1 : 0); dig < s[pref] - '0'; dig++) {
                        counts[dig]++;
                        if (counts[dig] % 2 == 1) odd++;
                        else odd--;

                        ret += solve(base, s.length - pref - 1, odd);

                        counts[dig]--;
                        if (counts[dig] % 2 == 1) odd++;
                        else odd--;
                    }
                    counts[s[pref] - '0']++;
                    if (counts[s[pref] - '0'] % 2 == 1) odd++;
                    else odd--;
                }
            }

            for (int lead = 1; lead < s.length; lead++) {
                ret += (base - 1) * solve(base, s.length - lead - 1, 1);
            }
            return ret;
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
}