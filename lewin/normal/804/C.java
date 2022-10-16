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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public int n;
        public int m;
        public int[] colors;
        public List<Integer>[] types;
        public List<Integer>[] graph;
        public int[] used;
        public int cgen;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            colors = new int[m];
            types = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            graph = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            for (int i = 0; i < n; i++) {
                int k = in.nextInt();
                for (int j = 0; j < k; j++) {
                    types[i].add(in.nextInt() - 1);
                }
            }
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }

            used = new int[m + 1];
            cgen = 0;
            dfs(0, -1);

            for (int i = 0; i < m; i++) if (colors[i] == 0) colors[i] = 1;
            out.println(AUtils.max(colors));
            out.println(colors);
        }

        public void dfs(int node, int par) {
            cgen++;
            for (int x : types[node]) {
                used[colors[x]] = cgen;
            }
            int cp = 1;
            for (int x : types[node]) {
                if (colors[x] == 0) {
                    while (used[cp] == cgen) cp++;
                    colors[x] = cp;
                    used[cp] = cgen;
                }
            }
            for (int next : graph[node]) {
                if (next != par) {
                    dfs(next, node);
                }
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

        public void println(int i) {
            writer.println(i);
        }

    }

    static class AUtils {
        public static int max(int[] arr) {
            int res = arr[0];
            for (int x : arr) res = Math.max(res, x);
            return res;
        }

    }
}