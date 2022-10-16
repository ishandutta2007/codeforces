import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        BBoboniuWalksOnGraph solver = new BBoboniuWalksOnGraph();
        solver.solve(1, in, out);
        out.close();
    }

    static class BBoboniuWalksOnGraph {
        List<BBoboniuWalksOnGraph.Edge>[] graph;
        HashSet<Integer>[] bads;
        boolean[][][][] bad;
        int n;
        int m;
        int k;
        int[] cur;
        int ans;
        boolean[][] bad1;

        void dfs(int index) {
            if (index == k) {
                ans++;
                return;
            }
            for (int i = 0; i <= index; i++) {
                if (bad1[index][i]) continue;
                cur[index] = i;
                boolean ok = true;
                for (int j = 0; ok && j < index; j++) {
                    if (bad[index][j][cur[index]][cur[j]])
                        ok = false;
                }
                if (ok) dfs(index + 1);
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, w = in.nextInt();
                graph[a].add(new BBoboniuWalksOnGraph.Edge(b, w));
            }
            bad1 = new boolean[k][k];
            bads = new HashSet[n];
            for (int i = 0; i < n; i++) bads[i] = new HashSet<>();
            for (int i = 0; i < n; i++) {
                graph[i].sort(Comparator.comparingInt(x -> x.weight));
                for (int j = 0; j < graph[i].size(); j++) {
                    BBoboniuWalksOnGraph.Edge e = graph[i].get(j);
                    if (!bads[e.to].add((graph[i].size() - 1) * k + j)) {
                        bad1[graph[i].size() - 1][j] = true;
                    }
                }
            }
            bad = new boolean[k][k][k][k];
            for (int i = 0; i < n; i++) {
                for (int a : bads[i]) {
                    for (int b : bads[i]) {
                        int a1 = a / k, a2 = a % k, b1 = b / k, b2 = b % k;
                        bad[a1][b1][a2][b2] = true;
                    }
                }
            }
            cur = new int[k];
            dfs(0);
            out.println(ans);
        }

        static class Edge {
            public int to;
            public int weight;

            public Edge(int to, int weight) {
                this.to = to;
                this.weight = weight;
            }

            public String toString() {
                return "Edge{" +
                        "to=" + to +
                        ", weight=" + weight +
                        '}';
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

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}