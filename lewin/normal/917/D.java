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
        int MOD = 1000000007;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] a = new int[n - 1], b = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                a[i] = in.nextInt() - 1;
                b[i] = in.nextInt() - 1;
            }
            out.println(countTrees(n, a, b));
        }

        public long[] countTrees(int n, int[] a, int[] b) {
            boolean[][] g = new boolean[n][n];
            for (int i = 0; i < n - 1; i++) {
                g[a[i]][b[i]] = g[b[i]][a[i]] = true;
            }
            long[] y = new long[n];
            for (int t = 0; t < n; t++) {
                long[][] A = new long[n][n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++)
                        if (i != j) {
                            long v = g[i][j] ? t : 1;
                            A[i][i] += v;
                            A[i][j] -= v;
                            if (A[i][j] < 0) A[i][j] += MOD;
                        }
                }
                long[][] A2 = new long[n - 1][n - 1];
                for (int i = 0; i < n - 1; i++) for (int j = 0; j < n - 1; j++) A2[i][j] = A[i + 1][j + 1];
                y[t] = det(A2);
            }
            long[] x = interpolation(y);
            return x;
        }

        long[] interpolation(long[] y) {
            int n = y.length;
            long[] f = new long[n], a = new long[n], b = new long[n];
            for (int i = 0; i < n; i++) f[i] = y[i];
            a[0] = y[0];
            b[0] = 1;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j + i < n; j++) f[j] = (f[j + 1] - f[j] + MOD) % MOD * inv(i) % MOD;
                for (int j = i; j > 0; j--) b[j] = (b[j - 1] - (i - 1) * b[j] % MOD + MOD) % MOD;
                b[0] = b[0] * (MOD - (i - 1)) % MOD;
                for (int j = 0; j <= i; j++) {
                    a[j] = (a[j] + b[j] * f[0]) % MOD;
                }
            }
            return a;
        }

        long det(long[][] a) {
            int n = a.length;
            long[][] c = new long[n][n];
            long res = 1;
            for (int i = 0; i < n; i++) c[i] = a[i].clone();
            for (int p = 0; p < n; p++) {
                int pi = p;
                for (int i = p + 1; i < n; i++) {
                    if (c[i][p] > c[pi][p]) pi = i;
                }
                if (p != pi) res = (MOD - res) % MOD;
                long[] t1 = c[pi];
                c[pi] = c[p];
                c[p] = t1;
                if (c[p][p] == 0) return 0;
                res = res * c[p][p] % MOD;
                for (int i = p + 1; i < n; i++) {
                    c[i][p] = c[i][p] * inv(c[p][p]) % MOD;
                    for (int j = p + 1; j < n; j++) {
                        c[i][j] -= c[p][j] * c[i][p] % MOD;
                        if (c[i][j] < 0) c[i][j] += MOD;
                    }
                }
            }
            return res;
        }

        long pow(long a, long b) {
            long res = 1;
            while (b > 0) {
                if ((b & 1) != 0) res = res * a % MOD;
                a = a * a % MOD;
                b >>>= 1;
            }
            return res;
        }

        long inv(long a) {
            return pow(a, MOD - 2);
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

        public void print(long[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(long[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}