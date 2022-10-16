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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        List<Integer>[] graph;
        List<Integer>[] g2;
        int[] indeg;

        boolean dfs(int node, int par) {
            boolean has = false;
            for (int next : graph[node]) {
                if (next == par) continue;
                boolean t = dfs(next, node);
                if (t) {
                    has ^= true;
                }
            }
            if (par != -1) {
                if (has) {
                    g2[node].add(par);
                    indeg[par]++;
                } else {
                    g2[par].add(node);
                    indeg[node]++;
                }
            }
            return !has;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            if (n % 2 == 0) {
                out.println("NO");
                return;
            }

            graph = LUtils.genArrayList(n);
            for (int i = 0; i < n; i++) {
                int a = in.nextInt() - 1;
                if (a == -1) continue;
                graph[i].add(a);
                graph[a].add(i);
            }

            g2 = LUtils.genArrayList(n);
            indeg = new int[n];
            if (!dfs(0, -1)) {
                System.exit(1);
            }

            out.println("YES");
            int[] q = new int[n];
            int front = 0, back = 0;
            for (int i = 0; i < n; i++) {
                if (indeg[i] == 0) {
                    q[back++] = i;
                }
            }
            while (front < back) {
                int cur = q[front++];
                for (int t : g2[cur]) {
                    if (--indeg[t] == 0) {
                        q[back++] = t;
                    }
                }
            }
            for (int k : q) {
                out.println(k + 1);
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
}