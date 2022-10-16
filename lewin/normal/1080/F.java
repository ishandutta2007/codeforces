import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        FKatyaAndSegmentsSets solver = new FKatyaAndSegmentsSets();
        solver.solve(1, in, out);
        out.close();
    }

    static class FKatyaAndSegmentsSets {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            FKatyaAndSegmentsSets.Interval[] its = new FKatyaAndSegmentsSets.Interval[k];
            for (int i = 0; i < k; i++) {
                its[i] = new FKatyaAndSegmentsSets.Interval(in.nextInt(), in.nextInt(), in.nextInt() - 1);
            }
            Arrays.sort(its, Comparator.comparingInt(x -> x.from));

            PersistentSegmentTree pst = new PersistentSegmentTree(n);
            int[] rts = new int[k + 1];
            rts[k] = pst.empty;
            for (int i = k - 1; i >= 0; i--) {
                rts[i] = pst.modify(rts[i + 1], its[i].index, its[i].to);
            }

            while (m-- > 0) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, x = in.nextInt(), y = in.nextInt();

                int lo = 0, hi = rts.length - 1;
                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if (its[mid].from < x) lo = mid + 1;
                    else hi = mid;
                }

                out.println(pst.query(rts[lo], a, b) <= y ? "yes" : "no");
                out.flush();
            }
        }

        static class Interval {
            public int from;
            public int to;
            public int index;

            public Interval(int from, int to, int index) {
                this.from = from;
                this.to = to;
                this.index = index;
            }

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

    static class PersistentSegmentTree {
        public static int MAXNODES = 10000000;
        public int[] left;
        public int[] right;
        public int[] start;
        public int[] end;
        public int[] val;
        public int nidx;
        public int empty;

        public PersistentSegmentTree(int n) {
            left = new int[MAXNODES];
            right = new int[MAXNODES];
            start = new int[MAXNODES];
            end = new int[MAXNODES];
            val = new int[MAXNODES];
            nidx = 0;
            empty = init(0, n - 1);
        }

        public int createNode(int s, int e, int v) {
            start[nidx] = s;
            end[nidx] = e;
            left[nidx] = -1;
            right[nidx] = -1;
            val[nidx] = v;
            return nidx++;
        }

        public int init(int s, int e) {
            int root = createNode(s, e, 0);
            if (s != e) {
                int mid = (s + e) / 2;
                left[root] = init(s, mid);
                right[root] = init(mid + 1, e);
            }
            val[root] = Integer.MAX_VALUE;
            return root;
        }

        public int query(int root, int s, int e) {
            if (start[root] == s && end[root] == e) {
                return val[root];
            }
            int mid = (start[root] + end[root]) / 2;
            if (e <= mid) return query(left[root], s, e);
            else if (mid < s) return query(right[root], s, e);
            else {
                return Math.max(query(left[root], s, mid), query(right[root], mid + 1, e));
            }
        }

        public int modify(int root, int pos, int v) {
            if (pos == start[root] && pos == end[root]) {
                return createNode(start[root], end[root], Math.min(v, val[root]));
            }
            int mid = (start[root] + end[root]) / 2;
            int nroot = createNode(start[root], end[root], val[root]);
            left[nroot] = left[root];
            right[nroot] = right[root];
            if (pos <= mid) {
                left[nroot] = modify(left[root], pos, v);
            } else {
                right[nroot] = modify(right[root], pos, v);
            }
            val[nroot] = Math.max(val[left[nroot]], val[right[nroot]]);
            return nroot;
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

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
        }

    }
}