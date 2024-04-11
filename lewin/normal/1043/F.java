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
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        FMakeItOne solver = new FMakeItOne();
        solver.solve(1, in, out);
        out.close();
    }

    static class FMakeItOne {
        int maxn = 300010;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            int gcd = arr[0];
            for (int i = 1; i < n; i++) {
                gcd = Utils.gcd(arr[i], gcd);
            }
            if (gcd != 1) {
                out.println(-1);
                return;
            }
            arr = AUtils.unique(arr);
            n = arr.length;

            long[] count = new long[maxn];
            for (int x : arr) count[x]++;
            if (count[1] > 0) {
                out.println(1);
                return;
            }
            for (int i = 1; i < maxn; i++) {
                for (int j = i + i; j < maxn; j += i) {
                    count[i] += count[j];
                }
            }
            long[] r = Arrays.copyOf(count, maxn);
            int ans = 1;
            while (true) {
                for (int j = 1; j < maxn; j++) {
                    r[j] = r[j] * count[j];
                }
                long[] tmp = Arrays.copyOf(r, maxn);
                for (int i = maxn - 1; i >= 1; i--) {
                    for (int j = i + i; j < maxn; j += i) {
                        tmp[i] -= tmp[j];
                    }
                }
                ans++;
                if (tmp[1] != 0) break;
            }
            out.println(ans);
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
        private byte[] buf = new byte[1 << 20];
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

    static class AUtils {
        public static void sort(int[] arr) {
            for (int i = 1; i < arr.length; i++) {
                int j = (int) (Math.random() * (i + 1));
                if (i != j) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
            Arrays.sort(arr);
        }

        public static int[] unique(int[] a) {
            a = a.clone();
            sort(a);
            int sz = 1;
            for (int i = 1; i < a.length; i++) {
                if (a[i] != a[sz - 1]) {
                    a[sz++] = a[i];
                }
            }
            return Arrays.copyOf(a, sz);
        }

    }

    static class Utils {
        public static int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }

    }
}