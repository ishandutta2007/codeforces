import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.util.AbstractCollection;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            TaskE.Event[] es = new TaskE.Event[2 * n];
            for (int i = 0; i < n; i++) {
                es[i] = new TaskE.Event(in.nextInt(), +1, i + 1);
                es[i + n] = new TaskE.Event(in.nextInt() + 1, -1, i + 1);
            }
            Arrays.sort(es);

            HashSet<Integer> active = new HashSet<>();
            int back = 0;
            boolean[] need = new boolean[n + 1];
            while (back < 2 * n) {
                int f = back;
                while (back < 2 * n && es[back].time == es[f].time) {
                    if (es[back].type == +1) active.add(es[back].idx);
                    else active.remove(es[back].idx);
                    back++;
                }
                if (active.size() == 1) {
                    need[(int) active.toArray()[0]] = true;
                }
            }

            for (int i = 1; i <= n; i++) {
                if (!need[i]) {
                    out.println(i);
                    return;
                }
            }

            out.println(-1);
        }

        static class Event implements Comparable<TaskE.Event> {
            public int time;
            public int type;
            public int idx;

            public Event(int time, int type, int idx) {
                this.time = time;
                this.type = type;
                this.idx = idx;
            }

            public int compareTo(TaskE.Event other) {
                if (time != other.time) return time - other.time;
                return other.type - type;
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}