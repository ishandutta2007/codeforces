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
import java.util.Collections;
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
        public int mod = 1000000007;
        public long inv6 = Utils.inv(6, mod);
        public long inv60 = Utils.inv(60, mod);

        public long sum2(long from, long to, long X, long a) {
            long ret = inv6;
            ret = ret * (from - to - 1 + mod) % mod;
            long a1 = 2 * from * from % mod - from + to + 2 * to * to % mod + 2 * from * to % mod;
            a1 %= mod;
            if (a1 < 0) a1 += mod;
            a1 = a1 * a % mod;
            a1 = a1 - 3 * X * (from + to) % mod;
            a1 %= mod;
            if (a1 < 0) a1 += mod;
            return ret * a1 % mod;

        }

        public long sum1(long from, long to, long m, long a) {
            long ret = inv60;
            ret = ret * a % mod * (a + 1) % mod * (2 * a + 1) % mod * (from - to - 1 + mod) % mod;
            long inner = 6 * a * a % mod + 6 * a % mod + 5 * from % mod - 10 * m % mod + 5 * to % mod - 12;
            inner %= mod;
            if (inner < 0) inner += mod;
            return ret * inner % mod;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long m = in.nextLong();
            long mm = m % mod;
            long base = mm * (mm + 1) % mod * (mm + 2) % mod * inv6 % mod;
            ArrayList<Long> a1 = new ArrayList<>();
            ArrayList<Long> a2 = new ArrayList<>();
            long sk = 0, sa = 0;
            for (int k = 1; 1L * k * k <= m; k++) {
                a1.add(1L * k * k);
                a2.add(m - 1L * k * k + 1);
                sa++;
                sk = (sk + 1L * k * k) % mod;
            }
            a1.add(m + 1);
            Collections.reverse(a2);
            long start = System.currentTimeMillis();
            ArrayList<Long> ss = new ArrayList<>();
            int i1 = 0, i2 = 0;
            while (i1 < a1.size() && i2 < a2.size()) {
                if (a1.get(i1) < a2.get(i2)) ss.add(a1.get(i1++));
                else ss.add(a2.get(i2++));
            }
            while (i1 < a1.size()) ss.add(a1.get(i1++));
            while (i2 < a2.size()) ss.add(a2.get(i2++));
            Collections.sort(ss);
            Debug.print(System.currentTimeMillis() - start);

            long sqrtval = 1;
            long ans = 0;
            for (int i = 0; i < ss.size() - 1; i++) {
                long from = ss.get(i), to = ss.get(i + 1) - 1;
                if (from > to) continue;

                while ((sqrtval + 1) * (sqrtval + 1) <= to) sqrtval++;
                while ((m - sa * sa) < to) {
                    sk = (sk - sa * sa) % mod;
                    if (sk < 0) sk += mod;
                    sa--;
                }
                from %= mod;
                to %= mod;
                long X = (sa + 1) * (mm + 1) % mod - sk;
                if (X < 0) X += mod;
                long add = sum1(from, to, mm, sa) + sum2(from, to, X, sa + 1);
                add = add * sqrtval % mod;
                add %= mod;
                ans = (ans + add) % mod;

            }
//        for (int n = 1; n <= m; n++) {
//            for (int k = 0; k * k <= n; k++) {
//                ans += (int)(Math.sqrt(n-k*k)) * n * (m - n + 1);
//            }
//        }
            ans *= 4;
            ans += base;
            out.println(ans % mod);
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