import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
 *
 * @author lewin
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
        public List<TaskC.Edge>[] graph;
        public int[] res;
        int n;

        public boolean ok1(long x, long y) {
            return x * x + y * y <= 1000000L * 1000000L;
        }

        public boolean ok2(long x, long y) {
            return x * x + y * y <= 1500000L * 1500000L;
        }

        public void dfs(int node) {
            for (TaskC.Edge next : graph[node]) {
                res[next.to] = (next.same == 1 ? 1 : -1) * res[node];
                dfs(next.to);
            }
        }

        public boolean ok(int mask, ArrayList<TaskC.Vector> vs, OutputWriter out) {
            long x = 0, y = 0;
            for (int i = 0; i < vs.size(); i++) {
                if (((mask >> i) & 1) == 1) {
                    x += vs.get(i).x;
                    y += vs.get(i).y;
                } else {
                    x -= vs.get(i).x;
                    y -= vs.get(i).y;
                }
            }
            if (ok2(x, y)) {
                res = new int[n];
                for (int i = 0; i < vs.size(); i++) {
                    if (((mask >> i) & 1) == 1) {
                        res[vs.get(i).id] = +1;
                    } else {
                        res[vs.get(i).id] = -1;
                    }
                    dfs(vs.get(i).id);
                }
                out.println(res);
                return true;
            }
            return false;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            ArrayList<TaskC.Vector> vs = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                vs.add(new TaskC.Vector(in.nextInt(), in.nextInt(), i));
            }
            graph = LUtils.genArrayList(n);
            while (vs.size() > 10) {
                vs.sort(Comparator.comparingDouble(x -> Math.atan2(x.y, x.x)));
                ArrayList<TaskC.Vector> nvs = new ArrayList<>();
                for (int i = 0; i < vs.size(); i++) {
                    if (i + 1 < vs.size()) {
                        TaskC.Vector a1 = vs.get(i);
                        TaskC.Vector a2 = vs.get(i + 1);
                        if (ok1(a1.x + a2.x, a1.y + a2.y)) {
                            nvs.add(new TaskC.Vector(a1.x + a2.x, a1.y + a2.y, a1.id));
                            graph[a1.id].add(new TaskC.Edge(a2.id, 1));
                            i++;
                        } else if (ok1(a1.x - a2.x, a1.y - a2.y)) {
                            if (a1.x - a2.x >= 0) {
                                nvs.add(new TaskC.Vector(a1.x - a2.x, a1.y - a2.y, a1.id));
                                graph[a1.id].add(new TaskC.Edge(a2.id, 0));
                            } else {
                                nvs.add(new TaskC.Vector(a2.x - a1.x, a2.y - a1.y, a2.id));
                                graph[a2.id].add(new TaskC.Edge(a1.id, 0));
                            }
                            i++;
                        } else {
                            nvs.add(vs.get(i));
                        }
                    } else {
                        nvs.add(vs.get(i));
                    }
                }
                vs = nvs;
            }

            for (int mask = 0; mask < 1 << vs.size(); mask++) {
                if (ok(mask, vs, out)) {
                    return;
                }
            }
        }

        static class Vector {
            public int x;
            public int y;
            public int id;

            public Vector(int x, int y, int id) {
                this.x = x;
                this.y = y;
                this.id = id;
            }

        }

        static class Edge {
            public int to;
            public int same;

            public Edge(int to, int same) {
                this.to = to;
                this.same = same;
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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}