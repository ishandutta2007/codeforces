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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public long a;
        public long b;
        public int pt;
        public int[] l;
        public int[] r;
        public int[] arr;
        public int ans;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            a = in.nextLong();
            b = in.nextLong();
            String sa = String.valueOf(a), sb = String.valueOf(b);
            while (sa.length() < sb.length()) sa = "0" + sa;
            int m = sa.length();
            l = new int[m];
            r = new int[m];
            for (int i = 0; i < m; i++) l[i] = sa.charAt(i) - '0';
            for (int i = 0; i < m; i++) r[i] = sb.charAt(i) - '0';
            arr = new int[10];
            long[] pow10 = new long[m + 1];
            pow10[0] = 1;
            for (int i = 1; i < pow10.length; i++) pow10[i] = pow10[i - 1] * 10;
            pt = 0;
            while (pt < m && l[pt] == r[pt]) {
                a -= pow10[m - pt - 1] * l[pt];
                b -= pow10[m - pt - 1] * l[pt];
                pt++;
            }
            if (pt == m) {
                out.println(1);
                return;
            }
            dfs(0, m - pt);
            out.println(ans);
        }

        public void dfs(int num, int left) {
            if (num == 9) {
                arr[9] = left;
                if (ok(arr)) {
                    ans++;
                }
            } else {
                for (int i = 0; i <= left; i++) {
                    arr[num] = i;
                    dfs(num + 1, left - i);
                }
            }
        }

        public boolean ok(int[] arr) {
            if (arr[r[pt]] > 0) {
                arr[r[pt]] -= 1;
                long g = r[pt];
                for (int dd = 0; dd <= 9; dd++) for (int k = 0; k < arr[dd]; k++) g = g * 10 + dd;
                arr[r[pt]]++;
                if (g <= b) {
                    return true;
                }
            }
            for (int cdig = r[pt] - 1; cdig >= l[pt] + 1; cdig--) {
                if (arr[cdig] > 0) {
                    return true;
                }
            }
            if (arr[l[pt]] > 0) {
                arr[l[pt]]--;
                long g = l[pt];
                for (int dd = 9; dd >= 0; dd--) for (int k = 0; k < arr[dd]; k++) g = g * 10 + dd;
                arr[l[pt]]++;
                if (g >= a) {
                    return true;
                }
            }
            return false;
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
}