import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.InputStream;
import java.util.BitSet;

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
        GNewRoadNetwork solver = new GNewRoadNetwork();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class GNewRoadNetwork {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            char[][] s = new char[m][n];
            BitSet[] bs = new BitSet[n];
            for (int i = 0; i < n; i++) {
                bs[i] = new BitSet();
            }
            for (int i = 0; i < m; i++) {
                char[] rr = in.next().toCharArray();
                for (int j = 0; j < n; j++) {
                    s[i][j] = rr[j];
                    if (s[i][j] == '1') {
                        bs[j].set(i);
                    }
                }
            }
            int[][] counts = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    BitSet a = (BitSet) bs[i].clone();
                    a.and(bs[j]);
                    counts[i][j] = counts[j][i] = a.cardinality();
                }
            }
            int[] tree = mstPrim(counts);
            int[] r = new int[m];
            int[] want = new int[m];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (s[i][j] == '1') want[i]++;
                }
                want[i]--;
            }
            for (int i = 1; i < n; i++) {
                for (int k = 0; k < m; k++) {
                    if (s[k][i] == '1' && s[k][tree[i]] == '1') {
                        r[k]++;
                    }
                }
            }
            for (int k = 0; k < m; k++) {
                if (r[k] != want[k]) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
            for (int i = 1; i < n; i++) {
                out.println((i + 1) + " " + (tree[i] + 1));
            }

        }

        public static int[] mstPrim(int[][] d) {
            int n = d.length;
            int[] prev = new int[n];
            int[] dist = new int[n];
            Arrays.fill(dist, Integer.MIN_VALUE);
            prev[0] = -1;
            dist[0] = 0;
            boolean[] visited = new boolean[n];
            for (int i = 0; i < n; i++) {
                int u = -1;
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && (u == -1 || dist[u] < dist[j]))
                        u = j;
                }
                visited[u] = true;
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && dist[j] < d[u][j]) {
                        dist[j] = d[u][j];
                        prev[j] = u;
                    }
                }
            }
            return prev;
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
}