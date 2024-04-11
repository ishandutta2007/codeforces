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
import java.io.InputStream;
import java.util.ArrayList;

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
        ERandomForestRank solver = new ERandomForestRank();
        solver.solve(1, in, out);
        out.close();
    }

    static class ERandomForestRank {
        int n;
        List<Integer>[] tree;
        int mod = 998244353;
        long[][] dp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            tree = LUtils.genArrayList(n);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                tree[a].add(b);
                tree[b].add(a);
            }
            dp = new long[n][];
            out.println((dfs(0, -1)[2] * 2) % mod);
        }

        long[] dfs(int node, int par) {
            long tot = 1;
            long alltaken = 1;
            for (int next : tree[node]) {
                if (next == par) continue;
                long[] r = dfs(next, node);
                tot = tot * (r[0] + r[1] + r[0] + r[1]) % mod;
                alltaken = alltaken * (r[1] + r[1] + r[0]) % mod;
            }
            long free = alltaken;
            long notfree = (tot - alltaken + mod) % mod;
            long sum = notfree;
            for (int next : tree[node]) {
                if (next == par) continue;
                long mult = tot * Utils.inv((dp[next][0] + dp[next][1] + dp[next][0] + dp[next][1]) % mod, mod) % mod;
                sum = (sum + 2 * mult * dp[next][2]) % mod;
            }
            return dp[node] = new long[]{free, notfree, sum};
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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 20];
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
}