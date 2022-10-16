import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        TaskH solver = new TaskH();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskH {
        long all;
        int d;
        int m;
        int[] gen;
        int bits = 8;
        int sections;
        HashMap<Long, Long>[][] mp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            d = in.nextInt();
            m = in.nextInt();
            sections = (m + bits - 1) / bits;
            all = (1L << m) - 1;
            gen = in.readIntArray(d);
            int n = in.nextInt();
            ArrayList<Long> masks = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                masks.add((1L << (in.nextInt() + 1)) - 1);
            }
            long l = in.nextLong(), r = in.nextLong();
            l-=1;
            r-=1;
            mp = new HashMap[sections][1 << bits];
            for (int i = 0; i < sections; i++) for (int j = 0; j < 1 << bits; j++) mp[i][j] = new HashMap<>();
            out.println(count(masks, r + 2 - n) - count(masks, l));
        }

        long rotateRight(long x, int distance) {
            return ((x >> distance) | ((x & ((1L << distance) - 1)) << (m - distance)));
        }

        ArrayList<int[]> getNext(int shift, int section, int mask) {
            long cmask = mask;
            cmask <<= (long) section * bits;
            cmask = rotateRight(cmask, shift);
            ArrayList<int[]> ret = new ArrayList<>();
            for (int i = 0; i < sections; i++) {
                int csec = (int) (cmask & ((1 << bits) - 1));
                if (csec != 0) {
                    ret.add(new int[]{i, csec});
                }
                cmask >>= bits;
            }
            return ret;
        }

        long count(int section, int mask, long mx) {
            if (mx == 0) return 0;
            if (mx == 1) {
                return (section == 0 && ((mask & 1) == 1)) ? 1 : 0;
            }
            Long r = mp[section][mask].get(mx);
            if (r != null) return r;
            long bd = 1;
            while (bd < (mx + d - 1) / d) bd *= d;

            long ans = 0;
            for (int i = 0; i < (mx + bd - 1) / bd; i++) {
                long nmx = (i == (mx + bd - 1) / bd - 1) ? ((mx - 1) % bd + 1) : bd;
                for (int[] x : getNext(gen[i], section, mask)) {
                    ans += count(x[0], x[1], nmx);
                }
            }
            mp[section][mask].put(mx, ans);
            return ans;
        }

        long count(ArrayList<Long> masks, long mx) {
            if (masks.size() == 1) {
                long ans = 0;
                long mask = masks.get(0);
                for (int j = 0; j < sections; j++) {
                    ans += count(j, (int) (mask & ((1 << bits) - 1)), mx);
                    mask >>= bits;
                }
                return ans;
            }
            long ans = 0;
            for (int start = 0; start < d && start < mx; start++) {
                ArrayList<Long> nextmask = new ArrayList<>();
                long cmask = all;
                int cp = start;
                for (int i = 0; i < masks.size(); i++) {
                    if (i > 0 && cp == 0) {
                        nextmask.add(cmask);
                        cmask = all;
                    }
                    cmask &= rotateRight(masks.get(i), gen[cp]);
                    if (++cp == d) cp = 0;
                }
                nextmask.add(cmask);
                ans += count(nextmask, (mx - start + d - 1) / d);
            }
            return ans;
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
}