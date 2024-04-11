import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        EChipsPuzzle solver = new EChipsPuzzle();
        solver.solve(1, in, out);
        out.close();
    }

    static class EChipsPuzzle {
        int n;
        int m;

        public ArrayList<EChipsPuzzle.Move> fix(char[][][] s, boolean reverse) {
            ArrayList<EChipsPuzzle.Move> moves = new ArrayList<>();
            List<Integer>[][] tmp = new List[n][m];
            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) tmp[i][j] = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int f, b, ic;
                    if (reverse) {
                        f = 0;
                        b = s[i][j].length;
                        ic = 1;
                    } else {
                        f = s[i][j].length - 1;
                        b = -1;
                        ic = -1;
                    }
                    for (int k = f; k != b; k += ic) {
                        if (s[i][j][k] == '0') {
                            if (i != 0) {
                                moves.add(new EChipsPuzzle.Move(i, j, 0, j));
                                tmp[0][j].add(0);
                            } else if (j != 0) {
                                moves.add(new EChipsPuzzle.Move(i, j, i, 0));
                                tmp[i][0].add(0);
                            } else {
                                if (n > 1) {
                                    moves.add(new EChipsPuzzle.Move(i, j, n - 1, 0));
                                    tmp[n - 1][0].add(0);
                                } else {
                                    moves.add(new EChipsPuzzle.Move(i, j, 0, m - 1));
                                    tmp[0][m - 1].add(0);
                                }
                            }
                        } else {
                            if (i != n - 1) {
                                moves.add(new EChipsPuzzle.Move(i, j, n - 1, j));
                                tmp[n - 1][j].add(1);
                            } else if (j != m - 1) {
                                moves.add(new EChipsPuzzle.Move(i, j, i, m - 1));
                                tmp[i][m - 1].add(1);
                            } else {
                                if (n > 1) {
                                    moves.add(new EChipsPuzzle.Move(i, j, n - 1, 0));
                                    tmp[n - 1][0].add(1);
                                } else {
                                    moves.add(new EChipsPuzzle.Move(i, j, 0, m - 1));
                                    tmp[0][m - 1].add(1);
                                }
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k : tmp[i][j]) {
                        if (k == 0) {
                            if (i != 0) {
                                moves.add(new EChipsPuzzle.Move(i, j, 0, j));
                                tmp[0][j].add(0);
                            } else if (j != 0) {
                                moves.add(new EChipsPuzzle.Move(i, j, i, 0));
                                tmp[i][0].add(0);
                            }
                        } else {
                            if (i != n - 1) {
                                moves.add(new EChipsPuzzle.Move(i, j, n - 1, j));
                                tmp[n - 1][j].add(1);
                            } else if (j != m - 1) {
                                moves.add(new EChipsPuzzle.Move(i, j, i, m - 1));
                                tmp[i][m - 1].add(1);
                            }
                        }
                    }
                }
            }
            if (reverse) {
                Collections.reverse(moves);
            }
            return moves;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            char[][][] s = new char[n][m][];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    s[i][j] = in.next().toCharArray();
                }
            }
            ArrayList<EChipsPuzzle.Move> forw = fix(s, false);
            char[][][] goal = new char[n][m][];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    goal[i][j] = in.next().toCharArray();
                }
            }
            ArrayList<EChipsPuzzle.Move> back = fix(goal, true);

            out.println(forw.size() + back.size());
            for (EChipsPuzzle.Move g : forw) {
                out.println((g.x1 + 1) + " " + (g.y1 + 1) + " " + (g.x2 + 1) + " " + (g.y2 + 1));
            }
            for (EChipsPuzzle.Move g : back) {
                out.println((g.x2 + 1) + " " + (g.y2 + 1) + " " + (g.x1 + 1) + " " + (g.y1 + 1));
            }
        }

        static class Move {
            public int x1;
            public int y1;
            public int x2;
            public int y2;

            public Move(int x1, int y1, int x2, int y2) {
                this.x1 = x1;
                this.y1 = y1;
                this.x2 = x2;
                this.y2 = y2;
            }

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