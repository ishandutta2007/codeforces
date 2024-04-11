import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        private static final int MODULO = 1000000007;
        private final int[] dx = new int[]{-1, 1, 0, 0};
        private final int[] dy = new int[]{0, 0, -1, 1};

        private long[][] multiply(long[][] a, long[][] b) {
            long[][] c = new long[a.length][a.length];
            for (int k = 0; k < a.length; ++k) {
                for (int i = 0; i < a.length; ++i) {
                    if (a[i][k] == 0) continue;
                    for (int j = 0; j < b.length; ++j) {
                        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MODULO;
                    }
                }
            }
            return c;
        }

        private long[][] power(long[][] a, int k) {
            long[][] result = new long[a.length][a.length];
            for (int i = 0; i < a.length; ++i) {
                result[i][i] = 1;
            }
            for (; k != 0; k >>= 1) {
                if (k % 2 == 1) {
                    result = multiply(result, a);
                }
                a = multiply(a, a);
            }
            return result;
        }

        private long[][] getMat(boolean[][] blocking) {
            int n = blocking.length;
            int m = blocking[0].length;

            long[][] ways = new long[n * m][n * m];

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (blocking[i][j]) continue;
                    ways[i * m + j][i * m + j] = 1;
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= m
                                || blocking[ni][nj]) {
                            continue;
                        }
                        ++ways[i * m + j][ni * m + nj];
                    }
                }
            }

            return ways;

        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n, m, k;
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();

            long[][] ways = new long[n * m][n * m];
            for (int i = 0; i < ways.length; ++i) {
                ways[i][i] = 1;
            }

            boolean[][] blocking = new boolean[n][m];

            int lastTime = 1;
            while (k-- != 0) {
                if (in.nextInt() == 1) {
                    int i = in.nextInt() - 1;
                    int j = in.nextInt() - 1;
                    int t = in.nextInt();

                    ways = multiply(ways, power(getMat(blocking), t - lastTime));
                    lastTime = t;

                    out.println(ways[0][i * m + j]);
                } else {
                    int i = in.nextInt() - 1;
                    int j = in.nextInt() - 1;
                    int t = in.nextInt();

                    ways = multiply(ways, power(getMat(blocking), t - lastTime));
                    lastTime = t;

                    blocking[i][j] = !blocking[i][j];
                }
            }
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}