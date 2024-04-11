import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public int MAXD = 1000010;
        public List<TaskB.Flight>[] fs;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            fs = LUtils.genArrayList(MAXD);
            for (int i = 0; i < m; i++) {
                int d = in.nextInt(), f = in.nextInt(), t = in.nextInt(), c = in.nextInt();
                if (f == 0)
                    fs[d].add(new TaskB.Flight(t, c, false));
                else
                    fs[d].add(new TaskB.Flight(f, c, true));
            }

            long[] fx = new long[MAXD + 1];
            boolean[] vf = new boolean[MAXD + 1];
            {
                long[] pc = new long[n + 1];
                Arrays.fill(pc, 1 << 29);
                int count = 0;
                pc[0] = 0;
                fx[0] = AUtils.sum(pc);
                vf[0] = false;
                for (int i = 0; i < MAXD; i++) {
                    fx[i + 1] = fx[i];
                    for (TaskB.Flight ff : fs[i]) {
                        if (!ff.dir) continue;

                        if (ff.cost < pc[ff.person]) {
                            if (pc[ff.person] == 1 << 29) count++;
                            fx[i + 1] -= pc[ff.person];
                            pc[ff.person] = ff.cost;
                            fx[i + 1] += pc[ff.person];
                        }
                    }
                    vf[i + 1] = count == n;
                }
            }

            long[] bx = new long[MAXD + 1];
            boolean[] vb = new boolean[MAXD + 1];
            {
                long[] pc = new long[n + 1];
                Arrays.fill(pc, 1 << 29);
                int count = 0;
                pc[0] = 0;
                bx[MAXD] = AUtils.sum(pc);
                vb[MAXD] = false;
                for (int i = MAXD - 1; i >= 0; i--) {
                    bx[i] = bx[i + 1];
                    for (TaskB.Flight ff : fs[i]) {
                        if (ff.dir) continue;

                        if (ff.cost < pc[ff.person]) {
                            if (pc[ff.person] == 1 << 29) count++;
                            bx[i] -= pc[ff.person];
                            pc[ff.person] = ff.cost;
                            bx[i] += pc[ff.person];
                        }
                    }
                    vb[i] = count == n;
                }
            }
            long ret = 1L << 60;
            for (int i = 0; i + k < MAXD; i++) {
                if (vf[i] && vb[i + k])
                    ret = Math.min(ret, fx[i] + bx[i + k]);
            }
            out.println(ret >= 1L << 60 ? -1 : ret);
        }

        static class Flight {
            public int person;
            public int cost;
            public boolean dir;

            public Flight(int person, int cost, boolean dir) {
                this.person = person;
                this.cost = cost;
                this.dir = dir;
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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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

    static class AUtils {
        public static long sum(long[] arr) {
            long sum = 0;
            for (long x : arr) {
                sum += x;
            }
            return sum;
        }

    }
}