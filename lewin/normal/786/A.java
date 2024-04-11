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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int k1 = in.nextInt();
            int[] a1 = in.readIntArray(k1);
            int k2 = in.nextInt();
            int[] a2 = in.readIntArray(k2);
            int[] count1 = new int[n];
            int[] count2 = new int[n];
            Arrays.fill(count1, k1);
            Arrays.fill(count2, k2);
            int[][] winner = new int[2][n];
            for (int[] x : winner) Arrays.fill(x, -1);
            winner[0][0] = 1;
            winner[1][0] = 0;
            int[] rqueue = new int[n];
            int[] mqueue = new int[n];
            int rback = 0, mback = 0;
            int rfront = 0, mfront = 0;
            rqueue[rback++] = 0;
            mqueue[mback++] = 0;
            while (rfront < rback || mfront < mback) {
                if (rfront < rback) {
                    int c = rqueue[rfront++];
                    for (int a : a1) {
                        int w = (c - a + n) % n;
                        if (winner[0][w] != -1) continue;
                        if (winner[1][c] == 0) {
                            winner[0][w] = 0;
                            mqueue[mback++] = w;
                        } else {
                            if (--count1[w] == 0) {
                                winner[0][w] = 1;
                                mqueue[mback++] = w;
                            }
                        }
                    }
                }
                if (mfront < mback) {
                    int c = mqueue[mfront++];
                    for (int a : a2) {
                        int w = (c - a + n) % n;
                        if (winner[1][w] != -1) continue;
                        if (winner[0][c] == 1) {
                            winner[1][w] = 1;
                            rqueue[rback++] = w;
                        } else {
                            if (--count2[w] == 0) {
                                winner[1][w] = 0;
                                rqueue[rback++] = w;
                            }
                        }
                    }
                }
            }

            for (int i = 1; i < n; i++) {
                if (i != 1) out.print(" ");
                out.print(s(winner[0][i], 0));
            }
            out.println();
            for (int i = 1; i < n; i++) {
                if (i != 1) out.print(" ");
                out.print(s(winner[1][i], 1));
            }
            out.println();
        }

        public String s(int x, int v) {
            if (x == -1) return "Loop";
            if (x == v) return "Win";
            return "Lose";
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

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}