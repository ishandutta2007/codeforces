import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
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
        AStringTransformation1 solver = new AStringTransformation1();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class AStringTransformation1 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            char[] a = in.next().toCharArray();
            char[] b = in.next().toCharArray();
            for (int i = 0; i < n; i++) {
                if (a[i] > b[i]) {
                    out.println(-1);
                    return;
                }
            }
            HashSet<Character> interesting = new HashSet<>();
            int A = 26;
            boolean[][] conn = new boolean[A][A];
            for (int i = 0; i < A; i++) conn[i][i] = true;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    conn[a[i] - 'a'][b[i] - 'a'] = true;
                    conn[b[i] - 'a'][a[i] - 'a'] = true;
                }
            }
            for (int k = 0; k < A; k++) {
                for (int i = 0; i < A; i++) {
                    for (int j = 0; j < A; j++) {
                        conn[i][j] |= conn[i][k] && conn[k][j];
                    }
                }
            }
            int ed = 0;
            boolean[] vis = new boolean[A];
            for (int i = 0; i < A; i++) {
                if (!vis[i]) {
                    int c = 0;
                    for (int j = 0; j < A; j++) {
                        if (conn[i][j]) {
                            c++;
                            vis[j] = true;
                        }
                    }
                    ed += c - 1;
                }
            }
            out.println(ed);
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}