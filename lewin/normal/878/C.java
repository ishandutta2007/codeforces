import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
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
        static int MAX = 0;
        static int IDX = 0;
        public int n;
        public int k;
        TreeSet<TaskC.Component> cc;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            TaskC.Person[] p = new TaskC.Person[n];
            for (int i = 0; i < n; i++) {
                p[i] = new TaskC.Person(in.readIntArray(k), i);
            }
//        for (int j = 0; j < k; j++) {
//            final int jj = j;
//            Arrays.sort(p, Comparator.comparingInt(x -> x.skills[jj]));
//            for (int i = 0; i < n; i++) {
//                p[i].skills[j] = i;
//            }
//        }
//        Arrays.sort(p, Comparator.comparingInt(x -> x.idx));

            cc = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                merge(new TaskC.Component(Arrays.copyOf(p[i].skills, k), Arrays.copyOf(p[i].skills, k), 1));
                out.println(cc.last().size);
            }
        }

        public void merge(TaskC.Component c) {
            for (int j = 0; j < k; j++) {
                small:
                {
                    MAX = 0;
                    IDX = j;
                    int g = c.min[j];
                    c.min[j] = c.max[j];
                    TaskC.Component t = cc.lower(c);
                    c.min[j] = g;
                    if (t == null) break small;

                    for (int r = 0; r < k; r++) {
                        if (t.max[r] > c.min[r]) {
                            cc.remove(t);
                            t.merge(c);
                            merge(t);
                            return;
                        }
                    }
                }

                big:
                {
                    MAX = 1;
                    IDX = j;
                    int g = c.max[j];
                    c.max[j] = c.min[j];
                    TaskC.Component t = cc.higher(c);
                    c.max[j] = g;
                    if (t == null) break big;

                    for (int r = 0; r < k; r++) {
                        if (t.min[r] < c.max[r]) {
                            cc.remove(t);
                            t.merge(c);
                            merge(t);
                            return;
                        }
                    }
                }
            }
            cc.add(c);

        }

        static class Person {
            public int[] skills;
            public int idx;

            public Person(int[] skills, int idx) {
                this.skills = skills;
                this.idx = idx;
            }

        }

        static class Component implements Comparable<TaskC.Component> {
            public int[] min;
            public int[] max;
            public int size;

            public Component(int[] min, int[] max, int size) {
                this.min = min;
                this.max = max;
                this.size = size;
            }

            public void merge(TaskC.Component other) {
                this.size += other.size;
                for (int i = 0; i < min.length; i++) {
                    min[i] = Math.min(min[i], other.min[i]);
                    max[i] = Math.max(max[i], other.max[i]);
                }
            }


            public String toString() {
                return "Component{" +
                        "min=" + Arrays.toString(min) +
                        ", max=" + Arrays.toString(max) +
                        ", size=" + size +
                        '}';
            }

            public int compareTo(TaskC.Component other) {
                if (MAX == 0) {
                    return min[IDX] - other.min[IDX];
                } else {
                    return max[IDX] - other.max[IDX];
                }
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
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
}