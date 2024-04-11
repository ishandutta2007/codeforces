import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.stream.Stream;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

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
        long[] want;
        List<TaskD.Edge>[] graph;
        public OutputWriter out;
        public long[] ret;
        public int[] color;
        public boolean bipartite;
        public boolean[] vis;

        public void solve(int testNumber, InputReader in, OutputWriter _out) {
            out = _out;
            int n = in.nextInt(), m = in.nextInt();
            want = in.readLongArray(n);
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(new TaskD.Edge(b, i));
                graph[b].add(new TaskD.Edge(a, i));
            }

            bipartite = true;
            color = new int[n];
            vis = new boolean[n];
            dfs(0, -1, 0);
            long s1 = 0, s2 = 0;
            for (int i = 0; i < n; i++) {
                if (color[i] == 0) s1 += want[i];
                else s2 += want[i];
            }

            ret = new long[m];
            if (s1 != s2) {
                boolean fixed = false;
                outer:
                for (int i = 0; i < n; i++) {
                    for (TaskD.Edge e : graph[i]) {
                        if (color[i] == color[e.to]) {
                            if (color[i] == 0) ret[e.idx] += (s1 - s2) / 2;
                            else ret[e.idx] += (s2 - s1) / 2;
                            want[i] -= ret[e.idx];
                            want[e.to] -= ret[e.idx];
                            fixed = true;
                            break outer;
                        }
                    }
                }
                if (!fixed) {
                    out.println("NO");
                    return;
                }
            }
            vis = new boolean[n];
            dfs2(0, -1, -1);

            out.println("YES");
            for (long x : ret) out.println(x);
        }

        public void dfs2(int node, int par, int pedge) {
            vis[node] = true;
            for (TaskD.Edge next : graph[node]) {
                if (vis[next.to]) continue;
                dfs2(next.to, node, next.idx);
            }
            if (want[node] != 0) {
                long add = want[node];
                ret[pedge] += add;
                want[par] -= add;
                want[node] -= add;
            }
        }

        public void dfs(int node, int par, int c) {
            if (vis[node]) {
                return;
            }
            vis[node] = true;
            color[node] = c;
            for (TaskD.Edge next : graph[node]) {
                if (next.to == par) continue;
                dfs(next.to, node, 1 - c);
            }
        }

        static class Edge {
            public int to;
            public int idx;

            public Edge(int to, int idx) {
                this.to = to;
                this.idx = idx;
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

        public long[] readLongArray(int tokens) {
            long[] ret = new long[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextLong();
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

        public void println(long i) {
            writer.println(i);
        }

    }
}