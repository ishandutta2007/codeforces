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
import java.util.Map;
import java.util.Map.Entry;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), w = in.nextInt(), h = in.nextInt();
            HashMap<Integer, ArrayList<TaskB.Dancer>> mp = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int g = in.nextInt(), p = in.nextInt(), t = in.nextInt();
                int tt = p - t;
                ArrayList<TaskB.Dancer> x = mp.get(tt);
                if (x == null) mp.put(tt, x = new ArrayList<>());
                x.add(new TaskB.Dancer(i, g, p, t));
            }
            int[][] res = new int[n][2];
            int[] p1 = new int[n];
            for (Map.Entry<Integer, ArrayList<TaskB.Dancer>> e : mp.entrySet()) {
                ArrayList<TaskB.Dancer> x = e.getValue();
                Collections.sort(x, (a, b) -> (a.dir != b.dir) ? a.dir - b.dir : (a.dir == 1 ? (b.pos - a.pos) : (a.pos - b.pos)));
                for (int j = 0; j < x.size(); j++) p1[j] = x.get(j).idx;
                Collections.sort(x, (a, b) -> (a.dir != b.dir) ? b.dir - a.dir : (a.dir == 1 ? (b.pos - a.pos) : (a.pos - b.pos)));
                for (int j = 0; j < x.size(); j++) {
                    if (x.get(j).dir == 1) {
                        res[p1[j]][0] = x.get(j).pos;
                        res[p1[j]][1] = h;
                    } else {
                        res[p1[j]][0] = w;
                        res[p1[j]][1] = x.get(j).pos;
                    }
                }

            }

            for (int i = 0; i < n; i++) {
                out.println(res[i][0] + " " + res[i][1]);
            }
        }

        static class Dancer {
            public int idx;
            public int pos;
            public int dir;
            public int time;

            public Dancer(int idx, int dir, int pos, int time) {
                this.idx = idx;
                this.dir = dir;
                this.pos = pos;
                this.time = time;
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
}