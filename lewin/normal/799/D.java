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
        public int[] can;
        public int mxn = 100010;
        public int cgen;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int a = in.nextInt(), b = in.nextInt(), w = in.nextInt(), h = in.nextInt(), n = in.nextInt();
            int[] z = in.readIntArray(n);
            AUtils.sort(z);
            can = new int[mxn];
            int ans = Math.min(solve((a + w - 1) / w, (b + h - 1) / h, z), solve((a + h - 1) / h, (b + w - 1) / w, z));
            if (ans > n) out.println(-1);
            else out.println(ans);
        }

        public int solve(int n1, int n2, int[] z) {
            if (n1 > n2) {
                int t = n1;
                n1 = n2;
                n2 = t;
            }
            int n = z.length;
            for (int need = 0; need <= n && need <= 40; need++) {
                long aprod = 1L * n1 * n2;
                long cprod = 1;
                for (int j = n - 1; j >= n - need; j--) {
                    cprod *= z[j];
                }
                if (cprod < aprod) continue;
                if (n1 <= 1 && cprod >= n2) return need;
                cgen++;
                can[1] = cgen;
                for (int k = n - 1; k >= n - need; k--) {
                    for (int r = n1 - 1; r >= 1; r--) {
                        if (can[r] == cgen) {
                            if (1L * r * z[k] < n1) {
                                can[r * z[k]] = cgen;
                            } else {
                                if (cprod / (r * z[k]) >= n2) {
                                    return need;
                                }
                            }
                        }
                    }
                }
            }
            return n + 1;
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

    static class AUtils {
        public static void sort(int[] arr) {
            for (int i = 1; i < arr.length; i++) {
                int j = (int) (Math.random() * (i + 1));
                if (i != j) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
            Arrays.sort(arr);
        }

    }
}