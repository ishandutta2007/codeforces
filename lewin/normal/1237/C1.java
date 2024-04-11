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
        C1BalancedRemovalsEasier solver = new C1BalancedRemovalsEasier();
        solver.solve(1, in, out);
        out.close();
    }

    static class C1BalancedRemovalsEasier {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            ArrayList<C1BalancedRemovalsEasier.Point> ps = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                ps.add(new C1BalancedRemovalsEasier.Point(in.nextInt(), in.nextInt(), in.nextInt(), i + 1));
            }
            for (int i = 0; i < 3; i++) {
                for (int j = i + 1; j < 3; j++) {
                    int r = 3 - i - j;
                    ps.sort(Comparator.comparingInt(x -> x.cs[r]));
                    HashMap<Pair<Integer, Integer>, C1BalancedRemovalsEasier.Point> mp = new HashMap<>();
                    for (C1BalancedRemovalsEasier.Point x : ps) {
                        Pair<Integer, Integer> k = new Pair<>(x.cs[i], x.cs[j]);
                        if (mp.containsKey(k)) {
                            C1BalancedRemovalsEasier.Point v = mp.remove(k);
                            out.println(x.idx + " " + v.idx);
                        } else {
                            mp.put(k, x);
                        }
                    }
                    ps = new ArrayList<>(mp.values());
                }
            }
            for (int i = 0; i < 3; i++) {
                if (i == 0) {
                    final int i1 = 1, i2 = 2;
                    ps.sort((a, b) -> (a.cs[i1] == b.cs[i1] ? a.cs[i2] - b.cs[i2] : a.cs[i1] - b.cs[i1]));
                } else if (i == 1) {
                    final int i1 = 0, i2 = 2;
                    ps.sort((a, b) -> (a.cs[i1] == b.cs[i1] ? a.cs[i2] - b.cs[i2] : a.cs[i1] - b.cs[i1]));
                } else {
                    final int i1 = 0, i2 = 1;
                    ps.sort((a, b) -> (a.cs[i1] == b.cs[i1] ? a.cs[i2] - b.cs[i2] : a.cs[i1] - b.cs[i1]));
                }

                HashMap<Integer, C1BalancedRemovalsEasier.Point> mp = new HashMap<>();
                for (C1BalancedRemovalsEasier.Point x : ps) {
                    if (mp.containsKey(x.cs[i])) {
                        C1BalancedRemovalsEasier.Point v = mp.remove(x.cs[i]);
                        out.println(x.idx + " " + v.idx);
                    } else {
                        mp.put(x.cs[i], x);
                    }
                }
                ps = new ArrayList<>(mp.values());


            }
            ps.sort((a, b) -> (a.cs[0] == b.cs[0] ? (a.cs[1] == b.cs[1] ? a.cs[2] - a.cs[2] : a.cs[1] - b.cs[1]) : a.cs[0] - b.cs[0]));
            for (int i = 0; i < ps.size(); i += 2) {
                out.println(ps.get(i).idx + " " + ps.get(i + 1).idx);
            }
        }

        static class Point {
            public int idx;
            public int[] cs;

            public Point(int x, int y, int z, int idx) {
                cs = new int[]{x, y, z};
                this.idx = idx;
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
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

        public String toString() {
            return String.format("[Pair = (%s, %s)", u.toString(), v.toString());
        }

    }
}