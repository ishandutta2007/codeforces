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
        public int n;
        public int[][] prob;
        public double[][] dp;
        public double[][][] leader;
        public double[][][] xx;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int p = in.nextInt();
            n = 1 << p;
            prob = new int[n][n];
            for (int i = 0; i < n; i++) prob[i] = in.readIntArray(n);

            dp = new double[n][n];
            for (double[] x : dp) Arrays.fill(x, -1);
            leader = new double[n][n][n];
            for (int i = 0; i < n; i++) {
                leader[i][i][i] = 1.0;
            }
            for (int size = 2; size <= n; size *= 2) {
                for (int start = 0; start < n; start += size) {
                    int end = (start + size - 1);
                    int mid = (start + end) / 2;
                    for (int px = start; px <= mid; px++) {
                        for (int py = mid + 1; py <= end; py++) {
                            leader[px][start][end] += leader[px][start][mid] * leader[py][mid + 1][end] * prob[px][py] / 100.0;
                            leader[py][start][end] += leader[py][mid + 1][end] * leader[px][start][mid] * prob[py][px] / 100.0;
                        }
                    }
                }
            }
            xx = new double[n][n][n];
            for (double[][] x : xx) for (double[] y : x) Arrays.fill(y, -1);
            out.println(solve(0, n - 1));
        }

        public double solve(int from, int to) {
            if (from == to) return 0;
            if (dp[from][to] != -1) return dp[from][to];

            double res = 0;
            for (int winner = from; winner <= to; winner++) {
                double add = exp(winner, from, to);
                int tf = from, tt = to;
                while (tf < tt) {
                    int mid = (tf + tt) / 2;
                    if (winner <= mid) {
                        add += solve(mid + 1, tt);
                        tt = mid;
                    } else {
                        add += solve(tf, mid);
                        tf = mid + 1;
                    }
                }
                res = Math.max(res, add);
            }


            return dp[from][to] = res;
        }

        public double exp(int player, int from, int to) {
            if (from == to) return 0;
            if (xx[player][from][to] != -1) return xx[player][from][to];
            double s = 0;
            int mid = (from + to) / 2;
            if (player <= mid) {
                for (int i = mid + 1; i <= to; i++) {
                    s += leader[player][from][mid] * leader[i][mid + 1][to] * prob[player][i] / 100.0;
                }
                s *= (to - from + 1) / 2;
                s += exp(player, from, mid);
            } else {
                for (int i = from; i <= mid; i++) {
                    s += leader[player][mid + 1][to] * leader[i][from][mid] * prob[player][i] / 100.0;
                }
                s *= (to - from + 1) / 2;
                s += exp(player, mid + 1, to);
            }
            return xx[player][from][to] = s;
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

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}