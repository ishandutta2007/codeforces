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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public int mod = 1000000007;
        public long[] fact;
        public long[] ifact;

        public long comb(int n, int k) {
            if (k < 0 || k > n) return 0;
            return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
        }

        public int solveSmart(int[] arr) {
            int n = arr.length;
            long[][] x = Factorials.getFIF(n + n + 1010, mod);
            fact = x[0];
            ifact = x[1];
            if (n % 4 == 0) {
                int b = n / 2 - 1;
                long ret = 0;
                for (int i = 0; i < arr.length; i++) {
                    long mult = comb(b, i / 2);
                    if (i % 2 == 1) mult = mod - mult;
                    ret = (mult * arr[i] + ret) % mod;
                }
                return (int) ret;
            } else if (n % 4 == 1) {
                int b = (n - 1) / 2;
                long ret = 0;
                for (int i = 0; i < arr.length; i += 2) {
                    long mult = comb(b, i / 2);
                    ret = (mult * arr[i] + ret) % mod;
                }
                return (int) ret;
            } else if (n % 4 == 2) {
                int b = (n - 2) / 2;
                long ret = 0;
                for (int i = 0; i < arr.length; i++) {
                    long mult = comb(b, i / 2);
                    ret = (mult * arr[i] + ret) % mod;
                }
                return (int) ret;
            } else if (n % 4 == 3) {
                int b = (n - 3) / 2;
                long ret = 0;
                for (int i = 0; i < arr.length; i++) {
                    long mult = comb(b, i / 2);
                    if (i % 2 == 1) mult = mult * 2 % mod;
                    else {
                        if (i * 2 >= arr.length) {
                            int t = arr.length - 1 - i;
                            mult = comb(b, t / 2);
                            mult = mult * (b - t + 1) % mod * x[2][b - t / 2 + 1] % mod;
                            mult = mod - mult;
                        } else {
                            mult = mult * (b - i + 1) % mod * x[2][b - i / 2 + 1] % mod;
                        }
                    }
                    ret = (mult * arr[i] + ret) % mod;
                }
                return (int) ret;
            }
            return 0;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            out.println(solveSmart(arr));
        }

    }

    static class Factorials {
        public static long[][] getFIF(int max, int mod) {
            long[] fact = new long[max];
            long[] ifact = new long[max];
            long[] inv = new long[max];
            inv[1] = 1;
            for (int i = 2; i < max; i++) {
                inv[i] = (mod - mod / i) * inv[mod % i] % mod;
            }
            fact[0] = 1;
            ifact[0] = 1;
            for (int i = 1; i < max; i++) {
                fact[i] = fact[i - 1] * i % mod;
                ifact[i] = ifact[i - 1] * inv[i] % mod;
            }
            return new long[][]{fact, ifact, inv};
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