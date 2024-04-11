import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.File;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.FileReader;
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
        public int mod = 1000000007;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt();

            int[][] comb = Utils.getComb(k + 10, mod);
            long[] pow = new long[k + 10];
            for (int i = 1; i < pow.length; i++) {
                pow[i] = Utils.mod_exp(i, k, mod);
            }
            long[] poly = new long[k + 1];
            long start = System.currentTimeMillis();
            for (int i = 1; i <= poly.length; i++) {
                for (int j = 1; j <= i; j++) {
                    poly[i - 1] = (poly[i - 1] + 1L * comb[i][j] * pow[j]) % mod;
                }
                poly[i - 1] = poly[i - 1] * Utils.inv(Utils.mod_exp(2, i - 1, mod), mod) % mod;
            }
            Debug.print(System.currentTimeMillis() - start);

            poly = Polynomial.interpolation(poly, mod);
            Debug.print(System.currentTimeMillis() - start);
            long res = 0;
            for (int i = poly.length - 1; i >= 0; i--) {
                res = (res * (n - 1) + poly[i]) % mod;
            }
            out.println(res * Utils.mod_exp(2, n - 1, mod) % mod);
        }

    }

    static class Polynomial {
        public static long[] interpolation(long[] y, int mod) {
            int n = y.length;
            long[] a = new long[n], b = new long[n];
            a[0] = y[0];
            b[0] = 1;
            long[] inv = new long[n + 1];
            inv[1] = 1;
            for (int i = 2; i <= n; i++) {
                inv[i] = (mod - mod / i) * inv[mod % i] % mod;
            }
            for (int i = 1; i < n; i++) {
                for (int j = 0; j + i < n; j++) y[j] = (y[j + 1] - y[j] + mod) % mod * inv[i] % mod;
                for (int j = i; j > 0; j--) b[j] = (b[j - 1] + (mod - i + 1) * b[j]) % mod;
                b[0] = b[0] * (mod - i + 1) % mod;
                for (int j = 0; j <= i; j++) {
                    a[j] = (a[j] + b[j] * y[0]) % mod;
                }
            }
            return a;
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }

    static class Debug {
        public static boolean DEBUG;

        static {
            try {
                DEBUG = System.getProperty("user.dir").contains("Dropbox");
            } catch (Exception e) {
                DEBUG = false;
            }
        }

        private static ArrayList<String> getParams() {
            StackTraceElement[] t = new Exception().getStackTrace();
            StackTraceElement up = t[2];

            ArrayList<String> ret = new ArrayList<>();
            ret.add(up.getFileName() + "/" + up.getMethodName());
            try {
                BufferedReader br = new BufferedReader(new FileReader(
                        new File("src/" + up.getClassName().replaceAll("\\.", "/") + ".java")));
                int g = up.getLineNumber();
                while (--g > 0) br.readLine();
                String q = br.readLine();
                String[] ss = q.split("Debug\\.print\\(");
                String[] qq = ss[1].substring(0, ss[1].indexOf(")")).split(",");
                for (int i = 0; i < qq.length; i++) {
                    ret.add(qq[i].trim());
                }
            } catch (Exception e) {
            }
            for (int i = 0; i < 100; i++) ret.add("???");
            return ret;
        }

        private static String toString(Object o) {
            if (o instanceof Object[]) {
                return Arrays.toString((Object[]) o);
            } else if (o instanceof char[]) {
                return new String((char[]) o);
            } else if (o instanceof int[]) {
                return Arrays.toString((int[]) o);
            } else if (o instanceof long[]) {
                return Arrays.toString((long[]) o);
            } else if (o instanceof double[]) {
                return Arrays.toString((double[]) o);
            } else {
                return o.toString();
            }
        }

        public static void print(Object x) {
            if (!DEBUG) return;
            ArrayList<String> s = getParams();
            System.out.println(s.get(0) + ": " + s.get(1) + " = " + toString(x));
        }

    }

    static class Utils {
        public static long inv(long N, long M) {
            long x = 0, lastx = 1, y = 1, lasty = 0, q, t, a = N, b = M;
            while (b != 0) {
                q = a / b;
                t = a % b;
                a = b;
                b = t;
                t = x;
                x = lastx - q * x;
                lastx = t;
                t = y;
                y = lasty - q * y;
                lasty = t;
            }
            return (lastx + M) % M;
        }

        public static long mod_exp(long b, long e, long mod) {
            long res = 1;
            while (e > 0) {
                if ((e & 1) == 1)
                    res = (res * b) % mod;
                b = (b * b) % mod;
                e >>= 1;
            }
            return res;
        }

        public static int[][] getComb(int sz, int mod) {
            int[][] comb = new int[sz][sz];
            for (int i = 0; i < sz; i++) {
                comb[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                    comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
                    if (comb[i][j] >= mod) comb[i][j] -= mod;
                }
            }
            return comb;
        }

    }
}