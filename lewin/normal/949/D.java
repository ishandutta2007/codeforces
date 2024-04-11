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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int n;
        int d;
        int b;
        int[] arr;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            d = in.nextInt();
            b = in.nextInt();
            arr = in.readIntArray(n);
            int lo = 0, hi = n / 2;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (can(mid)) hi = mid;
                else lo = mid + 1;
            }
            out.println(lo);
        }

        boolean can(int mid) {
            int fptr = mid, bptr = n - 1 - mid;
            int a1 = 0, a2 = n - 1;
            int steps = 0;
            int[] brr = Arrays.copyOf(arr, n);
            while (fptr < bptr) {
                long span = 1L * d * (mid + steps + 1);
                a1 = (int) Math.max(a1, fptr - span);
                a2 = (int) Math.min(a2, bptr + span);
                {
                    long need = b;
                    while (a1 <= fptr + span && a1 <= a2 && need > 0) {
                        long take = Math.min(need, brr[a1]);
                        brr[a1] -= take;
                        need -= take;
                        if (brr[a1] == 0) a1++;
                    }
                    if (need > 0) return false;
                }
                {
                    long need = b;
                    while (a2 >= bptr - span && a2 >= a1 && need > 0) {
                        long take = Math.min(need, brr[a2]);
                        brr[a2] -= take;
                        need -= take;
                        if (brr[a2] == 0) a2--;
                    }
                    if (need > 0) return false;
                }
                steps++;
                fptr++;
                bptr--;
            }
            if (fptr == bptr) {
                long span = 1L * d * (mid + steps + 1);
                a1 = (int) Math.max(a1, fptr - span);
                a2 = (int) Math.min(a2, bptr + span);
                long need = b;
                while (a1 <= fptr + span && a1 <= a2 && need > 0) {
                    long take = Math.min(need, brr[a1]);
                    brr[a1] -= take;
                    need -= take;
                    if (brr[a1] == 0) a1++;
                }
                if (need > 0) return false;
            }
            return true;
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