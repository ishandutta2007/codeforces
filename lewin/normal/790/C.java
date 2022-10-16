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
        public int cv;
        public int ck;
        public int cs;
        public int[][] freq;
        public ArrayList<Integer>[] pos;
        public int[][][][] dp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            char[] c = in.next().toCharArray();
            cv = 0;
            ck = 0;
            cs = 0;
            freq = new int[n + 1][3];
            pos = new ArrayList[3];
            for (int i = 0; i < 3; i++) pos[i] = new ArrayList<>();
            int idx = 0;
            for (char x : c) {
                System.arraycopy(freq[idx], 0, freq[idx + 1], 0, 3);
                idx++;
                if (x == 'V') {
                    freq[idx][0]++;
                    cv++;
                    pos[0].add(idx);
                } else if (x == 'K') {
                    freq[idx][1]++;
                    ck++;
                    pos[1].add(idx);
                } else {
                    freq[idx][2]++;
                    cs++;
                    pos[2].add(idx);
                }
            }
            dp = new int[cv + 1][ck + 1][cs + 1][3];
            for (int[][][] x : dp) for (int[][] y : x) for (int[] z : y) Arrays.fill(z, -1);
            out.println(dfs(0, 0, 0, 2));
        }

        public int dfs(int tv, int tk, int ts, int last) {
            if (tv == cv && tk == ck && ts == cs) {
                return 0;
            }
            if (dp[tv][tk][ts][last] != -1) return dp[tv][tk][ts][last];
            int ret = 1 << 29;
            if (tv < cv) {
                int p = pos[0].get(tv);
                int move = Math.max(freq[p][0] - tv, 0) + Math.max(freq[p][1] - tk, 0) + Math.max(freq[p][2] - ts, 0) - 1;
                ret = Math.min(ret, dfs(tv + 1, tk, ts, 0) + move);
            }
            if (tk < ck && last != 0) {
                int p = pos[1].get(tk);
                int move = Math.max(freq[p][0] - tv, 0) + Math.max(freq[p][1] - tk, 0) + Math.max(freq[p][2] - ts, 0) - 1;
                ret = Math.min(ret, dfs(tv, tk + 1, ts, 1) + move);
            }
            if (ts < cs) {
                int p = pos[2].get(ts);
                int move = Math.max(freq[p][0] - tv, 0) + Math.max(freq[p][1] - tk, 0) + Math.max(freq[p][2] - ts, 0) - 1;
                ret = Math.min(ret, dfs(tv, tk, ts + 1, 2) + move);
            }
            return dp[tv][tk][ts][last] = ret;
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