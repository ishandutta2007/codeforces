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
            int r = in.nextInt();
            int c = in.nextInt();
            int[][] grid = new int[r][c];
            for (int i = 0; i < r; i++) grid[i] = in.readIntArray(c);

            int min = AUtils.min(grid[0]);
            for (int i = 1; i < r; i++) min = Math.min(min, AUtils.min(grid[i]));

            for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) grid[i][j] -= min;
            ArrayList<TaskA.Operation> ops = new ArrayList<>();
            for (int k = 0; k < min; k++) {
                if (r < c) for (int i = 0; i < r; i++) ops.add(new TaskA.Operation(0, i));
                else for (int i = 0; i < c; i++) ops.add(new TaskA.Operation(1, i));
            }

            int zx = -1, zy = -1;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == 0) {
                        zx = i;
                        zy = j;
                    }
                }
            }

            int[] rs = new int[r], cs = new int[c];

            for (int i = 0; i < r; i++) {
                rs[i] = grid[i][zy];
            }
            for (int j = 0; j < c; j++) {
                cs[j] = grid[zx][j];
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] != rs[i] + cs[j]) {
                        out.println(-1);
                        return;
                    }
                }
            }

            for (int i = 0; i < r; i++) {
                while (rs[i]-- > 0) ops.add(new TaskA.Operation(0, i));
            }
            for (int j = 0; j < c; j++) {
                while (cs[j]-- > 0) ops.add(new TaskA.Operation(1, j));
            }

            out.println(ops.size());
            for (TaskA.Operation o : ops) out.println(o);
        }

        static class Operation {
            public int which;
            public int pos;

            public Operation(int which, int pos) {
                this.which = which;
                this.pos = pos;
            }

            public String toString() {
                return (which == 0 ? "row" : "col") + " " + (pos + 1);
            }

        }

    }

    static class AUtils {
        public static int min(int[] arr) {
            int res = arr[0];
            for (int x : arr) res = Math.min(res, x);
            return res;
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
}