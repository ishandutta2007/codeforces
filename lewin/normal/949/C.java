import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Stack;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.util.Vector;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int n;
        int m;
        int h;
        int[] u;
        List<Integer>[] graph;
        List<Integer>[] force;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            h = in.nextInt();
            u = in.readIntArray(n);

            graph = LUtils.genArrayList(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }

            force = LUtils.genArrayList(n);
            for (int i = 0; i < n; i++) {
                for (int e : graph[i]) {
                    if ((u[e] + 1) % h == u[i]) {
                        force[e].add(i);
                    }
                    if ((u[i] + 1) % h == u[e]) {
                        force[i].add(e);
                    }
                }
            }
            List<List<Integer>> tt = new SCCTarjan().scc(force);
            List<Integer> best = new ArrayList<>();
            for (int i = 0; i < n; i++) best.add(i);
            int[] comp = new int[n];
            int cidx = 0;
            for (List<Integer> r : tt) {
                if (r.size() >= best.size()) continue;
                cidx++;
                for (int k : r) comp[k] = cidx;
                boolean ok = true;
                for (int k : r) {
                    for (int e : force[k]) {
                        if (comp[e] != cidx) {
                            ok = false;
                        }
                    }
                }
                if (ok) best = r;
            }
            out.println(best.size());
            boolean first = true;
            for (int k : best) {
                if (!first) out.print(" ");
                out.print(k + 1);
                first = false;
            }
            out.println();

        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }

    static class SCCTarjan {
        List<Integer>[] graph;
        boolean[] visited;
        Stack<Integer> stack;
        int time;
        int[] lowlink;
        List<List<Integer>> components;

        public List<List<Integer>> scc(List<Integer>[] graph) {
            int n = graph.length;
            this.graph = graph;
            visited = new boolean[n];
            stack = new Stack<>();
            time = 0;
            lowlink = new int[n];
            components = new ArrayList<>();

            for (int u = 0; u < n; u++)
                if (!visited[u])
                    dfs(u);

            return components;
        }

        void dfs(int u) {
            lowlink[u] = time++;
            visited[u] = true;
            stack.add(u);
            boolean isComponentRoot = true;

            for (int v : graph[u]) {
                if (!visited[v])
                    dfs(v);
                if (lowlink[u] > lowlink[v]) {
                    lowlink[u] = lowlink[v];
                    isComponentRoot = false;
                }
            }

            if (isComponentRoot) {
                List<Integer> component = new ArrayList<>();
                while (true) {
                    int x = stack.pop();
                    component.add(x);
                    lowlink[x] = Integer.MAX_VALUE;
                    if (x == u)
                        break;
                }
                components.add(component);
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

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}