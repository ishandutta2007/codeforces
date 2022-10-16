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
        public List<TaskB.Edge>[] graph;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            graph = LUtils.genArrayList(n);
            int[] indeg = new int[n];
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, lab = in.next().charAt(0) - 'a' + 1;
                graph[a].add(new TaskB.Edge(b, lab));
                indeg[b]++;
            }

            int[] queue = new int[n];
            int front = 0, back = 0;
            for (int i = 0; i < n; i++) {
                if (indeg[i] == 0) {
                    queue[back++] = i;
                }
            }
            while (front < back) {
                int cur = queue[front++];
                for (TaskB.Edge e : graph[cur]) {
                    if (--indeg[e.to] == 0) {
                        queue[back++] = e.to;
                    }
                }
            }

            boolean[][][][] win = new boolean[2][n][n][27];
            for (int ci = n - 1; ci >= 0; ci--) {
                for (int cj = n - 1; cj >= 0; cj--) {
                    int i = queue[ci], j = queue[cj];
                    for (int let = 0; let <= 26; let++) {
                        for (int turn = 0; turn < 2; turn++) {
                            if (turn == 0) {
                                for (TaskB.Edge e : graph[i]) {
                                    if (e.lab >= let)
                                        win[turn][i][j][let] |= !win[1 - turn][e.to][j][e.lab];
                                }
                            } else {
                                for (TaskB.Edge e : graph[j]) {
                                    if (e.lab >= let)
                                        win[turn][i][j][let] |= !win[1 - turn][i][e.to][e.lab];
                                }
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out.print(win[0][i][j][0] ? 'A' : 'B');
                }
                out.println();
            }

        }

        static class Edge {
            public int to;
            public int lab;

            public Edge(int to, int lab) {
                this.to = to;
                this.lab = lab;
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

        public void println() {
            writer.println();
        }

        public void print(char i) {
            writer.print(i);
        }

        public void close() {
            writer.close();
        }

    }
}