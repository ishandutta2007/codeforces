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
        ENoGameNoLife solver = new ENoGameNoLife();
        solver.solve(1, in, out);
        out.close();
    }

    static class ENoGameNoLife {
        int mod = 998244353;
        List<Integer>[] graph;
        int MAX = 512;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            graph = LUtils.genArrayList(n);
            int[] indeg = new int[n];
            for (int i = 0; i < m; i++) {
                int u = in.nextInt() - 1, v = in.nextInt() - 1;
                graph[u].add(v);
                indeg[v]++;
            }
            int[] q = new int[n];
            int front = 0, back = 0;
            for (int i = 0; i < n; i++) {
                if (indeg[i] == 0) {
                    q[back++] = i;
                }
            }
            while (front < back) {
                int cur = q[front++];
                for (int x : graph[cur]) {
                    if (--indeg[x] == 0) {
                        q[back++] = x;
                    }
                }
            }

            int[] nim = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                int cur = q[i];
                HashSet<Integer> seen = new HashSet<>();
                for (int x : graph[cur]) {
                    seen.add(nim[x]);
                }
                while (seen.contains(nim[cur])) nim[cur]++;
            }
            long[] count = new long[MAX];
            for (int i = 0; i < n; i++) {
                count[nim[i]]++;
            }
            long denom = Utils.inv(n + 1, mod);
            for (int i = 0; i < MAX; i++) {
                count[i] = count[i] * denom % mod;
                count[i] = mod - count[i];
            }
            int[][] mat = new int[MAX][MAX];
            int[] b = new int[MAX];
            for (int i = 0; i < MAX; i++) {
                b[i] = (int) (i == 0 ? 0 : denom);
                for (int j = 0; j < MAX; j++) {
                    mat[i][j] = (int) count[i ^ j];
                }
                mat[i][i]++;
            }
            int[] ret = Gauss.gauss(mat, b, mod);
            out.println(ret[0]);
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

    static class Utils {
        public static long inv(long N, long M) {
            long x = 0, lastx = 1, y = 1, lasty = 0, q, t, a = N, b = M;
            while (b != 0) {
                q = a / b;
                t = a % b;
                a = b;
                b = t;
                t = x;
                x = lastx - q * x;
                lastx = t;
                t = y;
                y = lasty - q * y;
                lasty = t;
            }
            return (lastx + M) % M;
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
                throw new UnknownError();
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

    static class Gauss {
        public static int[] gauss(int[][] a, int[] b, int mod) {
            int n = a.length;
            for (int row = 0; row < n; row++) {
                long iv = Utils.inv(a[row][row], mod);
                for (int i = row + 1; i < n; i++)
                    a[row][i] = (int) (1L * a[row][i] * iv % mod);
                b[row] = (int) (1L * b[row] * iv % mod);
                // a[row][row] = 1;
                for (int i = 0; i < n; i++) {
                    int x = a[i][row];
                    if (i != row && x != 0) {
                        // row + 1 instead of row is an optimization
                        for (int j = row + 1; j < n; j++) {
                            a[i][j] -= 1L * a[row][j] * x % mod;
                            if (a[i][j] < 0) a[i][j] += mod;
                        }
                        b[i] -= 1L * b[row] * x % mod;
                        if (b[i] < 0) b[i] += mod;
                    }
                }
            }
            return b;
        }

    }
}