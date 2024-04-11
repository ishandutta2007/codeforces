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
import java.util.LinkedList;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        HashMap<Integer, Integer> preu;
        HashMap<Integer, Integer> prev;
        HashMap<Integer, Integer> du;
        HashMap<Integer, Integer> dv;
        int u;
        int v;
        int p;

        void f(HashMap<Integer, Integer> d, HashMap<Integer, Integer> pre, LinkedList<Integer> q, int cur, int par) {
            if (d.containsKey(cur)) return;
            d.put(cur, d.get(par) + 1);
            pre.put(cur, par);
            q.add(cur);
        }

        void construct(OutputWriter out, int lu, int lv, int dir) {
            ArrayList<Integer> moves = new ArrayList<>();
            int ol = lu;
            while (preu.get(lu) != -1) {
                int g = preu.get(lu);
                if ((g + 1) % p == lu) moves.add(1);
                else if ((g - 1 + p) % p == lu) moves.add(2);
                else moves.add(3);
                lu = g;
            }
            Collections.reverse(moves);
            while (ol != lv) {
                ol += dir;
                if (ol >= p) ol -= p;
                if (ol < 0) ol += p;
                moves.add(dir == +1 ? 1 : 2);
            }
            while (prev.get(lv) != -1) {
                int n = prev.get(lv);
                if ((lv + 1) % p == n) moves.add(1);
                else if ((lv - 1 + p) % p == n) moves.add(2);
                else moves.add(3);
                lv = n;
            }

            out.println(moves.size());
            for (int k : moves) {
                out.println(k);
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            u = in.nextInt();
            v = in.nextInt();
            p = in.nextInt();
            preu = new HashMap<>();
            prev = new HashMap<>();
            du = new HashMap<>();
            dv = new HashMap<>();
            preu.put(u, -1);
            du.put(u, 0);
            prev.put(v, -1);
            dv.put(v, 0);

            LinkedList<Integer> qu = new LinkedList<>(), qv = new LinkedList<>();
            qu.add(u);
            qv.add(v);
            while (true) {
                int xu = qu.removeFirst();
                for (int i = 0; i + du.get(xu) <= 200; i++) {
                    Integer x = dv.get((xu + i) % p);
                    if (x != null && i + du.get(xu) + x <= 200) {
                        construct(out, xu, (xu + i) % p, +1);
                        return;
                    }
                    x = dv.get((xu - i + p) % p);
                    if (x != null && i + du.get(xu) + x <= 200) {
                        construct(out, xu, (xu - i + p) % p, -1);
                        return;
                    }
                }
                f(du, preu, qu, (xu - 1 + p) % p, xu);
                f(du, preu, qu, (xu + 1) % p, xu);
                f(du, preu, qu, (int) Utils.inv(xu, p), xu);

                int xv = qv.removeFirst();
                for (int i = 0; i + dv.get(xv) <= 200; i++) {
                    Integer x = du.get((xv + i) % p);
                    if (x != null && i + dv.get(xv) + x <= 200) {
                        construct(out, (xv + i) % p, xv, -1);
                        return;
                    }
                    x = du.get((xv - i + p) % p);
                    if (x != null && i + dv.get(xv) + x <= 200) {
                        construct(out, (xv - i + p) % p, xv, +1);
                        return;
                    }
                }
                f(dv, prev, qv, (xv - 1 + p) % p, xv);
                f(dv, prev, qv, (xv + 1) % p, xv);
                f(dv, prev, qv, (int) Utils.inv(xv, p), xv);
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

    static class Utils {
        public static long inv(long N, long M) {
            long x = 0, lastx = 1, y = 1, lasty = 0, q, t, a = N, b = M;
            while (b != 0) {
                q = a / b;
                t = a % b;
                a = b;
                b = t;
                t = x;
                x = lastx - q * x;
                lastx = t;
                t = y;
                y = lasty - q * y;
                lasty = t;
            }
            return (lastx + M) % M;
        }

    }
}