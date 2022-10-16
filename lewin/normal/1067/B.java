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
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BMultihedgehog solver = new BMultihedgehog();
        solver.solve(1, in, out);
        out.close();
    }

    static class BMultihedgehog {
        int n;
        int k;
        List<Integer>[] graph;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            k = Math.min(in.nextInt(), 20);
            graph = LUtils.genArrayList(n);
            int[] deg = new int[n];
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
                deg[a]++;
                deg[b]++;
            }
            boolean[] alive = new boolean[n];
            Arrays.fill(alive, true);

            while (k-- >= 0) {
                int[] killed = new int[n];
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (alive[i]) found++;
                    if (alive[i] && deg[i] == 1) {
                        for (int x : graph[i]) {
                            killed[x]++;
                        }
                        alive[i] = false;
                    }
                }
                if (k == -1) {
                    out.println(found == 1 ? "Yes" : "No");
                    return;
                }
                if (found <= 1) {
                    out.println("No");
                    return;
                }
                for (int i = 0; i < n; i++) {
                    if (alive[i] && killed[i] > 0 && killed[i] < 3) {
                        out.println("No");
                        return;
                    }
                    if (alive[i]) {
                        deg[i] -= killed[i];
                    }
                }
            }
            out.println("No");
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

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 20];
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