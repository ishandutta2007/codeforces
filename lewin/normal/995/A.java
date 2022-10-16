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
import java.util.ArrayList;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[][] grid = new int[4][n];
            for (int i = 0; i < 4; i++) {
                grid[i] = in.readIntArray(n);
            }

            ArrayList<TaskA.Move> moves = new ArrayList<>();
            if (k == 2 * n) {
                // can anyone go into their slot
                for (int i = 0; i < n; i++) {
                    for (int e = 1; e <= 2; e++) {
                        if (grid[e][i] == grid[e ^ 1][i]) {
                            moves.add(new TaskA.Move(grid[e][i], (e ^ 1) + 1, i + 1));
                            grid[e][i] = 0;
                        }
                    }
                }

                if (moves.size() == 0) {
                    out.println(-1);
                    return;
                }
            }

            int[][] nr = new int[4][n];
            int[][] nc = new int[4][n];
            for (int i = 1; i < n; i++) {
                nr[1][i] = 1;
                nc[1][i] = i - 1;
            }
            nr[1][0] = 2;
            nc[1][0] = 0;
            for (int i = 0; i + 1 < n; i++) {
                nr[2][i] = 2;
                nc[2][i] = i + 1;
            }
            nr[2][n - 1] = 1;
            nc[2][n - 1] = n - 1;

            int[] x = new int[2 * n], y = new int[2 * n];
            int id = 0;
            for (int i = n - 1; i >= 0; i--) {
                x[id] = 2;
                y[id] = i;
                id++;
            }
            for (int i = 0; i < n; i++) {
                x[id] = 1;
                y[id] = i;
                id++;
            }
            while (true) {
                boolean moved = false;
                for (int i = 0; i < 2 * n; i++) {
                    int cx = x[i], cy = y[i];
                    if (grid[cx][cy] != 0 && grid[cx][cy] == grid[cx ^ 1][cy]) {
                        moves.add(new TaskA.Move(grid[cx][cy], (cx ^ 1) + 1, cy + 1));
                        grid[cx][cy] = 0;
                        moved = true;
                    }
                    int nx = nr[cx][cy], ny = nc[cx][cy];
                    if (grid[nx][ny] == 0 && grid[cx][cy] != 0) {
                        moves.add(new TaskA.Move(grid[cx][cy], nx + 1, ny + 1));
                        grid[nx][ny] = grid[cx][cy];
                        grid[cx][cy] = 0;
                        moved = true;
                    }
                }

                if (!moved) break;
            }

            out.println(moves.size());
            for (TaskA.Move m : moves) {
                out.println(m.car + " " + m.r + " " + m.c);
            }
        }

        static class Move {
            public int car;
            public int r;
            public int c;

            public Move(int car, int r, int c) {
                this.car = car;
                this.r = r;
                this.c = c;
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

        public void println(int i) {
            writer.println(i);
        }

    }
}