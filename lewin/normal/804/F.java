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
import java.util.BitSet;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public int mod = 1000000007;
        public int n;
        public int a;
        public int b;
        public char[][] adj;
        public List<Integer>[] graph;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            a = in.nextInt();
            b = in.nextInt();
            adj = new char[n][n];
            graph = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            for (int i = 0; i < n; i++) adj[i] = in.next().toCharArray();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][j] == '1') {
                        graph[i].add(j);
                    }
                }
            }
            List<List<Integer>> comp = new SCCTarjan().scc(graph);
            boolean[][] can = new boolean[n][];
            int[] low = new int[n];
            for (int i = 0; i < n; i++) {
                int q = in.nextInt();
                char[] w = in.next().toCharArray();
                can[i] = new boolean[q];
                for (int j = 0; j < q; j++) {
                    can[i][j] = w[j] == '1';
                    if (can[i][j]) low[i]++;
                }
            }
            int[] wcomp = new int[n];
            int idx = 0;
            List<BitSet> bb = new ArrayList<>();
            List<Integer> bs = new ArrayList<>();
            for (List<Integer> gg : comp) {
                int gcd = 0;
                for (int x : gg) {
                    gcd = Utils.gcd(gcd, can[x].length);
                    wcomp[x] = idx;
                }
                idx++;
                BitSet d = new BitSet(gcd);
                bs.add(gcd);
                bb.add(d);
                for (int x : gg) {
                    for (int i = 0; i < can[x].length; i++) {
                        if (can[x][i]) {
                            d.set(i % gcd, true);
                        }
                    }
                }
            }

            for (int kk = comp.size() - 1; kk > 0; kk--) {
                int g = Utils.gcd(bs.get(kk), bs.get(kk - 1));
                BitSet ww = new BitSet(g);
                for (int i = 0; i < bs.get(kk); i += g) {
                    ww.or(bb.get(kk).get(i, i + g));
                }
                for (int i = 0; i < bs.get(kk - 1); i++) {
                    if (ww.get(i % g)) {
                        bb.get(kk - 1).set(i, true);
                    }
                }
            }
            int[] high = new int[n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < can[i].length; j++) {
                    if (bb.get(wcomp[i]).get(j % bs.get(wcomp[i])))
                        high[i]++;
                }
            }
            long ret = 0;
            int[][] comb = Utils.getComb(n + 1, mod);
            for (int lowest = 0; lowest < n; lowest++) {
                int countabove = 0;
                for (int other = 0; other < n; other++) {
                    if (other == lowest) continue;
                    if (low[other] > high[lowest]) {
                        countabove++;
                    }
                }
                if (countabove >= a) {
                    continue;
                }
                int canbig = 0;
                for (int other = 0; other < n; other++) {
                    if (other == lowest) continue;
                    if (low[other] <= high[lowest] && (high[other] > high[lowest] || (high[other] == high[lowest] && other > lowest))) {
                        canbig++;
                    }
                }

                for (int take = 0; take < b && take <= canbig && take + countabove < a; take++) {
                    ret = (ret + 1L * comb[canbig][take] * comb[countabove][b - take - 1]) % mod;
                }
            }
            out.println(ret);
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

    static class Utils {
        public static int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }

        public static int[][] getComb(int sz, int mod) {
            int[][] comb = new int[sz][sz];
            for (int i = 0; i < sz; i++) {
                comb[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                    comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
                    if (comb[i][j] >= mod) comb[i][j] -= mod;
                }
            }
            return comb;
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
}