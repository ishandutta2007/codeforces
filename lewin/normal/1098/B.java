import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        BNiceTable solver = new BNiceTable();
        solver.solve(1, in, out);
        out.close();
    }

    static class BNiceTable {
        char[] cs = "ACGT".toCharArray();

        int score(char[][] a, char[][] b) {
            int count = 0;
            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < a[0].length; j++) {
                    if (a[i][j] == b[i][j])
                        count++;
                }
            }
            return count;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) grid[i] = in.next().toCharArray();
            char[][] best = new char[n][m];
            int bscore = -1;
            for (int X = 0; X < 4; X++) {
                for (int Y = 0; Y < 4; Y++) {
                    if (X == Y) continue;
                    for (int Z = 0; Z < 4; Z++) {
                        if (Z == X || Z == Y) continue;

                        int W = 6 - X - Y - Z;
                        if (X > Y || Z > W) continue;


                        {
                            char[][] ww = new char[n][m];
                            for (int i = 0; i < n; i++) {
                                char a = (i % 2 == 0 ? cs[X] : cs[Z]);
                                char b = (i % 2 == 0 ? cs[Y] : cs[W]);
                                int ca0 = 0, ca1 = 0, cb0 = 0, cb1 = 0;
                                for (int j = 0; j < m; j++) {
                                    if (grid[i][j] == a) {
                                        if (j % 2 == 0) ca0++;
                                        else ca1++;
                                    }
                                    if (grid[i][j] == b) {
                                        if (j % 2 == 0) cb0++;
                                        else cb1++;
                                    }
                                }
                                for (int j = 0; j < m; j++) {
                                    ww[i][j] = (ca0 + cb1 > cb0 + ca1) ^ (j % 2 == 0) ? b : a;
                                }
                            }
                            int r = score(ww, grid);
                            if (r > bscore) {
                                bscore = r;
                                best = ww;
                            }
                        }
                        {
                            char[][] ww = new char[n][m];
                            for (int j = 0; j < m; j++) {
                                char a = (j % 2 == 0 ? cs[X] : cs[Z]);
                                char b = (j % 2 == 0 ? cs[Y] : cs[W]);
                                int ca0 = 0, ca1 = 0, cb0 = 0, cb1 = 0;
                                for (int i = 0; i < n; i++) {
                                    if (grid[i][j] == a) {
                                        if (i % 2 == 0) ca0++;
                                        else ca1++;
                                    }
                                    if (grid[i][j] == b) {
                                        if (i % 2 == 0) cb0++;
                                        else cb1++;
                                    }
                                }
                                for (int i = 0; i < n; i++) {
                                    ww[i][j] = (ca0 + cb1 > cb0 + ca1) ^ (i % 2 == 0) ? b : a;
                                }
                            }
                            int r = score(ww, grid);
                            if (r > bscore) {
                                bscore = r;
                                best = ww;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                out.println(new String(best[i]));
            }
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
}