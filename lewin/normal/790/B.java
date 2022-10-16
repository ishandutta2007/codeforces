import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.stream.Stream;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public List<Integer>[] graph;
        public long[][] sum;
        public long[][] count;
        public int n;
        public int k;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            graph = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }
            sum = new long[n][k];
            count = new long[n][k];
            out.println(dfs(0, -1));
        }

        public long dfs(int node, int par) {
            long ret = 0;
            sum[node][0] = 0;
            count[node][0] = 1;
            for (int next : graph[node]) {
                if (next == par) continue;
                ret += dfs(next, node);
                for (int j = 0; j < k; j++) {
                    for (int i = 0; i < k; i++) {
                        int add = (i + j + 1 + k - 1) / k;
                        ret += sum[next][j] * count[node][i] + sum[node][i] * count[next][j] + count[node][i] * count[next][j] * add;
                    }
                }
                sum[node][0] += count[next][k - 1];
                for (int j = 0; j < k; j++) {
                    count[node][(j + 1) % k] += count[next][j];
                    sum[node][(j + 1) % k] += sum[next][j];
                }
            }
            return ret;
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
}