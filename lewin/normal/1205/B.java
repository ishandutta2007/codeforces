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
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BShortestCycle solver = new BShortestCycle();
        solver.solve(1, in, out);
        out.close();
    }

    static class BShortestCycle {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            long[] arr = in.readLongArray(n);
            long[] x = new long[n];
            int q = 0;
            for (int i = 0; i < 62; i++) {
                int c = 0;
                for (int j = 0; j < n; j++) {
                    if (((arr[j] >> i) & 1) == 1) {
                        c++;
                    }
                }
                if (c >= 3) {
                    out.println(3);
                    return;
                }
            }
            for (int i = 0; i < n; i++) if (arr[i] > 0) x[q++] = arr[i];
            arr = Arrays.copyOf(x, q);
            n = q;
            List<Integer>[] graph = LUtils.genArrayList(n);
            boolean[][] g = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j && (arr[i] & arr[j]) != 0) {
                        graph[i].add(j);
                        g[i][j] = true;
                    }
                }
            }

            int[] queue = new int[n];
            int[] dist = new int[n];
            int front, back;
            int ans = n + 1;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j && (arr[i] & arr[j]) != 0) {
                        g[i][j] = false;
                        g[j][i] = false;
                        Arrays.fill(dist, 1 << 29);
                        dist[i] = 0;
                        front = 0;
                        back = 0;
                        queue[back++] = i;
                        while (front < back) {
                            int cur = queue[front++];
                            for (int k : graph[cur]) {
                                if (g[cur][k] && dist[cur] + 1 < dist[k]) {
                                    queue[back++] = k;
                                    dist[k] = dist[cur] + 1;
                                }
                            }
                        }
                        ans = Math.min(ans, dist[j] + 1);
                        g[i][j] = true;
                        g[j][i] = true;
                    }
                }
            }
            out.println(ans > n ? -1 : ans);
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

        public long[] readLongArray(int tokens) {
            long[] ret = new long[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextLong();
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

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}