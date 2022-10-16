import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        public int[][] dp;
        public int[][] opt;
        public int[] arr;
        public HashMap<Pair<Integer, Integer>, Integer> pp;
        public TaskB.SegmentTree root;
        public static int[] seq;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            arr = new int[n + 1];
            for (int i = 1; i <= n; i++) arr[i] = in.nextInt();
            int[] next = new int[n + 1];
            Arrays.fill(next, n + 1);

            seq = new int[n + 1];
            for (int i = n; i >= 1; i--) {
                seq[i] = next[arr[i]];
                next[arr[i]] = i;
            }

            dp = new int[k + 1][n + 1];
            opt = new int[k + 1][n + 1];

            root = new TaskB.SegmentTree(1, n);
            pp = new HashMap<>();
            for (int i = 1; i <= k; i++) {
                compute(i, 1, n, 1, n);
            }
            out.println(dp[k][n]);
        }

        public void solveOne(int a, int b, int from, int to) {
            to = Math.min(to, b);
            if (to < from) return;
            int ee = cost(to + 1, b);
            int add = 0;
            for (int j = to; j >= from; j--) {
                if (j <= b && seq[j] > b) add++;
                int t = dp[a - 1][j - 1] + ee + add;
                if (t > dp[a][b]) {
                    dp[a][b] = t;
                    opt[a][b] = j;
                }
            }
        }

        public void compute(int d, int L, int R, int optL, int optR) {
            if (L > R) return;
            if (L == R) {
                solveOne(d, L, optL, optR);
                return;
            }
            optR = Math.min(optR, R);
            if (optL == optR) {
                for (int i = L; i <= R; i++) {
                    solveOne(d, i, optL, optR);
                }
                return;
            }

            int M = (L + R) / 2;
            solveOne(d, M, optL, optR);
            compute(d, L, M - 1, optL, opt[d][M]);
            compute(d, M + 1, R, opt[d][M], optR);
        }

        public int cost(int from, int to) {
            if (from > to) return 0;
            Pair<Integer, Integer> key = new Pair<>(from, to);
            Integer d = pp.get(key);
            if (d != null) return d;
            int res = root.query(from, to, to);
            pp.put(key, res);
            return res;
        }

        static class SegmentTree {
            public int[] arr;
            public int start;
            public int end;
            public TaskB.SegmentTree lchild;
            public TaskB.SegmentTree rchild;

            public SegmentTree(int start, int end) {
                this.start = start;
                this.end = end;
                arr = new int[end - start + 2];
                arr[0] = -1;
                if (start == end) {
                    arr[1] = seq[start];
                } else {
                    int mid = (start + end) >> 1;
                    lchild = new TaskB.SegmentTree(start, mid);
                    rchild = new TaskB.SegmentTree(mid + 1, end);
                    int lidx = 1, ridx = 1;

                    int idx = 1;
                    int[] larr = lchild.arr, rarr = rchild.arr;
                    while (lidx < larr.length && ridx < rarr.length) {
                        if (larr[lidx] < rarr[ridx]) {
                            arr[idx++] = larr[lidx++];
                        } else {
                            arr[idx++] = rarr[ridx++];
                        }
                    }
                    while (lidx < larr.length) {
                        arr[idx++] = larr[lidx++];
                    }
                    while (ridx < rarr.length) {
                        arr[idx++] = rarr[ridx++];
                    }
                }
            }

            public int query(int s, int e, int k) {
                if (start == s && end == e) {
                    int lo = 0, hi = arr.length;
                    while (lo < hi) {
                        int mid = (lo + hi) / 2;
                        if (arr[mid] <= k) lo = mid + 1;
                        else hi = mid;
                    }
                    return arr.length - lo;
                }
                int mid = (start + end) >> 1;
                if (mid >= e) return lchild.query(s, e, k);
                else if (mid < s) return rchild.query(s, e, k);
                else {
                    int x = lchild.query(s, mid, k);
                    x += rchild.query(mid + 1, e, k);
                    return x;
                }
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

    static class Pair<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<Pair<U, V>> {
        public final U u;
        public final V v;

        public Pair(U u, V v) {
            this.u = u;
            this.v = v;
        }

        public int hashCode() {
            return (u == null ? 0 : u.hashCode() * 31) + (v == null ? 0 : v.hashCode());
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<U, V> p = (Pair<U, V>) o;
            return (u == null ? p.u == null : u.equals(p.u)) && (v == null ? p.v == null : v.equals(p.v));
        }

        public int compareTo(Pair<U, V> b) {
            int cmpU = u.compareTo(b.u);
            return cmpU != 0 ? cmpU : v.compareTo(b.v);
        }

        public String toString() {
            return String.format("[Pair = (%s, %s)", u.toString(), v.toString());
        }

    }
}