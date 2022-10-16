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
        public int n;
        public int s;
        public int m;
        public List<Integer>[] graph;
        public int[][] dist;
        public boolean[] leaf;
        public int[] cc;
        public int MAXANS = 50 * 50 * 50;
        public ArrayList<Integer> leaves;
        public int count;
        public int[][] dp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            dist = new int[n][n];
            for (int[] x : dist) Arrays.fill(x, 1 << 29);
            for (int i = 0; i < n; i++) dist[i][i] = 0;
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, c = in.nextInt();
                dist[a][b] = dist[b][a] = c;
                graph[a].add(b);
                graph[b].add(a);
            }
            leaf = new boolean[n];
            for (int i = 0; i < n; i++) {
                leaf[i] = graph[i].size() == 1;
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
            s = in.nextInt() - 1;
            m = in.nextInt();
            cc = new int[n];
            for (int i = 0; i < m; i++) cc[in.nextInt() - 1]++;

            dp = new int[n + 1][m + 1];
            int best = Integer.MAX_VALUE;
            for (int[] x : dp) Arrays.fill(x, -1);
            for (int j : graph[s]) {
                count = 0;
                leaves = new ArrayList<>();
                dfs(j, s);

                if (count > 0) {
                    int lo = 0, hi = MAXANS;
                    while (lo < hi) {
                        int mid = (lo + hi + 1) / 2;
                        if (can2(mid, count)) lo = mid;
                        else hi = mid - 1;
                    }
                    best = Math.min(best, lo);
                }
            }
            out.println(best);
        }

        public boolean can2(int target, int have) {
            int tot = 0;
            for (int j : leaves) {
                int add = dist[s][j];
                if (solve(j, m - 1) + add >= target) {
                    int canadd = 1;
                    while (canadd < have && solve(j, m - canadd - 1) + add >= target) canadd++;
                    tot += canadd;
                }
            }
            return tot >= have;
        }

        public void dfs(int node, int par) {
            if (leaf[node]) leaves.add(node);
            count += cc[node];
            for (int next : graph[node]) {
                if (next == par) continue;
                dfs(next, node);
            }
        }

        public int solve(int node, int crim) {
            if (crim == 0) return 0;
            if (dp[node][crim] != -1) return dp[node][crim];
            int lo = 0, hi = MAXANS;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (can(mid, node, crim)) lo = mid;
                else hi = mid - 1;
            }
            return dp[node][crim] = lo;
        }

        public boolean can(int target, int node, int crim) {
            int tot = 0;
            for (int j = 0; j < n; j++) {
                if (leaf[j] && j != node) {
                    int add = dist[node][j];
                    if (solve(j, crim - 1) + add >= target) {
                        int canadd = 1;
                        while (canadd < crim && solve(j, crim - canadd - 1) + add >= target) canadd++;
                        tot += canadd;
                    }
                }
            }
            return tot >= crim;
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