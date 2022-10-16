import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        BMonopoleMagnets solver = new BMonopoleMagnets();
        solver.solve(1, in, out);
        out.close();
    }

    static class BMonopoleMagnets {
        int[] q;
        int qt;
        int qh;
        boolean[][] vis;
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) {
                grid[i] = in.next().toCharArray();
            }
            boolean[] emptyrow = new boolean[n];
            boolean[] emptycol = new boolean[m];
            Arrays.fill(emptyrow, true);
            Arrays.fill(emptycol, true);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '#') {
                        emptyrow[i] = false;
                        emptycol[j] = false;
                    }
                }
            }
            int er = 0, ec = 0;
            for (int i = 0; i < n; i++) if (emptyrow[i]) er++;
            for (int j = 0; j < m; j++) if (emptycol[j]) ec++;
            if (er == n && ec == m) {
                out.println(0);
                return;
            }
            if ((er == 0) != (ec == 0)) {
                out.println(-1);
                return;
            }

            for (int i = 0; i < n; i++) {
                if (emptyrow[i]) continue;
                int count = 0, mn = m + 1, mx = -1;
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '#') {
                        count++;
                        mn = Math.min(mn, j);
                        mx = Math.max(mx, j);
                    }
                }
                if (mx - mn + 1 != count) {
                    out.println(-1);
                    return;
                }
            }
            for (int i = 0; i < m; i++) {
                if (emptycol[i]) continue;
                int count = 0, mn = n + 1, mx = -1;
                for (int j = 0; j < n; j++) {
                    if (grid[j][i] == '#') {
                        count++;
                        mn = Math.min(mn, j);
                        mx = Math.max(mx, j);
                    }
                }
                if (mx - mn + 1 != count) {
                    out.println(-1);
                    return;
                }
            }
            q = new int[n * m];
            qt = 0;
            qh = 0;
            vis = new boolean[n][m];
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!vis[i][j] && grid[i][j] == '#') {
                        ans++;
                        q[qt++] = i * m + j;
                        vis[i][j] = true;
                        while (qh < qt) {
                            int cur = q[qh++];
                            int row = cur / m, col = cur % m;
                            for (int k = 0; k < 4; k++) {
                                int nr = row + dx[k], nc = col + dy[k];
                                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '#') {
                                    vis[nr][nc] = true;
                                    q[qt++] = nr * m + nc;
                                }
                            }
                        }
                    }
                }
            }
            out.println(ans);
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