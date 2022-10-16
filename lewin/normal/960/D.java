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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int getlevel(long x) {
            return Long.numberOfTrailingZeros(Long.highestOneBit(x));
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int q = in.nextInt();
            long[] shifts = new long[62];
            while (q-- > 0) {
                int type = in.nextInt();
                if (type == 1) {
                    int level = getlevel(in.nextLong());
                    long k = in.nextLong();
                    k %= 1L << level;
                    if (k < 0) k += (1L << level);
                    shifts[level] += k;
                    shifts[level] %= 1L << level;
                } else if (type == 2) {
                    int level = getlevel(in.nextLong());
                    long k = in.nextLong();
                    k %= 1L << level;
                    if (k < 0) k += (1L << level);
                    for (int j = level; j < shifts.length; j++) {
                        shifts[j] += k << (j - level);
                        shifts[j] %= 1L << j;
                    }
                } else {
                    long value = in.nextLong();
                    while (true) {
                        if (value == 1) {
                            out.println(value);
                            break;
                        }

                        out.print(value + " ");
                        int level = getlevel(value);
                        long cur = value - (1L << level);

                        long actualpos = (1L << level) + ((cur + shifts[level]) % (1L << level));
                        long parent = actualpos / 2;
                        long c2 = parent - (1L << (level - 1));
                        c2 = (c2 + (1L << (level - 1)) - shifts[level - 1]) % ((1L << (level - 1)));
                        value = (1L << (level - 1)) + c2;
                    }
                }
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}