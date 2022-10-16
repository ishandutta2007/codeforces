import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
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
 *
 * @author lewin
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
        int n;
        long[] w;
        long[] h;
        long[] c;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            HashSet<Long> ws = new HashSet<>();
            HashSet<Long> hs = new HashSet<>();
            w = new long[n];
            h = new long[n];
            c = new long[n];
            for (int i = 0; i < n; i++) {
                w[i] = in.nextLong();
                h[i] = in.nextLong();
                c[i] = in.nextLong();
                ws.add(w[i]);
                hs.add(h[i]);
            }
            int a1 = ws.size(), a2 = hs.size();
            if (1L * a1 * a2 != n) {
                out.println(0);
                return;
            }
            ArrayList<Long> ww = new ArrayList<>(ws), hh = new ArrayList<>(hs);
            Collections.sort(ww);
            Collections.sort(hh);
            long[][] need = new long[a1][a2];
            for (int i = 0; i < n; i++) {
                int x1 = Collections.binarySearch(ww, w[i]);
                int x2 = Collections.binarySearch(hh, h[i]);
                need[x1][x2] = c[i];
            }

            long[] a = new long[a1];
            long[] b = new long[a2];
            for (int i = 0; i < a1; i++) {
                for (int j = 0; j < a2; j++) {
                    a[i] = Utils.gcd(a[i], need[i][j]);
                    b[j] = Utils.gcd(b[j], need[i][j]);
                }
            }
            for (int i = 0; i < a1; i++) {
                long r = need[i][0] / b[0];
                if (a[i] % r != 0) {
                    out.println(0);
                    return;
                }
                a[i] = r;
            }
            for (int j = 0; j < a2; j++) {
                long r = need[0][j] / a[0];
                if (b[j] % r != 0) {
                    out.println(0);
                    return;
                }
                b[j] = r;
            }
            for (int i = 0; i < a1; i++) {
                for (int j = 0; j < a2; j++) {
                    if (need[i][j] % b[j] != 0 && need[i][j] / b[j] != a[i]) {
                        out.println(0);
                        return;
                    }
                }
            }

            long g1 = 0;
            for (long k : a) g1 = Utils.gcd(g1, k);
            long g2 = 0;
            for (long k : b) g2 = Utils.gcd(g2, k);
            out.println(countdiv(g1 * g2));
        }

        long countdiv(long r) {
            int res = 0;
            for (long i = 1; i * i <= r; i++) {
                if (r % i == 0) {
                    res++;
                    if (r / i != i) res++;
                }
            }
            return res;
        }

    }

    static class Utils {
        public static long gcd(long x, long y) {
            for (; x != 0; x ^= y, y ^= x, x ^= y, x %= y) ;
            return y;
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

        public void println(int i) {
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