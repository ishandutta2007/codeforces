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
        public int[] color;
        public int[] perm = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
        public int[] perm2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            color = in.readIntArray(24);

            perm[0] = 4;
            perm[2] = 6;
            perm[4] = 8;
            perm[6] = 10;
            perm[8] = 21;
            perm[10] = 23;
            perm[21] = 0;
            perm[23] = 2;

            int[] p2 = new int[]{1, 3, 5, 0, 2, 4};
            int[][] p4 = new int[][]{
                    {1, 3, 0, 2},
                    {1, 3, 0, 2},
                    {1, 3, 0, 2},
                    {3, 2, 1, 0},
                    {0, 1, 2, 3},
                    {2, 0, 3, 1}
            };
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 4; j++) {
                    perm2[i * 4 + j] = p2[i] * 4 + p4[i][j];
                }
            }


            for (int face = 0; face < 3; face++) {
                rotate(1);
                if (solved(color)) {
                    out.println("YES");
                    return;
                }
                rotate(-1);
                rotate(-1);
                if (solved(color)) {
                    out.println("YES");
                    return;
                }
                rotate(1);

                xx();
            }
            out.println("NO");
        }

        public void rotate(int dir) {
            if (dir == 1) {
                int[] ncolor = new int[24];
                for (int i = 0; i < 24; i++) {
                    ncolor[perm[i]] = color[i];
                }
                color = ncolor;
            } else {
                int[] ncolor = new int[24];
                for (int i = 0; i < 24; i++) {
                    ncolor[i] = color[perm[i]];
                }
                color = ncolor;
            }
        }

        public void xx() {
            int[] ncolor = new int[24];
            for (int i = 0; i < 24; i++) {
                ncolor[perm2[i]] = color[i];
            }
            color = ncolor;
        }

        public boolean solved(int[] s) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 4; j++) {
                    if (s[i * 4 + j] != s[i * 4 + 0]) {
                        return false;
                    }
                }
            }
            return true;
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