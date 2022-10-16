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
import java.util.Comparator;
import java.util.Collections;
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
        public List<Integer>[] child;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), b = in.nextInt();
            child = LUtils.genArrayList(n);
            TaskC.Item[] its = new TaskC.Item[n];
            its[0] = new TaskC.Item(in.nextInt(), in.nextInt(), 0);
            for (int i = 1; i < n; i++) {
                its[i] = new TaskC.Item(in.nextInt(), in.nextInt(), i);
                child[in.nextInt() - 1].add(i);
            }
            long[][] dp = new long[n][n + 1];
            int[] size = new int[n];
            List<TaskC.Item>[] gg = LUtils.genArrayList(n);
            for (int i = n - 1; i >= 0; i--) {
                gg[i].add(its[i]);
                for (int j : child[i])
                    gg[i].addAll(gg[j]);
                Collections.sort(gg[i], Comparator.comparingInt(x -> x.c));

                long[] x = new long[2];
                x[0] = 1L << 60;
                x[1] = its[i].c - its[i].d;
                size[i] = 1;
                for (int j : child[i]) {
                    long[] nxt = new long[size[i] + size[j] + 1];
                    Arrays.fill(nxt, 1L << 60);
                    for (int k = 0; k <= size[i]; k++) {
                        for (int m = 0; m <= size[j]; m++) {
                            nxt[k + m] = Math.min(nxt[k + m], x[k] + dp[j][m]);
                        }
                    }
                    size[i] += size[j];
                    x = nxt;
                }
                Arrays.fill(dp[i], 1L << 60);
                System.arraycopy(x, 0, dp[i], 0, x.length);
                dp[i][0] = 0;
                long csum = 0;
                for (int j = 1; j <= gg[i].size(); j++) {
                    csum += gg[i].get(j - 1).c;
                    dp[i][j] = Math.min(dp[i][j], csum);
                }
            }
            for (int i = n; i >= 0; i--) {
                if (dp[0][i] <= b) {
                    out.println(i);
                    return;
                }
            }
        }

        static class Item {
            public int c;
            public int d;
            public int idx;

            public Item(int c, int d, int idx) {
                this.c = c;
                this.d = d;
                this.idx = idx;
            }

        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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