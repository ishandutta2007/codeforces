import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.File;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Comparator;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        List<Integer>[] graph;
        int[] a;
        int[] b;
        long[] ans;
        CHT[] cvx;

        void dfs(int node, int par) {
            cvx[node] = new CHT(CHT.MIN);
            for (int next : graph[node]) {
                if (next == par) continue;
                dfs(next, node);
            }

            int big = 0, bidx = -1;
            for (int next : graph[node]) {
                if (next == par) continue;
                if (cvx[next].size() > big) {
                    big = cvx[next].size();
                    bidx = next;
                }
            }

            if (bidx == -1) {
                ans[node] = 0;
                cvx[node].add(b[node], 0);
                return;
            }

            cvx[node] = cvx[bidx];
            for (int next : graph[node]) {
                if (next == par || next == bidx) continue;
                for (CHT.Line l : cvx[next].hull) {
                    cvx[node].add(l);
                }
            }

            Debug.print(node, cvx[node].size(), cvx[node].hull);
            ans[node] = cvx[node].query(a[node]);
            cvx[node].add(b[node], ans[node]);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            a = in.readIntArray(n);
            b = in.readIntArray(n);
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }
            ans = new long[n];
            cvx = new CHT[n];
            dfs(0, -1);
            out.println(ans);
        }

    }

    static class CHT {
        public static final int MIN = -1;
        public TreeSet<CHT.Line> hull;
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
            hull = new TreeSet<>(comp);
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

        public long query(long x) {
            CHT.Line temp = new CHT.Line(0, 0, 0);
            temp.left = x;
            query = true;
            Debug.print(x, temp, hull.floor(temp));
            long ans = hull.floor(temp).eval(x);
            query = false;
            return ans;
        }

        private void remove(CHT.Line x) {
            hull.remove(x);
        }

        public int size() {
            return hull.size();
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

            public long eval(long x) {
                return m * x + b;
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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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
}