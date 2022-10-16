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
        EBalancedBinarySearchTrees solver = new EBalancedBinarySearchTrees();
        solver.solve(1, in, out);
        out.close();
    }

    static class EBalancedBinarySearchTrees {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] r = new int[]{1, 2, 4, 5, 9, 10, 20, 21, 41, 42, 84, 85, 169, 170, 340, 341, 681, 682, 1364, 1365, 2729, 2730, 5460, 5461, 10921, 10922, 21844, 21845, 43689, 43690, 87380, 87381, 174761, 174762, 349524, 349525, 699049, 699050};
            boolean print = false;
            for (int j : r)
                if (n == j) {
                    out.println(1);
                    print = true;
                }
            if (!print) out.println(0);
//        dp = new int[2][n+1];
//        AUtils.deepFill(dp, -1);
//        out.println((count(n, 0) + count(n, 1)) % mod);
//        dp = new int[2][1000000+1];
//        AUtils.deepFill(dp, -1);
//        ArrayList<Integer> tt = new ArrayList<>();
//        int ct = 0;
//        int sh = 0;
//        for (int n = 1; n <= 1000000; n++) {
//            mxn = n-10;
//            long ans = (count(n, 0) + count(n, 1)) % mod;
//            if (ans != 0) {
//                Debug.print(n,ans);
//                tt.add(n);
//                sh = 1;
////                Debug.print(n,Integer.toString(n,2));
//            }
//            ct += sh;
//            if (ct == 5) {
//                n = Math.max(n, n * 2 - 10);
//                ct = 0;
//                sh = 0;
//            }
//        }
//        out.println(tt);
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
}