import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public List<TaskD.Edge>[] graph;
        public List<TaskD.Path> res;
        public boolean[] vis;
        public boolean[] pp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(new TaskD.Edge(b, i));
                graph[b].add(new TaskD.Edge(a, i));
            }

            res = new ArrayList<>();
            vis = new boolean[n];
            pp = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    dfs(i);
                }
            }

            out.println(res.size());
            for (TaskD.Path p : res) {
                out.printf("%d %d %d\n", p.a + 1, p.b + 1, p.c + 1);
            }
        }

        public int dfs(int node) {
            if (vis[node]) return -1;
            pp[node] = true;
            vis[node] = true;
            int unmatched = -1;
            for (TaskD.Edge e : graph[node]) {
                if (pp[e.to]) continue;
                int x = dfs(e.to);
                if (x != -1) {
                    res.add(new TaskD.Path(node, e.to, x));
                } else if (unmatched != -1) {
                    res.add(new TaskD.Path(unmatched, node, e.to));
                    unmatched = -1;
                } else {
                    unmatched = e.to;
                }
            }
            pp[node] = false;
            return unmatched;
        }

        static class Edge {
            public int to;
            public int idx;

            public Edge(int to, int idx) {
                this.to = to;
                this.idx = idx;
            }

        }

        static class Path {
            public int a;
            public int b;
            public int c;

            public Path(int a, int b, int c) {
                this.a = a;
                this.b = b;
                this.c = c;
            }

        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}