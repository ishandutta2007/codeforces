import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public int LOG = 20;
        public int[][] a0;
        public int[][] a1;
        public int[][] bs;
        public HashMap<Pair<Integer, Integer>, Integer> mp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[][] arr = new int[2][n + 1];
            for (int i = 1; i <= n; i++) arr[0][i] = in.nextInt();
            for (int i = 1; i <= n; i++) arr[1][i] = in.nextInt();
            int[] brr = new int[n + 1];
            for (int i = 1; i <= n; i++) brr[i] = arr[0][i] + arr[1][i];

            a0 = getJumps(arr[0]);
            a1 = getJumps(arr[1]);
            bs = getJumps(brr);

            mp = new HashMap<>();
            out.println(solve(n, n));
        }

        public int solve(int l0, int l1) {
            Pair<Integer, Integer> xx = new Pair<>(l0, l1);
            Integer d = mp.get(xx);
            if (d != null) return d;
            if (a0[0][l0] >= l1) return 1 + solve(a0[0][l0], l1);
            if (a1[0][l1] >= l0) return 1 + solve(l0, a1[0][l1]);

            int res = 0;
            int w = bs[0][Math.min(l0, l1)];
            if (w >= 0) res = 1 + solve(w, w);
            if (a0[0][l0] >= 0)
                res = Math.max(res, 1 + solve(a0[0][l0], l1));
            if (a1[0][l1] >= 0)
                res = Math.max(res, 1 + solve(l0, a1[0][l1]));
            mp.put(xx, res);
            return res;
        }

        public int[][] getJumps(int[] arr) {
            int n = arr.length;
            HashMap<Long, Integer> mp = new HashMap<>();
            int[][] anc = new int[LOG][n];
            long csum = 0;
            anc[0][0] = -1;
            mp.put(csum, 0);
            for (int i = 1; i < n; i++) {
                csum += arr[i];
                anc[0][i] = Math.max(anc[0][i - 1], mp.getOrDefault(csum, -1));
                mp.put(csum, i);
            }

            for (int level = 1; level < LOG; level++) {
                anc[level][0] = -1;
                for (int i = 1; i < n; i++) {
                    anc[level][i] = Math.max(anc[level][i - 1], (anc[level - 1][i] == -1 ? -1 : anc[level - 1][anc[level - 1][i]]));
                }
            }
            return anc;
        }

    }

    static class Pair<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<Pair<U, V>> {
        public final U u;
        public final V v;

        public Pair(U u, V v) {
            this.u = u;
            this.v = v;
        }

        public int hashCode() {
            return (u == null ? 0 : u.hashCode() * 31) + (v == null ? 0 : v.hashCode());
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<U, V> p = (Pair<U, V>) o;
            return (u == null ? p.u == null : u.equals(p.u)) && (v == null ? p.v == null : v.equals(p.v));
        }

        public int compareTo(Pair<U, V> b) {
            int cmpU = u.compareTo(b.u);
            return cmpU != 0 ? cmpU : v.compareTo(b.v);
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