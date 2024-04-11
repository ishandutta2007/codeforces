import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.stream.LongStream;
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
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CConstructATree solver = new CConstructATree();
        solver.solve(1, in, out);
        out.close();
    }

    static class CConstructATree {
        int[] par;
        int cidx = 1;

        long minsum(int n, int branch) {
            long minsum = 1;
            int spots = 1;
            int nodesleft = n - 1;
            long cdepth = 2;
            while (nodesleft > 0) {
                spots = (int) Math.min(1L * spots * branch, nodesleft);
                minsum += cdepth * spots;
                nodesleft -= spots;
                cdepth++;
            }
            return minsum;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            long s = in.nextLong();
            if (s < minsum(n, n - 1) || s > minsum(n, 1)) {
                out.println("No");
                return;
            }
            int lo = 1, hi = n - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (s < minsum(n, mid)) lo = mid + 1;
                else hi = mid;
            }
            par = new int[n];
            if (lo == 1) {
                for (int i = 1; i < n; i++) {
                    par[i] = i - 1;
                }
            } else {
                construct(n, lo, s);
            }
            long[] d = new long[n];
            d[0] = 1;
            for (int i = 1; i < n; i++) {
                d[i] = d[par[i]] + 1;
            }
            if (AUtils.sum(d) != s) {
                Debug.print(AUtils.sum(d), s);
                throw new RuntimeException();
            }

            out.println("Yes");
            for (int i = 1; i < n; i++) {
                if (i != 1) out.print(" ");
                out.print(par[i] + 1);
            }
            out.println();
        }

        void construct(int nodes, int b, long wantsum) {
            int plevel = 1;
            int cp = 0;
            wantsum -= nodes;
            nodes -= 1;
            while (nodes > 0) {
                for (int take = 1; take <= nodes && take <= 1L * plevel * b; take++) {
                    if (sum(nodes, b, take) <= wantsum) {
                        wantsum -= nodes;
                        nodes -= take;
                        int c = 0;
                        int first = cidx;
                        for (int j = 0; j < take; j++) {
                            par[cidx++] = cp;
                            if (++c == b) {
                                cp++;
                                c = 0;
                            }
                        }
                        cp = first;
                        plevel = take;
                        break;
                    }
                }
            }
            if (wantsum != 0) throw new RuntimeException();
        }

        long sum(int nodes, int branch, int spots) {
            long sum = spots;
            int nodesleft = nodes - spots;
            long cdepth = 2;
            while (nodesleft > 0) {
                spots = (int) Math.min(1L * spots * branch, nodesleft);
                sum += cdepth * spots;
                nodesleft -= spots;
                cdepth++;
            }
            return sum;

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

    static class AUtils {
        public static long sum(long[] arr) {
            return Arrays.stream(arr).reduce(0, Long::sum);
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
            StackTraceElement[] t = Thread.currentThread().getStackTrace();
            StackTraceElement up = t[3];

            ArrayList<String> ret = new ArrayList<>();
            String qqq = up.toString();
            ret.add("." + up.getMethodName() + qqq.substring(qqq.indexOf("("), qqq.length()));
            try {
                BufferedReader br = new BufferedReader(new FileReader(
                        new File("src/" + up.getClassName().replaceAll("\\.", "/") + ".java")));
                int g = up.getLineNumber();
                while (--g > 0) br.readLine();
                String q = br.readLine();
                String[] ss = q.split("Debug\\.print\\(");
                String[] qq = ss[1].substring(0, ss[1].lastIndexOf(")")).split(",");
                for (int i = 0; i < qq.length; i++) {
                    ret.add(qq[i].trim());
                }
            } catch (Exception e) {
            }
            for (int i = 0; i < 100; i++) ret.add("???");
            return ret;
        }

        private static String toString(Object o) {
            if (o == null) {
                return "null";
            } else if (o instanceof Object[]) {
                return Arrays.toString((Object[]) o);
            } else if (o instanceof char[]) {
                return new String((char[]) o);
            } else if (o instanceof int[]) {
                return Arrays.toString((int[]) o);
            } else if (o instanceof long[]) {
                return Arrays.toString((long[]) o);
            } else if (o instanceof double[]) {
                return Arrays.toString((double[]) o);
            } else if (o instanceof boolean[]) {
                return Arrays.toString((boolean[]) o);
            } else {
                return o.toString();
            }
        }

        public static void print(Object... x) {
            if (!DEBUG) return;
            ArrayList<String> s = getParams();
            System.out.print(s.get(0) + ": ");
            for (int i = 0; i < x.length; i++) {
                System.out.print(s.get(i + 1) + " = " + toString(x[i]));
                if (i != x.length - 1) System.out.print(", ");
            }
            System.out.println();
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println() {
            writer.println();
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

    }
}