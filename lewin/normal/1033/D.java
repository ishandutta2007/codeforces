import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        DDivisors solver = new DDivisors();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDivisors {
        public static final int mod = 998244353;
        HashMap<Long, Integer> pp;

        public void put(long key, int value) {
            Integer r = pp.get(key);
            if (r == null) r = 0;
            pp.put(key, r + value);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            pp = new HashMap<>();
            ArrayList<Long> semiprimes = new ArrayList<>();
            while (n-- > 0) {
                long a = in.nextLong();
                long t = getFourth(a);
                if (t != -1) {
                    put(t, 4);
                    continue;
                }
                t = getCube(a);
                if (t != -1) {
                    put(t, 3);
                    continue;
                }
                t = getSquare(a);
                if (t != -1) {
                    put(t, 2);
                    continue;
                }
                semiprimes.add(a);
            }
            Collections.sort(semiprimes);
            boolean[] mark = new boolean[semiprimes.size()];
            for (int i = 0; i < semiprimes.size(); i++) {
                if (mark[i]) continue;
                for (int j = i + 1; j < semiprimes.size(); j++) {
                    if (mark[j]) continue;
                    long t = Utils.gcd(semiprimes.get(i), semiprimes.get(j));
                    if (t != 1 && t < semiprimes.get(i)) {
                        put(t, 2);
                        put(semiprimes.get(i) / t, 1);
                        put(semiprimes.get(j) / t, 1);
                        mark[i] = true;
                        mark[j] = true;
                        break;
                    }
                }
            }
            for (int i = 0; i < semiprimes.size(); i++) {
                if (!mark[i]) {
                    for (long k : pp.keySet()) {
                        if (semiprimes.get(i) % k == 0) {
                            put(k, 1);
                            put(semiprimes.get(i) / k, 1);
                            mark[i] = true;
                            break;
                        }
                    }
                }
            }


            long res = 1;
            for (int x : pp.values()) {
                res = res * (x + 1) % mod;
            }
            for (int i = 0; i < semiprimes.size(); i++) {
                if (!mark[i]) {
                    int ff = 1;
                    while (i + 1 < semiprimes.size() && semiprimes.get(i + 1).equals(semiprimes.get(i))) {
                        ff++;
                        i++;
                    }
                    res = res * (ff + 1) % mod;
                    res = res * (ff + 1) % mod;
                }
            }
            out.println(res);
        }

        public long getSquare(long a) {
            long lo = 1, hi = 1500000000;
            while (lo < hi) {
                long mid = (lo + hi) / 2;
                if (mid * mid < a) lo = mid + 1;
                else hi = mid;
            }
            if (lo * lo == a) return lo;
            return -1;
        }

        public long getCube(long a) {
            long lo = 1, hi = 1259922;
            while (lo < hi) {
                long mid = (lo + hi) / 2;
                if (mid * mid * mid < a) lo = mid + 1;
                else hi = mid;
            }
            if (lo * lo * lo == a) return lo;
            return -1;
        }

        public long getFourth(long a) {
            long lo = 1, hi = 37607;
            while (lo < hi) {
                long mid = (lo + hi) / 2;
                if (mid * mid * mid * mid < a) lo = mid + 1;
                else hi = mid;
            }
            if (lo * lo * lo * lo == a) return lo;
            return -1;
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

    static class Utils {
        public static long gcd(long x, long y) {
            for (; x != 0; x ^= y, y ^= x, x ^= y, x %= y) ;
            return y;
        }

    }
}