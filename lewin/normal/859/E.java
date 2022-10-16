import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public List<Integer>[] graph;
        public List<Integer>[] g2;
        public int[] next;
        public int mod = 1000000007;
        public boolean[] mark;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            next = new int[2 * n];
            Arrays.fill(next, -1);

            graph = LUtils.genArrayList(2 * n);
            g2 = LUtils.genArrayList(2 * n);
            int[] indeg = new int[2 * n];
            for (int i = 0; i < n; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                next[a] = b;
                graph[b].add(a);
                g2[b].add(a);
                g2[a].add(b);
                indeg[b]++;
            }

            mark = new boolean[2 * n];
            long ways = 1;
            for (int i = 0; i < 2 * n; i++) {
                if (next[i] == -1) {
                    ways = ways * dfs(i) % mod;
                } else if (next[i] == i) {
                    for (int child : graph[i]) {
                        if (child != i)
                            dfs(child);
                    }
                }
            }

            for (int i = 0; i < 2 * n; i++) {
                if (!mark[i]) {
                    if (dfs2(i) > 1) {
                        ways = ways * 2 % mod;
                    }
                }
            }
            out.println(ways);
        }

        public int dfs(int node) {
            mark[node] = true;
            int r = 1;
            for (int child : graph[node]) r += dfs(child);
            return r;
        }

        public int dfs2(int node) {
            if (mark[node]) return 0;
            mark[node] = true;
            int r = 1;
            for (int child : g2[node]) if (!mark[child]) r += dfs2(child);
            return r;
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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}