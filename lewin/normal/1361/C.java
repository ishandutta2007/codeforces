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
        GJohnnyAndMegansNecklace solver = new GJohnnyAndMegansNecklace();
        solver.solve(1, in, out);
        out.close();
    }

    static class GJohnnyAndMegansNecklace {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] perm = new int[2 * n];
            perm = in.readIntArray(2 * n);
            for (int k = 20; k >= 0; k--) {
                int[] tp = new int[2 * n];
                for (int i = 0; i < 2 * n; i++) {
                    tp[i] = perm[i] & ((1 << k) - 1);
                }
                int[] partner = new int[2 * n];
                HashMap<Integer, Integer> last = new HashMap<>();
                for (int i = 0; i < 2 * n; i++) {
                    Integer x = last.get(tp[i]);
                    if (x != null) {
                        partner[x] = i;
                        partner[i] = x;
                        last.remove(tp[i]);
                    } else {
                        last.put(tp[i], i);
                    }
                }
                if (last.size() > 0) continue;
                HashMap<Integer, GJohnnyAndMegansNecklace.Pair> p1 = new HashMap<>();
                int[] next = new int[2 * n];
                int[] par = DisjointSets.createSets(2 * n);
                boolean[] vis = new boolean[2 * n];
                for (int i = 0; i < 2 * n; i++) {
                    if (vis[i]) continue;
                    int cur = i;
                    int pp = -1;
                    do {
                        DisjointSets.unite(par, cur, i);
                        DisjointSets.unite(par, cur ^ 1, i);

                        vis[cur] = true;
                        vis[cur ^ 1] = true;

                        next[cur] = cur ^ 1;
                        if (pp != -1) {
                            next[pp] = cur;
                            GJohnnyAndMegansNecklace.Pair q = p1.get(tp[cur]);
                            if (q != null) {
                                int a = DisjointSets.root(par, q.rt);
                                int b = DisjointSets.root(par, i);
                                if (a != b) {
                                    next[pp] = q.b;
                                    next[q.a] = cur;
                                    DisjointSets.unite(par, a, b);
                                    p1.put(tp[cur], new GJohnnyAndMegansNecklace.Pair(q.a, cur, i));
                                }
                            } else {
                                p1.put(tp[cur], new GJohnnyAndMegansNecklace.Pair(pp, cur, i));
                            }
                        }
                        pp = cur ^ 1;
                        cur = partner[cur ^ 1];
                    } while (cur != i);

                    next[pp] = cur;
                    GJohnnyAndMegansNecklace.Pair q = p1.get(tp[i]);
                    if (q != null) {
                        int a = DisjointSets.root(par, q.rt);
                        int b = DisjointSets.root(par, i);
                        if (a != b) {
                            next[pp] = q.b;
                            next[q.a] = cur;
                            DisjointSets.unite(par, a, b);
                            p1.put(tp[cur], new GJohnnyAndMegansNecklace.Pair(q.a, cur, i));
                        }
                    } else {
                        p1.put(tp[cur], new GJohnnyAndMegansNecklace.Pair(pp, cur, i));
                    }
                }
                boolean ok = true;
                for (int i = 0; i < 2 * n; i++) {
                    if (DisjointSets.root(par, i) != DisjointSets.root(par, 0)) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;

                out.println(k);
                int cur = 0;
                if (next[cur] != 1) cur = next[cur];
                for (int i = 0; i < 2 * n; i++) {
                    if (i != 0) out.print(" ");
                    out.print(cur + 1);
                    cur = next[cur];
                }
                out.println();
                return;
            }
        }

        static class Pair {
            public int a;
            public int b;
            public int rt;

            public Pair(int a, int b, int rt) {
                this.a = a;
                this.b = b;
                this.rt = rt;
            }

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

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class DisjointSets {
        public static int[] createSets(int size) {
            int[] p = new int[size];
            for (int i = 0; i < size; i++)
                p[i] = i;
            return p;
        }

        public static int root(int[] p, int x) {
            return x == p[x] ? x : (p[x] = root(p, p[x]));
        }

        public static boolean unite(int[] p, int a, int b) {
            a = root(p, a);
            b = root(p, b);
            if (a != b) {
                if (Math.random() < 0.5)
                    p[a] = b;
                else
                    p[b] = a;
                return true;
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}