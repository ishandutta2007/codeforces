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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        String[] digs = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[] cdigs = new int[n];
            for (int i = 0; i < n; i++) {
                cdigs[i] = Integer.parseInt(in.next(), 2);
            }
            int[] masks = new int[10];
            for (int i = 0; i < 10; i++) {
                masks[i] = Integer.parseInt(digs[i], 2);
            }

            int[][] mx = new int[1 << 7][8];
            int[][] nops = new int[1 << 7][10];
            AUtils.deepFill(nops, -1);
            AUtils.deepFill(mx, -1);
            for (int i = 0; i < 1 << 7; i++) {
                for (int j = 0; j < 10; j++) {
                    if ((i & masks[j]) == i) {
                        int ops = Integer.bitCount(masks[j] ^ i);
                        mx[i][ops] = Math.max(mx[i][ops], j);
                        nops[i][j] = ops;
                    }
                }
            }

            boolean[][] can = new boolean[n + 1][k + 1];
            can[n][0] = true;
            for (int i = n - 1; i >= 0; i--) {
                for (int r = 0; r <= 7; r++) {
                    if (mx[cdigs[i]][r] != -1) {
                        for (int j = r; j <= k; j++) {
                            can[i][j] |= can[i + 1][j - r];
                        }
                    }
                }
            }

            if (!can[0][k]) {
                out.println(-1);
                return;
            }

            int ops = k;
            for (int i = 0; i < n; i++) {
                for (int dig = 9; dig >= 0; dig--) {
                    int b = nops[cdigs[i]][dig];
                    if (b >= 0 && b <= ops && can[i + 1][ops - b]) {
                        out.print(dig);
                        ops -= b;
                        break;
                    }
                }
            }
            out.println();
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

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}