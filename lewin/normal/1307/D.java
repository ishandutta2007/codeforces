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
        DCowAndFields solver = new DCowAndFields();
        solver.solve(1, in, out);
        out.close();
    }

    static class DCowAndFields {
        List<Integer>[] graph;
        int n;
        int m;
        int k;

        int[] getDist(int source) {
            int[] dist = new int[n];
            Arrays.fill(dist, 1 << 30);
            dist[source] = 0;
            int front = 0, back = 0;
            int[] q = new int[n];
            q[back++] = source;
            while (front < back) {
                int cur = q[front++];
                for (int nxt : graph[cur]) {
                    if (dist[cur] + 1 < dist[nxt]) {
                        dist[nxt] = dist[cur] + 1;
                        q[back++] = nxt;
                    }
                }
            }
            return dist;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            int[] arr = in.readIntArrayAndDecrementOne(k);
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }
            int[] dist0 = getDist(0);
            int[] dist1 = getDist(n - 1);
            int ans = dist0[n - 1];
            DCowAndFields.State[] ds = new DCowAndFields.State[k];
            for (int i = 0; i < k; i++) {
                ds[i] = new DCowAndFields.State(dist0[arr[i]], dist1[arr[i]], i);
            }
            Arrays.sort(ds, Comparator.comparingInt(x -> x.a));
            int mx = 0;
            for (int i = 0; i + 1 < k; i++) {
                mx = Math.max(mx, Math.min(ds[i].a + ds[i + 1].b, ds[i].b + ds[i + 1].a) + 1);
            }
            out.println(Math.min(ans, mx));
        }

        static class State {
            public int a;
            public int b;
            public int c;

            public State(int a, int b, int c) {
                this.a = a;
                this.b = b;
                this.c = c;
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

        public int[] readIntArrayAndDecrementOne(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt() - 1;
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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}