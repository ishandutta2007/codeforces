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
        public List<Integer>[] graph;
        public boolean[] must;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            if (n == 1) {
                out.println("Yes");
                out.println(0);
                return;
            }
            graph = LUtils.genArrayList(m);
            int[][] arr = new int[n][];
            must = new boolean[m];
            for (int i = 0; i < n; i++) {
                int t = in.nextInt();
                arr[i] = new int[t];
                for (int j = 0; j < t; j++) {
                    arr[i][j] = in.nextInt() - 1;
                }
            }

            outer:
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < Math.min(arr[i].length, arr[i + 1].length); j++) {
                    if (arr[i][j] == arr[i + 1][j]) {
                        continue;
                    } else {
                        if (arr[i][j] < arr[i + 1][j]) {
                            graph[arr[i + 1][j]].add(arr[i][j]);
                        } else {
                            must[arr[i][j]] = true;
                        }
                        continue outer;
                    }
                }

                if (arr[i].length > arr[i + 1].length) {
                    out.println("No");
                    return;
                }
            }
            for (int i = 0; i < m; i++) {
                if (must[i]) {
                    for (int j : graph[i]) {
                        if (!must[j]) {
                            must[j] = true;
                            dfs(j);
                        }
                    }
                }
            }
            outer:
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < Math.min(arr[i].length, arr[i + 1].length); j++) {
                    if (arr[i][j] == arr[i + 1][j]) {
                        continue;
                    } else {
                        if (arr[i][j] > arr[i + 1][j]) {
                            if (must[arr[i + 1][j]]) {
                                out.println("No");
                                return;
                            }
                        }
                        continue outer;
                    }
                }
            }


            out.println("Yes");
            int count = 0;
            for (boolean x : must) if (x) count++;
            out.println(count);
            for (int i = 0; i < m; i++) {
                if (must[i]) {
                    out.println(i + 1);
                }
            }
        }

        public void dfs(int node) {
            for (int j : graph[node]) {
                if (!must[j]) {
                    must[j] = true;
                    dfs(j);
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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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