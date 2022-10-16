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
import java.util.LinkedList;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] d = in.readIntArray(m);
            AUtils.sort(d);
            int g = in.nextInt(), r = in.nextInt();

            LinkedList<Integer> q = new LinkedList<>();
            int[][] dist = new int[m][g + 1];
            AUtils.deepFill(dist, Integer.MAX_VALUE);
            boolean[][] vis = new boolean[m][g + 1];
            q.add(0);
            vis[0][0] = true;
            dist[0][0] = 0;
            while (q.size() > 0) {
                int cur = q.pollFirst();
                int node = cur % m;
                int time = cur / m;
                if (time == g) {
                    if (!vis[node][0]) {
                        vis[node][0] = true;
                        q.addLast(node);
                        dist[node][0] = dist[node][time] + 1;
                    }
                } else {
                    if (node > 0 && d[node] - d[node - 1] + time <= g) {
                        int nnode = node - 1;
                        int ntime = time + d[node] - d[node - 1];
                        if (!vis[nnode][ntime]) {
                            vis[nnode][ntime] = true;
                            q.addFirst(ntime * m + nnode);
                            dist[nnode][ntime] = dist[node][time];
                        }
                    }
                    if (node + 1 < m && d[node + 1] - d[node] + time <= g) {
                        int nnode = node + 1;
                        int ntime = time + d[node + 1] - d[node];
                        if (!vis[nnode][ntime]) {
                            vis[nnode][ntime] = true;
                            q.addFirst(ntime * m + nnode);
                            dist[nnode][ntime] = dist[node][time];
                        }
                    }
                }
            }
            int best = Integer.MAX_VALUE;
            for (int i = 0; i <= g; i++) {
                if (dist[m - 1][i] == Integer.MAX_VALUE) continue;
                best = Math.min(best, dist[m - 1][i] * (r + g) + i);
            }
            out.println(best == Integer.MAX_VALUE ? -1 : best);
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

    static class AUtils {
        public static void sort(int[] arr) {
            shuffle(arr);
            Arrays.sort(arr);
        }

        public static void shuffle(int[] arr) {
            for (int i = 1; i < arr.length; i++) {
                int j = (int) (Math.random() * (i + 1));
                if (i != j) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
        }

        public static void deepFill(int[][] x, int val) {
            for (int[] y : x) deepFill(y, val);
        }

        public static void deepFill(int[] x, int val) {
            Arrays.fill(x, val);
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