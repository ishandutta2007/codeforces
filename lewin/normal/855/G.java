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
        public List<Integer>[] graph;
        public int n;
        public long ans;
        public int[] size;
        public int[] depth;
        public int[] par;
        public int[] down;
        public long[] mult;

        public int dfs1(int node, int p) {
            down[node] = 1;
            for (int next : graph[node]) {
                if (next == p) continue;
                depth[next] = depth[node] + 1;
                par[next] = node;
                dfs1(next, node);
                mult[node] += 2L * (down[node] - 1) * down[next];
                down[node] += down[next];
            }
            mult[node] += 2L * (down[node] - 1) * (n - down[node]);
            ans += 2L * down[node] * (n - down[node]);
            return down[node];
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }
            ans = 0;
            down = new int[n];
            depth = new int[n];
            par = new int[n];
            size = new int[n];
            mult = new long[n];
            Arrays.fill(size, 1);
            dfs1(0, -1);
            ans -= 1L * n * (n - 1);

            out.println(ans);
            int q = in.nextInt();
            int[] p = DisjointSets.createSets(n);
            while (q-- > 0) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                a = DisjointSets.root(p, a);
                b = DisjointSets.root(p, b);
                while (a != b) {
                    if (depth[a] < depth[b]) {
                        int t = a;
                        a = b;
                        b = t;
                    }

                    int m = DisjointSets.root(p, par[a]);

                    delete(m);
                    delete(a);

                    p[a] = m;
                    ans -= 2L * size[m] * size[a] * (n - size[a] - size[m]);
                    ans += size[a] * (mult[m] - 2L * down[a] * (n - size[m] - down[a]));
                    ans += size[m] * (mult[a] - 2L * (down[a] - size[a]) * (n - down[a]));
                    mult[m] -= 2L * size[a] * (n - down[a] - size[m]);
                    mult[m] += mult[a] - (2L * (down[a] - size[a]) * (n - down[a]));
                    size[m] += size[a];

                    add(m);
                    a = m;
                }
                out.println(ans);
            }
        }

        public void delete(int node) {
            ans -= 2L * size[node] * (size[node] - 1) * (n - size[node]);
            ans -= 1L * size[node] * (size[node] - 1) * (size[node] - 2);
        }

        public void add(int node) {
            ans += 2L * size[node] * (size[node] - 1) * (n - size[node]);
            ans += 1L * size[node] * (size[node] - 1) * (size[node] - 2);
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
}