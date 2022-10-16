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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] s = in.next().toCharArray();
            char[] t = in.next().toCharArray();

            int n = t.length;
            AUtils.sort(s);
            AUtils.sort(t);
            if (n == 1) {
                out.println(s[0]);
                return;
            }
            int ms = 0, mt = n - 1;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) ms++;
                else mt--;
            }

            int fs = 0, bs = ms - 1, ft = mt + 1, bt = n - 1;
            char[] res = new char[n];
            int a = 0, b = n - 1;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    if (t[bt] <= s[fs]) {
                        res[b--] = s[bs--];
                    } else {
                        res[a++] = s[fs++];
                    }
                } else {
                    if (s[fs] >= t[bt]) {
                        res[b--] = t[ft++];
                    } else {
                        res[a++] = t[bt--];
                    }
                }
            }
            out.println(new String(res));
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

        public void println(char i) {
            writer.println(i);
        }

        public void close() {
            writer.close();
        }

    }

    static class AUtils {
        public static void sort(char[] arr) {
            for (int i = 1; i < arr.length; i++) {
                int j = (int) (Math.random() * (i + 1));
                if (i != j) {
                    char t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
            Arrays.sort(arr);
        }

    }
}