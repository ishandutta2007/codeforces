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
import java.util.Collections;
import java.util.ArrayList;
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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long x = in.nextLong(), y = in.nextLong();
            ArrayList<Long> divs = new ArrayList<>();
            for (int i = 1; 1L * i * i <= x; i++) {
                if (x % i == 0) {
                    divs.add((long) i);
                    if (1L * i * i != x)
                        divs.add(x / i);
                }
            }
            Collections.sort(divs);
            long curdiv = Utils.gcd(y, x);
            int pos = -1;
            for (int i = 0; i < divs.size(); i++) {
                if (divs.get(i) == curdiv) {
                    pos = i;
                    break;
                }
            }

            long res = 0;
            while (y > 0) {
                long numsteps = y / curdiv;
                long num = 0;
                int npos = divs.size();
                for (int j = pos + 1; j < divs.size(); j++) {
                    long nextdiv = divs.get(j);
                    long e = y % nextdiv;
                    if (y - e >= num && e % curdiv == 0) {
                        numsteps = e / curdiv;
                        num = y - e;
                        npos = j;
                    }
                }

                pos = npos;
                if (pos < divs.size()) curdiv = divs.get(pos);
                res += numsteps;
                y = num;
            }
            out.println(res);
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
        public static long gcd(long x, long y) {
            for (; x != 0; x ^= y, y ^= x, x ^= y, x %= y) ;
            return y;
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