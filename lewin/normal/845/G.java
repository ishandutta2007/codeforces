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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public List<TaskG.Edge>[] graph;
        public int n;
        public int[] basis;
        public int bidx;
        public boolean[] vis;
        public int[] xor;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            int m = in.nextInt();
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, c = in.nextInt();
                graph[a].add(new TaskG.Edge(b, c));
                graph[b].add(new TaskG.Edge(a, c));
            }
            xor = new int[n];
            vis = new boolean[n];
            vis[0] = true;
            basis = new int[32];
            bidx = 0;
            dfs(0);
            int bb = xor[0] ^ xor[n - 1];
            for (int i = bidx - 1; i >= 0; i--) {
                bb = Math.min(bb, bb ^ basis[i]);
            }
            out.println(bb);
        }

        public void add(int num) {
            for (int i = bidx - 1; i >= 0; i--) {
                num = Math.min(num, num ^ basis[i]);
            }
            if (num > 0) {
                basis[bidx++] = num;
                Arrays.sort(basis, 0, bidx);
            }
        }

        public void dfs(int node) {
            for (TaskG.Edge next : graph[node]) {
                if (vis[next.to]) {
                    add(xor[node] ^ xor[next.to] ^ next.weight);
                    continue;
                }
                vis[next.to] = true;
                xor[next.to] = xor[node] ^ next.weight;
                dfs(next.to);
            }
        }

        static class Edge {
            public int to;
            public int weight;

            public Edge(int to, int weight) {
                this.to = to;
                this.weight = weight;
            }

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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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
}