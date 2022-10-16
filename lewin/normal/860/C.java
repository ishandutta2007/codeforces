import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public HashSet<String> a;
        public HashSet<String> b;
        public HashSet<String> alls;
        public HashSet<String> bada;
        public HashSet<String> badb;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            a = new HashSet<>();
            b = new HashSet<>();
            alls = new HashSet<>();
            bada = new HashSet<>();
            badb = new HashSet<>();
            for (int i = 0; i < n; i++) {
                String s = in.next();
                int type = in.nextInt();
                if (type == 1) a.add(s);
                else b.add(s);
                alls.add(s);
            }
            List<TaskC.Operation> res = new ArrayList<>();
            int e = a.size();
            int x = n + 1;
            while (alls.contains(String.valueOf(x))) {
                x++;
            }
            String temp = String.valueOf(x);
            boolean[] good = new boolean[n + 1];
            boolean[] free = new boolean[n + 1];
            int freea = 0, freeb = 0;
            for (int i = 1; i <= e; i++) {
                String t = String.valueOf(i);
                if (a.contains(t)) {
                    good[i] = true;
                    a.remove(t);
                } else if (b.contains(t)) {
                    badb.add(t);
                    b.remove(t);
                } else {
                    free[i] = true;
                    freea++;
                }
            }
            for (int i = e + 1; i <= n; i++) {
                String t = String.valueOf(i);
                if (b.contains(t)) {
                    good[i] = true;
                    b.remove(t);
                } else if (a.contains(t)) {
                    bada.add(t);
                    a.remove(t);
                } else {
                    free[i] = true;
                    freeb++;
                }
            }

            List<String> la = new ArrayList<>(bada), lb = new ArrayList<>(badb);
            List<String> fa = new ArrayList<>(), fb = new ArrayList<>();
            for (int i = 1; i <= e; i++) if (free[i]) fa.add(String.valueOf(i));
            for (int i = e + 1; i <= n; i++) if (free[i]) fb.add(String.valueOf(i));
            List<String> ob = new ArrayList<>(b), oa = new ArrayList<>(a);

            while (la.size() > 0 || lb.size() > 0) {
                while (fa.size() > 0 || fb.size() > 0) {
                    boolean changed = false;
                    while (fa.size() > 0 && la.size() > 0) {
                        String s;
                        res.add(new TaskC.Operation(s = la.remove(la.size() - 1), fa.remove(fa.size() - 1)));
                        fb.add(s);
                        changed = true;
                    }
                    while (fb.size() > 0 && lb.size() > 0) {
                        String s;
                        res.add(new TaskC.Operation(s = lb.remove(lb.size() - 1), fb.remove(fb.size() - 1)));
                        fa.add(s);
                        changed = true;
                    }
                    if (!changed) break;
                }

                if (lb.size() > 0) {
                    String s;
                    res.add(new TaskC.Operation(s = lb.remove(lb.size() - 1), temp));
                    ob.add(temp);
                    fa.add(s);
                } else if (la.size() > 0) {
                    String s;
                    res.add(new TaskC.Operation(s = la.remove(la.size() - 1), temp));
                    oa.add(temp);
                    fb.add(s);
                }
                temp = String.valueOf(++x);
            }

            for (int i = 0; i < fa.size(); i++) {
                res.add(new TaskC.Operation(oa.get(i), fa.get(i)));
            }
            for (int i = 0; i < fb.size(); i++) {
                res.add(new TaskC.Operation(ob.get(i), fb.get(i)));
            }


            out.println(res.size());
            for (TaskC.Operation o : res) {
                out.printf("move %s %s\n", o.from, o.to);
            }


        }

        static class Operation {
            public String from;
            public String to;

            public Operation(String from, String to) {
                this.from = from;
                this.to = to;
            }

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

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}