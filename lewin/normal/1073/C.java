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
        CVasyaAndRobot solver = new CVasyaAndRobot();
        solver.solve(1, in, out);
        out.close();
    }

    static class CVasyaAndRobot {
        String ss = "UDLR";
        int[] dx = {0, 0, -1, +1};
        int[] dy = {+1, -1, 0, 0};
        int[][] ps;
        int ex;
        int ey;
        int x;
        int y;

        boolean can(int front, int back) {
            int cx = 0, cy = 0;
            for (int k = 0; k < 4; k++) {
                cx += dx[k] * (ps[k][back] - ps[k][front - 1]);
                cy += dy[k] * (ps[k][back] - ps[k][front - 1]);
            }
            int nx = x - (ex - cx);
            int ny = y - (ey - cy);
            int nn = back - front + 1;
            if ((nx + ny + 200000000) % 2 != nn % 2) {
                return false;
            }
            if (Math.abs(nx) + Math.abs(ny) > nn) {
                return false;
            }
            return true;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            String s = in.next();
            x = in.nextInt();
            y = in.nextInt();
            if ((x + y + 2000000000) % 2 != (n % 2)) {
                out.println(-1);
                return;
            }
            if (Math.abs(x) + Math.abs(y) > n) {
                out.println(-1);
                return;
            }
            ps = new int[4][n + 1];

            ex = 0;
            ey = 0;
            for (int i = 0; i < n; i++) {
                int k = ss.indexOf(s.charAt(i));
                for (int j = 0; j < 4; j++) ps[j][i + 1] = ps[j][i];
                ps[k][i + 1]++;
                ex += dx[k];
                ey += dy[k];
            }
            int best = n + 1;
            int front = 1;
            for (int i = 1; i <= n; i++) {
                while (front <= i && can(front + 1, i)) front++;
                if (can(front, i)) {
                    best = Math.min(best, i - front + 1);
                }
            }
            out.println(best > n ? -1 : best);

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 20];
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