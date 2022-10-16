import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public List<TaskF.Edge>[] graph;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            if (n == 1) {
                out.println(0);
                return;
            }
            TaskF.Edge[] e = new TaskF.Edge[m];
            graph = LUtils.genArrayList(2 * n);
            int ee = 0;
            for (int i = 0; i < m; i++) {
                e[i] = new TaskF.Edge(in.nextInt() - 1, in.nextInt() - 1, in.nextInt(), in.nextInt());
                graph[2 * e[i].from + 0].add(new TaskF.Edge(e[i], 0, ee++, false));
                graph[2 * e[i].to + 1].add(new TaskF.Edge(e[i], 1, ee++, true));
                graph[2 * e[i].from + 1].add(new TaskF.Edge(e[i], 1, ee++, false));
                graph[2 * e[i].to + 0].add(new TaskF.Edge(e[i], 0, ee++, true));
            }
            TaskF.Edge[] ae = new TaskF.Edge[ee];
            for (int i = 0; i < 2 * n; i++) {
                for (TaskF.Edge xx : graph[i]) {
                    ae[xx.id] = xx;
                }
            }
            for (int i = 0; i < 2 * n; i++) {
                Collections.sort(graph[i], Comparator.comparingInt(x -> x.s));
            }

            int[] min = new int[ee];
            Arrays.fill(min, 1 << 30);
            int[] idd = new int[2 * n];
            PriorityQueue<TaskF.State> pq = new PriorityQueue<>(Comparator.comparingInt(x -> x.ctime));
            for (int i = 0; i < graph[0].size(); i++) {
                TaskF.Edge eee = graph[0].get(i);
                if (eee.s != 0) break;
                idd[0]++;
                pq.add(new TaskF.State(eee.id, min[eee.id] = 0));
            }

            long res = 1L << 60;
            while (pq.size() > 0) {
                TaskF.State w = pq.poll();
                if (min[w.id] != w.ctime) continue;
                TaskF.Edge cur = ae[w.id];
                if (cur.from == n - 1) {
                    res = Math.min(res, w.ctime);
                }
                // expand from
                int maxtime = cur.e;
                if ((maxtime - w.ctime) % 2 == 1) maxtime--;
                int node = cur.from * 2 + cur.t;
                for (int i = idd[node]; i < graph[node].size(); i++) {
                    TaskF.Edge eee = graph[node].get(i);
                    if (eee.s > maxtime) {
                        break;
                    }
                    idd[node]++;
                    int ct = Math.max(w.ctime, eee.s);
                    if ((ct - w.ctime) % 2 == 1) ct++;
                    if (ct <= eee.e)
                        pq.add(new TaskF.State(eee.id, min[eee.id] = ct));
                }
                // expand to
                if (min[w.id ^ 1] > min[w.id] + 1) {
                    if (min[w.id] + 1 <= ae[w.id ^ 1].e)
                        pq.add(new TaskF.State(w.id ^ 1, min[w.id ^ 1] = min[w.id] + 1));
                }
            }
            out.println(res >= 1L << 60 ? -1 : res);
        }

        static class Edge {
            public int from;
            public int to;
            public int s;
            public int e;
            public int t;
            public int id;

            public Edge(int from, int to, int s, int e) {
                this.from = from;
                this.to = to;
                this.s = s;
                this.e = e;
            }

            public Edge(TaskF.Edge e, int t, int id, boolean swap) {
                if (!swap) {
                    this.from = e.from;
                    this.to = e.to;
                } else {
                    this.from = e.to;
                    this.to = e.from;
                }
                this.s = e.s;
                this.e = e.e;
                this.t = t;
                this.id = id;
            }

        }

        static class State {
            public int id;
            public int ctime;

            public State(int id, int ctime) {
                this.id = id;
                this.ctime = ctime;
            }

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