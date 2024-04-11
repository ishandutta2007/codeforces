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
import java.util.Comparator;
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
        ETheFairNutAndRectangles solver = new ETheFairNutAndRectangles();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETheFairNutAndRectangles {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            ETheFairNutAndRectangles.Rectangle[] rs = new ETheFairNutAndRectangles.Rectangle[n];
            for (int i = 0; i < n; i++) {
                int x = in.nextInt(), y = in.nextInt();
                long a = in.nextLong();
                rs[i] = new ETheFairNutAndRectangles.Rectangle(x, y, a);
            }
            Arrays.sort(rs, Comparator.comparingInt(x -> x.x));
            long[] dp = new long[n + 1];
            ConvexHullOptimization ch = new ConvexHullOptimization();
            ch.addLine(0, 0);
            for (int i = 1; i <= n; i++) {
                dp[i] = -ch.minValue(-rs[i - 1].y) + 1L * rs[i - 1].x * rs[i - 1].y - rs[i - 1].a;
                ch.addLine(-rs[i - 1].x, -dp[i]);
            }
            out.println(AUtils.max(dp));

        }

        static class Rectangle {
            public int x;
            public int y;
            public long a;

            public Rectangle(int x, int y, long a) {
                this.x = x;
                this.y = y;
                this.a = a;
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }

    static class AUtils {
        public static long max(long[] arr) {
            long res = arr[0];
            for (long x : arr) if (x > res) res = x;
            return res;
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

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class ConvexHullOptimization {
        long[] A = new long[1000010];
        long[] B = new long[1000010];
        int len;
        int ptr;

        public void addLine(long a, long b) {
            // intersection of (A[len-2],B[len-2]) with (A[len-1],B[len-1]) must lie to the left of intersection of (A[len-1],B[len-1]) with (a,b)
//        while (len >= 2 && (B[len - 2] - B[len - 1]) * (a - A[len - 1]) >= (B[len - 1] - b) * (A[len - 1] - A[len - 2])) {
//            --len;
//        }
            while (len >= 2 && (double) (B[len - 2] - B[len - 1]) / (A[len - 1] - A[len - 2]) >= (double) (B[len - 1] - b) / (a - A[len - 1])) {
                --len;
            }
            A[len] = a;
            B[len] = b;
            ++len;
            ptr = Math.min(ptr, len - 1);
        }

        public long minValue(long x) {
            ptr = Math.min(ptr, len - 1);
            while (ptr + 1 < len && A[ptr + 1] * x + B[ptr + 1] <= A[ptr] * x + B[ptr]) {
                ++ptr;
            }
            return A[ptr] * x + B[ptr];
        }

    }
}