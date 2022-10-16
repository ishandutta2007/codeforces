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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final int MAXNODES = 30 * 300000 + 101;
        static final int MAXB = 29;
        int[] count;
        int[][] next;
        int cidx;

        int create() {
            return cidx++;
        }

        void insert(int num) {
            int cur = 0;
            for (int bit = MAXB; bit >= 0; bit--) {
                count[cur]++;
                int c = (num >> bit) & 1;
                if (next[cur][c] == -1) next[cur][c] = create();
                cur = next[cur][c];
            }
            count[cur]++;
        }

        int query(int num) {
            int cur = 0;
            int res = 0;
            for (int bit = MAXB; bit >= 0; bit--) {
                count[cur]--;
                int c = (num >> bit) & 1;
                int want = c;

                if (next[cur][want] == -1 || count[next[cur][want]] == 0) {
                    want = 1 ^ want;
                    res += 1 << bit;
                }
                cur = next[cur][want];
            }
            count[cur]--;
            return res;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            count = new int[MAXNODES];
            next = new int[MAXNODES][2];
            AUtils.deepFill(next, -1);
            create();
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                insert(in.nextInt());
            }
            for (int i = 0; i < n; i++) {
                out.println(query(arr[i]));
            }
        }

    }

    static class AUtils {
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
}