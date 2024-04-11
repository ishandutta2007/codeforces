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
        CPalindromicPaths solver = new CPalindromicPaths();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPalindromicPaths {
        InputReader in;
        OutputWriter out;
        int[][] grid;

        int ask(int x1, int y1, int x2, int y2) {
            out.printf("? %d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
            out.flush();
            return in.nextInt();
        }

        int getFlip(int fx, int fy, int tx, int ty) {
            int x = ask(fx, fy, tx, ty);
            return grid[fx][fy] ^ grid[tx][ty] ^ x ^ 1;
        }

        public void solve(int testNumber, InputReader _in, OutputWriter _out) {
            in = _in;
            out = _out;
            int n = in.nextInt();
            grid = new int[n][n];
            grid[0][0] = 1;
            grid[0][1] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == n - 1 && j == n - 1) continue;
                    if ((i + j) % 2 == 1 && j == 0) continue;
                    if (i >= 2) grid[i][j] = getFlip(i - 2, j, i, j);
                    else if (i >= 1 && j >= 1) grid[i][j] ^= getFlip(i - 1, j - 1, i, j);
                    else if (j >= 2) grid[i][j] = getFlip(i, j - 2, i, j);
                }
            }
            for (int j = 1; j < n; j += 2) {
                grid[j][0] = getFlip(j, 0, j, 2);
            }
            grid[n - 1][n - 1] = 0;
            int flip = -1;
            outer:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i >= 1 && j >= 1) {
                        if (grid[i - 1][j] != grid[i][j - 1]) {
                            int nx = -1, ny = -1;
                            if (i + 1 < n) {
                                nx = i + 1;
                                ny = j;
                            } else if (j + 1 < n) {
                                nx = i;
                                ny = j + 1;
                            }
                            if (nx != -1) {
                                flip = getFlip(i - 1, j - 1, nx, ny);
                                break outer;
                            }
                        }
                    }
                    if (i + 1 < n && j + 1 < n) {
                        if (grid[i + 1][j] != grid[i][j + 1]) {
                            int nx = -1, ny = -1;
                            if (i - 1 >= 0) {
                                nx = i - 1;
                                ny = j;
                            } else if (j - 1 >= 0) {
                                nx = i;
                                ny = j - 1;
                            }
                            if (nx != -1) {
                                flip = getFlip(nx, ny, i + 1, j + 1);
                                break outer;
                            }
                        }
                    }
                }
            }
            if (flip == -1) {
                for (int i = 0; i + 2 < n; i++) {
                    if (grid[i][i] == grid[i + 1][i + 1] && grid[i + 1][i + 1] != grid[i + 2][i + 2]) {
                        if (grid[i][i + 1] == grid[i + 1][i + 2]) {
                            flip = getFlip(i, i, i + 1, i + 2);
                        } else {
                            flip = getFlip(i, i + 1, i + 2, i + 2);
                            break;
                        }
                    } else if (grid[i][i] != grid[i + 1][i + 1] && grid[i + 1][i + 1] == grid[i + 2][i + 2]) {
                        if (grid[i][i + 1] != grid[i + 1][i + 2]) {
                            flip = getFlip(i, i, i + 1, i + 2);
                            break;
                        } else {
                            flip = getFlip(i, i + 1, i + 2, i + 2);
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + j) % 2 == 1) {
                        grid[i][j] ^= flip;
                    }
                }
            }
            out.println("!");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out.print(grid[i][j]);
                }
                out.println();
            }
            out.flush();
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

        public void println() {
            writer.println();
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
        }

        public void print(int i) {
            writer.print(i);
        }

    }
}