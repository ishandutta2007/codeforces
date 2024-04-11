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
        public boolean[] hascyc;
        public int[] p;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            TaskF.Edge[] es = new TaskF.Edge[m];
            for (int i = 0; i < m; i++) {
                es[i] = new TaskF.Edge(in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
            }
            Arrays.sort(es, Comparator.comparingInt(x -> x.c));

            long cost = 0;
            hascyc = new boolean[n];
            p = DisjointSets.createSets(n);
            for (int i = m - 1; i >= 0; i--) {
                if (canAdd(es[i])) {
                    cost += es[i].c;
                }
            }

            out.println(cost);
        }

        public boolean canAdd(TaskF.Edge e) {
            int a = e.a, b = e.b;
            int x1 = DisjointSets.root(p, a), x2 = DisjointSets.root(p, b);
            if (x1 != x2 && (!hascyc[x1] || !hascyc[x2])) {
                DisjointSets.unite(p, a, b);
                hascyc[DisjointSets.root(p, a)] |= hascyc[x1] || hascyc[x2];
                return true;
            } else {
                if (hascyc[x1]) {
                    return false;
                }

                hascyc[x1] = true;
                return true;
            }
        }

        static class Edge {
            public int a;
            public int b;
            public int c;

            public Edge(int a, int b, int c) {
                this.a = a;
                this.b = b;
                this.c = c;
            }

        }

    }

    static class DisjointSets {
        public static int[] createSets(int size) {
            int[] p = new int[size];
            for (int i = 0; i < size; i++)
                p[i] = i;
            return p;
        }

        public static int root(int[] p, int x) {
            return x == p[x] ? x : (p[x] = root(p, p[x]));
        }

        public static boolean unite(int[] p, int a, int b) {
            a = root(p, a);
            b = root(p, b);
            if (a != b) {
                if (Math.random() < 0.5)
                    p[a] = b;
                else
                    p[b] = a;
                return true;
            }
            return false;
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
}