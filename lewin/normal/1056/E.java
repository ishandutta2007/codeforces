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
import java.math.BigInteger;
import java.util.Random;
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
        ECheckTranscription solver = new ECheckTranscription();
        solver.solve(1, in, out);
        out.close();
    }

    static class ECheckTranscription {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] s = in.next().toCharArray();
            String rr = in.next();
            char[] t = rr.toCharArray();
            int c0 = 0, c1 = 0;
            for (char c : s)
                if (c == '0') c0++;
                else c1++;
            if (s[0] == '1') {
                for (int i = 0; i < s.length; i++) {
                    s[i] = (char) (s[i] ^ '0' ^ '1');
                }
                int x = c0;
                c0 = c1;
                c1 = x;
            }
            Hashing hs = new Hashing(rr);
            int[] zz = ZAlgorithm.zAlgorithm(t);
            int ans = 0;
            for (int l0 = 1; c0 * l0 < t.length; l0++) {
                if (((t.length - c0 * l0) % c1) != 0) continue;
                int l1 = (t.length - c0 * l0) / c1;
                if (l0 == l1) {
                    if (rr.substring(0, rr.length() - l0).equals(rr.substring(l0))) {
                        continue;
                    }
                }
                int cpos = 0;
                boolean ok = true;
                boolean first = true;
                long hh = 0;
                for (int i = 0; ok && i < s.length; i++) {
                    if (s[i] == '0') {
                        if (zz[cpos] < l0) {
                            ok = false;
                        }
                        cpos += l0;
                    } else {
                        if (first) {
                            hh = hs.getHash(cpos, l1);
                            first = false;
                        }
                        if (hs.getHash(cpos, l1) != hh) {
                            ok = false;
                        }
                        cpos += l1;
                    }
                }
                if (ok) ans++;
            }
            out.println(ans);

//        if (c0 == 1) {
//            if (c1 == 1) {
//                int ans = s.length - 1;
//                if (t.length() % 2 == 0 && t.substring(0, t.length() / 2).equals(t.substring(t.length() / 2))) {
//                    ans--;
//                }
//                out.println(ans);
//                return;
//            }
//
//            int b1 = 0, a1 = 0;
//            for (int i = 0; i < s.length; i++) {
//                if (s[i] == '0') break;
//                b1++;
//            }
//            for (int i = s.length-1; i >= 0; i--) {
//                if (s[i] == '0') break;
//                a1++;
//            }
//
//            for (int l1 = 1; l1 <=
//        }
        }

    }

    static class Hashing {
        static final int multiplier = 43;
        static final Random rnd = new Random();
        static final int mod1 = BigInteger.valueOf((int) (1e9 + rnd.nextInt((int) 1e9))).nextProbablePrime().intValue();
        static final int mod2 = BigInteger.valueOf((int) (1e9 + rnd.nextInt((int) 1e9))).nextProbablePrime().intValue();
        static final int invMultiplier1 = BigInteger.valueOf(multiplier).modInverse(BigInteger.valueOf(mod1)).intValue();
        static final int invMultiplier2 = BigInteger.valueOf(multiplier).modInverse(BigInteger.valueOf(mod2)).intValue();
        long[] hash1;
        long[] hash2;
        long[] inv1;
        long[] inv2;
        int n;

        public Hashing(String s) {
            n = s.length();
            hash1 = new long[n + 1];
            hash2 = new long[n + 1];
            inv1 = new long[n + 1];
            inv2 = new long[n + 1];
            inv1[0] = 1;
            inv2[0] = 1;

            long p1 = 1;
            long p2 = 1;
            for (int i = 0; i < n; i++) {
                hash1[i + 1] = (hash1[i] + s.charAt(i) * p1) % mod1;
                p1 = p1 * multiplier % mod1;
                inv1[i + 1] = inv1[i] * invMultiplier1 % mod1;
                hash2[i + 1] = (hash2[i] + s.charAt(i) * p2) % mod2;
                p2 = p2 * multiplier % mod2;
                inv2[i + 1] = inv2[i] * invMultiplier2 % mod2;
            }
        }

        public long getHash(int i, int len) {
            return (((hash1[i + len] - hash1[i] + mod1) * inv1[i] % mod1) << 32)
                    + (hash2[i + len] - hash2[i] + mod2) * inv2[i] % mod2;
        }

    }

    static class ZAlgorithm {
        public static int[] zAlgorithm(char[] let) {
            int N = let.length;
            int[] z = new int[N];
            int L = 0, R = 0;
            for (int i = 1; i < N; i++) {
                if (i > R) {
                    L = R = i;
                    while (R < N && let[R - L] == let[R])
                        R++;
                    z[i] = R - L;
                    R--;
                } else {
                    int k = i - L;
                    if (z[k] < R - i + 1)
                        z[i] = z[k];
                    else {
                        L = i;
                        while (R < N && let[R - L] == let[R])
                            R++;
                        z[i] = R - L;
                        R--;
                    }
                }
            }
            z[0] = N;
            return z;
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