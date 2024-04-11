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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public final int OR = 0;
        public final int AND = 1;
        public final int XOR = 2;
        public String s = "|&^";

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] type = new int[n], op = new int[n];
            for (int i = 0; i < n; i++) {
                type[i] = s.indexOf(in.next());
                op[i] = in.nextInt();
            }
            int or = 0, and = 1023, xor = 0;
            for (int bit = 0; bit < 10; bit++) {
                int i0 = 0, i1 = 1;
                for (int i = 0; i < n; i++) {
                    switch (type[i]) {
                        case OR:
                            if (((op[i] >> bit) & 1) == 1) {
                                i0 = 1;
                                i1 = 1;
                            }
                            break;
                        case AND:
                            if (((op[i] >> bit) & 1) == 0) {
                                i0 = 0;
                                i1 = 0;
                            }
                            break;
                        case XOR:
                            if (((op[i] >> bit) & 1) == 1) {
                                i0 = i0 ^ 1;
                                i1 = i1 ^ 1;
                            }
                            break;
                    }
                }
                if (i1 == 0 && i0 == 0) {
                    and ^= 1 << bit;
                }
                if (i1 == 1 && i0 == 1) {
                    or |= 1 << bit;
                }
                if (i1 == 0 && i0 == 1) {
                    xor ^= 1 << bit;
                }
            }

            out.println(3);
            out.println("| " + or);
            out.println("& " + and);
            out.println("^ " + xor);
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