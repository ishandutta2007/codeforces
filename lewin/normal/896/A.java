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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public long[] len = new long[100010];
        public String s = "What are you doing at the end of the world? Are you busy? Will you save us?";
        public String a1 = "What are you doing while sending \"";
        public String a2 = "\"? Are you busy? Will you send \"";
        public String a3 = "\"?";

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int q = in.nextInt();
            len[0] = s.length();
            for (int i = 1; i < len.length; i++) {
                len[i] = a1.length() + a2.length() + a3.length() + len[i - 1] + len[i - 1];
                if (len[i] >= 4e18) len[i] = (long) 4e18;
            }
            while (q-- > 0) {
                int n = in.nextInt();
                long k = in.nextLong();
                out.print(solve(n, k - 1));
            }
            out.println();
        }

        public char solve(int level, long index) {
            if (level == 0) {
                if (index >= s.length()) {
                    return '.';
                } else {
                    return s.charAt((int) index);
                }
            } else {
                if (index < a1.length()) return a1.charAt((int) index);
                if (index < a1.length() + len[level - 1]) return solve(level - 1, index - a1.length());
                if (index < a1.length() + len[level - 1] + a2.length())
                    return a2.charAt((int) (index - len[level - 1] - a1.length()));
                if (index < a1.length() + len[level - 1] + a2.length() + len[level - 1])
                    return solve(level - 1, index - a1.length() - len[level - 1] - a2.length());
                if (index < a1.length() + len[level - 1] + a2.length() + len[level - 1] + a3.length())
                    return a3.charAt((int) (index - len[level - 1] - a1.length() - len[level - 1] - a2.length()));
                return '.';
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

        public void println() {
            writer.println();
        }

        public void print(char i) {
            writer.print(i);
        }

        public void close() {
            writer.close();
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