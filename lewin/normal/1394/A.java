import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        ABoboniuChatsWithDu solver = new ABoboniuChatsWithDu();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABoboniuChatsWithDu {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), d = in.nextInt(), m = in.nextInt();
            long ans = 0;
            int[] arr = in.readIntArray(n);
            List<Integer> lo = new ArrayList<>();
            List<Integer> hi = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (arr[i] <= m) {
                    lo.add(arr[i]);
                } else {
                    hi.add(arr[i]);
                }
            }
            Collections.sort(lo);
            Collections.sort(hi);
            Collections.reverse(lo);
            Collections.reverse(hi);
            long[] ls = new long[lo.size() + 1];
            for (int i = 1; i <= lo.size(); i++) {
                ls[i] = ls[i - 1] + lo.get(i - 1);
            }
            long[] hs = new long[hi.size() + 1];
            for (int i = 1; i <= hi.size(); i++) {
                hs[i] = hs[i - 1] + hi.get(i - 1);
            }
            if (hi.size() == 0) {
                out.println(ls[lo.size()]);
                return;
            }
            for (int big = 1; big <= hi.size(); big++) {
                long lohide = 1L * (big - 1) * d;
                long hihide = 1L * big * d;
                if (lohide + big > n) continue;
                if (hi.size() - big > hihide) continue;
                int takelo = (int) (lo.size() - Math.max(0, lohide - (hi.size() - big)));
                ans = Math.max(ans, ls[takelo] + hs[big]);
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