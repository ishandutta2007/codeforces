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
        CDrazilLikesHeap solver = new CDrazilLikesHeap();
        solver.solve(1, in, out);
        out.close();
    }

    static class CDrazilLikesHeap {
        int[] arr;
        int[] deep;
        int n;

        void f(int i) {
            int left = 2 * i, right = 2 * i + 1;
            if (left >= n || (arr[left] == 0 && arr[right] == 0)) {
                arr[i] = 0;
                return;
            } else {
                if (arr[left] > arr[right]) {
                    arr[i] = arr[left];
                    f(left);
                } else {
                    arr[i] = arr[right];
                    f(right);
                }
            }
            if (arr[left] == 0 && arr[right] == 0) {
                deep[i] = Integer.numberOfTrailingZeros(Integer.highestOneBit(i));
            } else if (arr[left] > arr[right]) {
                deep[i] = deep[left];
            } else {
                deep[i] = deep[right];
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int t = in.nextInt();
            arr = new int[1 << 20];
            deep = new int[1 << 20];
            while (t-- > 0) {
                int h = in.nextInt(), g = in.nextInt();
                n = (1 << h);
                for (int i = 1; i < (1 << h); i++) {
                    arr[i] = in.nextInt();
                    deep[i] = h - 1;
                }
                int[] operations = new int[(1 << h) - (1 << g)];
                int idx = 0;
                long sum = 0;
                for (int i = 1; i < (1 << g); i++) {
                    while (deep[i] >= g) {
                        operations[idx++] = i;
                        f(i);
                    }
                    sum += arr[i];
                }
                out.println(sum);
                out.println(operations);
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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}