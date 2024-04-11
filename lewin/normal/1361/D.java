import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        FJohnnyAndJames solver = new FJohnnyAndJames();
        solver.solve(1, in, out);
        out.close();
    }

    static class FJohnnyAndJames {
        int n;
        int k;

        void add(HashMap<Fraction, List<Integer>> t, Fraction key, int value) {
            t.computeIfAbsent(key, k1 -> new ArrayList<>()).add(value);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            HashMap<Fraction, List<Integer>>[] f = new HashMap[2];
            for (int i = 0; i < 2; i++) f[i] = new HashMap<>();
            double[] dists = new double[n];
            for (int i = 0; i < n; i++) {
                long x = in.nextLong(), y = in.nextLong();
                dists[i] = Math.sqrt(x * x + y * y);
                if (x == 0 && y == 0) continue;
                Fraction g = new Fraction(x, y);
                if (y > 0 || (y == 0 && x > 0)) {
                    add(f[0], g, i);
                } else {
                    add(f[1], g, i);
                }
            }
            double[] vs = new double[n];
            for (int qq = 0; qq < 2; qq++) {
                for (List<Integer> lst : f[qq].values()) {
                    lst.sort(Comparator.comparingDouble(x -> -dists[x]));
                    int i = 0, j = lst.size() - 1;
                    double sd = 0;
                    while (i <= j) {
                        double k1 = (k - 2 * i - 1) * dists[lst.get(i)] - sd;
                        double k2 = (k - 2 * i - 1) * dists[lst.get(j)] - sd;
                        if (k1 >= k2) {
                            vs[lst.get(i)] = k1;
                            i++;
                        } else {
                            vs[lst.get(j)] = k2;
                            sd += 2 * dists[lst.get(j)];
                            j--;
                        }
                    }
                }
            }
            AUtils.sort(vs);
            AUtils.reverse(vs);
            double res = 0;
            for (int i = 0; i < k; i++) {
                res += vs[i];
            }
            out.printf("%.10f\n", res);
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

    }

    static class Fraction {
        public long x;
        public long y;

        public Fraction(long x, long y) {
            if (x < 0) {
                x = -x;
                y = -y;
            } else if (x == 0) {
                y = Math.abs(y);
            }

            long g = Utils.gcd(Math.abs(x), Math.abs(y));
            if (g != 0) {
                x /= g;
                y /= g;
            } else {
                if (x != 0) x = 1;
                if (y != 0) y = 1;
            }
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "Fraction{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }

        public int hashCode() {
            return new Long(x * 12091379 + y).hashCode();
        }

        public boolean equals(Object other) {
            if (!(other instanceof Fraction)) return false;
            return ((Fraction) other).x == x && ((Fraction) other).y == y;
        }

    }

    static class AUtils {
        public static void reverse(double[] arr) {
            for (int i = 0, j = arr.length - 1; i < j; i++, j--) {
                double t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }

        public static void sort(double[] arr) {
            shuffle(arr);
            Arrays.sort(arr);
        }

        public static void shuffle(double[] arr) {
            for (int i = 1; i < arr.length; i++) {
                int j = (int) (Math.random() * (i + 1));
                if (i != j) {
                    double t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
        }

    }

    static class Utils {
        public static long gcd(long x, long y) {
            for (; x != 0; x ^= y, y ^= x, x ^= y, x %= y) ;
            return y;
        }

    }
}