import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        CU2 solver = new CU2();
        solver.solve(1, in, out);
        out.close();
    }

    static class CU2 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            CHT cht = new CHT(CHT.MIN);
            for (int i = 0; i < n; i++) {
                long x = 2 * in.nextLong(), y = 2 * in.nextLong();
                cht.add(-2 * x, x * x - 2 * y);
            }
            out.println(cht.hull.size() - 1);
//        Point[] ps = new Point[n+2];
//        long INF = 1_000_000_000L;
//        long min = INF, max = -INF;
//        for (int i = 0; i < n; i++) {
//            long x = in.nextLong(), y = in.nextLong();
//            min = Math.min(min, x);
//            max = Math.max(max, x);
//            ps[i] = new Point(x,y*y);
//        }
//        if (min == max) {
//            out.println(0);
//            return;
//        }
//        ps[n] = new Point(min, -INF);
//        ps[n+1] = new Point(max, -INF);
//        out.println(convexHull2(ps).length-3);
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

    static class CHT {
        public static final int MIN = -1;
        public final TreeSet<CHT.Line> hull;
        int type;
        boolean query = false;
        Comparator<CHT.Line> comp = new Comparator<CHT.Line>() {
            public int compare(CHT.Line a, CHT.Line b) {
                if (!query) return type * Long.compare(a.m, b.m);
                if (a.left == b.left)
                    return Long.compare(a.m, b.m);
                return Double.compare(a.left, b.left);
            }
        };

        public CHT(final int type) {
            this.type = type;
            this.hull = new TreeSet<>(comp);
        }

        public void add(long m, long b) {
            add(new CHT.Line(m, b));
        }

        public void add(CHT.Line a) {
            CHT.Line[] LR = {hull.lower(a), hull.ceiling(a)};
            for (int i = 0; i < 2; i++)
                if (LR[i] != null && LR[i].m == a.m) {
                    if (type == 1 && LR[i].b >= a.b)
                        return;
                    if (type == -1 && LR[i].b <= a.b)
                        return;
                    remove(LR[i]);
                }

            hull.add(a);
            CHT.Line L = hull.lower(a), R = hull.higher(a);
            if (L != null && R != null && a.inter(R) <= R.left) {
                hull.remove(a);
                return;
            }
            CHT.Line LL = (L != null) ? hull.lower(L) : null;
            CHT.Line RR = (R != null) ? hull.higher(R) : null;
            if (L != null) a.left = a.inter(L);
            if (R != null) R.left = a.inter(R);
            while (LL != null && L.left >= a.inter(LL)) {
                remove(L);
                a.left = a.inter(L = LL);
                LL = hull.lower(L);
            }
            while (RR != null && R.inter(RR) <= a.inter(RR)) {
                remove(R);
                RR.left = a.inter(R = RR);
                RR = hull.higher(R);
            }
        }

        private void remove(CHT.Line x) {
            hull.remove(x);
        }

        public static class Line {
            long m;
            long b;
            double left = Long.MIN_VALUE;

            public Line(long m, long x, long y) {
                this.m = m;
                this.b = -m * x + y;
            }

            public Line(long m, long b) {
                this.m = m;
                this.b = b;
            }

            public double inter(CHT.Line x) {
                return (double) (x.b - this.b) / (double) (this.m - x.m);
            }

            public String toString() {
                return "Line{" +
                        "m=" + m +
                        ", b=" + b +
                        ", left=" + left +
                        '}';
            }

        }

    }
}