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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public int[] color;
        public int[][] sw;
        public int[] idx;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            color = in.readIntArray(n);
            sw = new int[n][2];
            idx = new int[n];
            for (int i = 0; i < m; i++) {
                int d = in.nextInt();
                for (int j = 0; j < d; j++) {
                    int w = in.nextInt() - 1;
                    sw[w][idx[w]++] = i;
                }
            }
            ArrayList<Integer>[] graph = new ArrayList[2 * m];
            for (int i = 0; i < 2 * m; i++) {
                graph[i] = new ArrayList<>();
            }

            for (int i = 0; i < n; i++) {
                int a1 = sw[i][0], a2 = sw[i][1];
                if (color[i] == 1) {
                    graph[a1].add(a2);
                    graph[a2 + m].add(a1 + m);
                    graph[a2].add(a1);
                    graph[a1 + m].add(a2 + m);
                } else {
                    graph[a1].add(a2 + m);
                    graph[a2].add(a1 + m);
                    graph[a1 + m].add(a2);
                    graph[a2 + m].add(a1);
                }
            }

            boolean[] x = TwoSat.solve2Sat(graph);
            out.println(x == null ? "NO" : "YES");
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

    }

    static class TwoSat {
        static void dfs1(List<Integer>[] graph, boolean[] used, List<Integer> order, int u) {
            used[u] = true;
            for (int v : graph[u])
                if (!used[v])
                    dfs1(graph, used, order, v);
            order.add(u);
        }

        static void dfs2(List<Integer>[] reverseGraph, int[] comp, int u, int color) {
            comp[u] = color;
            for (int v : reverseGraph[u])
                if (comp[v] == -1)
                    dfs2(reverseGraph, comp, v, color);
        }

        public static boolean[] solve2Sat(List<Integer>[] graph) {
            int n = graph.length;
            boolean[] used = new boolean[n];
            List<Integer> order = new ArrayList<>();
            for (int i = 0; i < n; ++i)
                if (!used[i])
                    dfs1(graph, used, order, i);

            List<Integer>[] reverseGraph = new List[n];
            for (int i = 0; i < n; i++)
                reverseGraph[i] = new ArrayList<>();
            for (int i = 0; i < n; i++)
                for (int j : graph[i])
                    reverseGraph[j].add(i);

            int[] comp = new int[n];
            Arrays.fill(comp, -1);
            for (int i = 0, color = 0; i < n; ++i) {
                int u = order.get(n - i - 1);
                if (comp[u] == -1)
                    dfs2(reverseGraph, comp, u, color++);
            }

            for (int i = 0; i < n / 2; ++i)
                if (comp[i] == comp[i + n / 2])
                    return null;

            boolean[] res = new boolean[n / 2];
            for (int i = 0; i < n / 2; i++)
                res[i] = comp[i] > comp[i + n / 2];
            return res;
        }

    }
}