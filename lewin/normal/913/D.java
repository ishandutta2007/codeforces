import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), T = in.nextInt();
            int[] a = new int[n], t = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                t[i] = in.nextInt();
            }
            List<TaskD.Problem>[] tt = LUtils.genArrayList(n + 1);
            for (int i = 0; i < n; i++) {
                tt[a[i]].add(new TaskD.Problem(t[i], i + 1));
            }
            PriorityQueue<TaskD.Problem> pq = new PriorityQueue<>(Comparator.comparingInt(x -> -x.time));
            int timeleft = T;
            for (TaskD.Problem g : tt[n]) {
                pq.add(g);
                timeleft -= g.time;
                while (pq.size() > n || timeleft < 0) {
                    timeleft += pq.poll().time;
                }
            }
            if (pq.size() == n) {
                out.println(n);
                out.println(n);
                boolean first = true;
                while (pq.size() > 0) {
                    if (!first) out.print(" ");
                    first = false;
                    out.print(pq.poll().idx);
                }
                out.println();
                return;
            }
            for (int k = n - 1; k >= 0; k--) {
                for (TaskD.Problem g : tt[k]) {
                    pq.add(g);
                    timeleft -= g.time;
                }
                while (pq.size() > k || timeleft < 0) {
                    timeleft += pq.poll().time;
                }

                if (pq.size() == k) {
                    out.println(k);
                    out.println(k);
                    boolean first = true;
                    while (pq.size() > 0) {
                        if (!first) out.print(" ");
                        first = false;
                        out.print(pq.poll().idx);
                    }
                    out.println();
                    return;
                }
            }
        }

        static class Problem {
            public int time;
            public int idx;

            public Problem(int time, int idx) {
                this.time = time;
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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}