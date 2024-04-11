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
        public int n;
        public int[][] child;
        public int[] val;
        public HashSet<Integer> good;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            val = new int[n];
            child = new int[n][2];
            int[] indeg = new int[n];
            for (int i = 0; i < n; i++) {
                val[i] = in.nextInt();
                child[i][0] = in.nextInt() - 1;
                child[i][1] = in.nextInt() - 1;
                if (child[i][0] != -2) indeg[child[i][0]]++;
                if (child[i][1] != -2) indeg[child[i][1]]++;
            }
            int root = -1;
            for (int i = 0; i < n; i++) {
                if (indeg[i] == 0) {
                    root = i;
                }
            }

            good = new HashSet<>();
            dfs(root, 0, 1000000000);
            int ans = 0;
            for (int v : val) if (!good.contains(v)) ans++;
            out.println(ans);
        }

        public void dfs(int root, int low, int high) {
            if (val[root] >= low && val[root] <= high) good.add(val[root]);
            if (child[root][0] != -2) {
                dfs(child[root][0], low, Math.min(high, val[root] - 1));
            }
            if (child[root][1] != -2) {
                dfs(child[root][1], Math.max(low, val[root] + 1), high);
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
}