import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
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
        ETourism solver = new ETourism();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETourism {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            long[] scores = in.readLongArray(n);
            HashSet<Integer>[] edges = new HashSet[n];
            for (int i = 0; i < n; i++) edges[i] = new HashSet<>();
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                edges[a].add(b);
                edges[b].add(a);
            }
            int s = in.nextInt() - 1;

            long[] maxtail = new long[n];
            HashSet<Integer> active = new HashSet<>();
            for (int i = 0; i < n; i++) active.add(i);

            int[] queue = new int[n];
            int front = 0, back = 0;
            for (int i = 0; i < n; i++) {
                if (edges[i].size() == 1 && i != s) {
                    queue[back++] = i;
                }
            }

            while (front < back) {
                int cur = queue[front++];
                active.remove(cur);

                int nxt = edges[cur].iterator().next();
                maxtail[nxt] = Math.max(maxtail[nxt], maxtail[cur] + scores[cur]);
                edges[nxt].remove(cur);
                if (edges[nxt].size() == 1 && nxt != s) {
                    queue[back++] = nxt;
                }
            }

            long ans = 0;
            long add = 0;
            for (int i : active) {
                ans += scores[i];
                add = Math.max(add, maxtail[i]);
            }
            out.println(ans + add);
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
}