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
        public int[] arr;
        public long ans;
        public int[] ps;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            arr = in.readIntArray(n);
            for (int i = 0; i < n; i++) arr[i] += n - i;
            ans = 0;
            ps = new int[n];
            solve(0, n - 1, 0, 1000000000 + n);
            out.println(ans);
        }

        public void solve(int lo, int hi, int al, int ah) {
            if (lo > hi) return;
            if (al == ah) {
                for (int j = lo; j <= hi; j++) {
                    ans += Math.abs(al - arr[j]);
                }
                return;
            }
            if (lo == hi) {
                if (arr[lo] < al) ans += al - arr[lo];
                if (arr[lo] > ah) ans += arr[lo] - ah;
                return;
            }

            int am = (al + ah) / 2;
            int psum = 0;
            int best = 0;
            for (int i = lo; i <= hi; i++) {
                psum += arr[i] > am ? -1 : +1;
                ps[i] = psum;
                best = Math.max(best, psum);
            }
            for (int i = hi; i >= lo; i--) {
                if (ps[i] == best) {
                    solve(lo, i, al, am);
                    solve(i + 1, hi, am + 1, ah);
                    return;
                }
            }
            if (best == 0) {
                solve(lo, hi, am + 1, ah);
                return;
            }
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
}