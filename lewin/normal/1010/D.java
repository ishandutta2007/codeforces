import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        DMarsRover solver = new DMarsRover();
        solver.solve(1, in, out);
        out.close();
    }

    static class DMarsRover {
        int[][] child;
        int[] type;
        int[] value;
        final int AND = 10;
        final int OR = 20;
        final int XOR = 30;
        final int NOT = 40;
        final int IN = 50;
        int[] p;

        int combine(int type, int b1, int b2) {
            switch (type) {
                case AND:
                    return b1 & b2;
                case OR:
                    return b1 | b2;
                case XOR:
                    return b1 ^ b2;
            }
            throw new RuntimeException();
        }

        int dfs(int node) {
            if (type[node] == IN) {
                return value[node];
            }
            if (type[node] == NOT) {
                DisjointSets.unite(p, child[node][0], node);
                return 1 - dfs(child[node][0]);
            } else {
                int x1 = dfs(child[node][0]), x2 = dfs(child[node][1]);
                int res = combine(type[node], x1, x2);
                if (res != combine(type[node], 1 - x1, x2)) DisjointSets.unite(p, child[node][0], node);
                if (res != combine(type[node], x1, 1 - x2)) DisjointSets.unite(p, child[node][1], node);
                return res;
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            child = new int[n][2];
            type = new int[n];
            value = new int[n];
            p = DisjointSets.createSets(n);
            for (int i = 0; i < n; i++) {
                String s = in.next();
                switch (s) {
                    case "AND":
                        type[i] = AND;
                        child[i][0] = in.nextInt() - 1;
                        child[i][1] = in.nextInt() - 1;
                        break;
                    case "OR":
                        type[i] = OR;
                        child[i][0] = in.nextInt() - 1;
                        child[i][1] = in.nextInt() - 1;
                        break;
                    case "XOR":
                        type[i] = XOR;
                        child[i][0] = in.nextInt() - 1;
                        child[i][1] = in.nextInt() - 1;
                        break;
                    case "NOT":
                        type[i] = NOT;
                        child[i][0] = in.nextInt() - 1;
                        child[i][1] = -1;
                        break;
                    case "IN":
                        type[i] = IN;
                        value[i] = in.nextInt();
                        child[i][0] = child[i][1] = -1;
                        break;
                }
            }
            int ans = dfs(0);
            int rt = DisjointSets.root(p, 0);
            for (int i = 0; i < n; i++) {
                if (type[i] == IN) {
                    out.print(DisjointSets.root(p, i) == rt ? (1 - ans) : ans);
                }
            }
            out.println();

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

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
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

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
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
}