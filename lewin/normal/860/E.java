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
        public List<Integer>[] graph;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            graph = LUtils.genArrayList(n);
            int ceo = -1;
            int[] par = new int[n];
            int[] child = new int[n];

            for (int i = 0; i < n; i++) {
                par[i] = in.nextInt() - 1;
                if (par[i] == -1) ceo = i;
                else {
                    child[par[i]]++;
                    graph[par[i]].add(i);
                }
            }

            List<Integer> toProcess = new ArrayList<>();
            toProcess.addAll(graph[ceo]);
            long[] under = new long[n];
            Arrays.fill(under, 1);
            under[ceo] = graph[ceo].size();
            int[] depth = new int[n];
            depth[ceo] = 0;
            for (int j : graph[ceo]) depth[j] = 1;
            long[] ans = new long[n];
            while (toProcess.size() > 0) {
                for (int k : toProcess) {
                    int cur = par[k];
                    do {
                        while (par[cur] != -1 && child[par[cur]] == 1)
                            par[cur] = par[par[cur]];
                        if (par[cur] == -1) {
                            ans[k] += (long) (depth[cur] + 1) * under[cur];
                            break;
                        }
                        ans[k] += (long) (depth[cur] - depth[par[cur]]) * under[cur];
                        cur = par[cur];
                    } while (cur != -1);
                }

                List<Integer> next = new ArrayList<>();
                for (int k : toProcess) {
                    int cur = k;
                    do {
                        under[cur] += graph[k].size() - 1;
                        while (par[cur] != -1 && child[par[cur]] == 1)
                            par[cur] = par[par[cur]];
                        cur = par[cur];
                    } while (cur != -1);
                    if (graph[k].size() == 0) {
                        cur = k;
                        while (par[cur] != -1) {
                            while (par[cur] != -1 && child[par[cur]] == 1)
                                par[cur] = par[par[cur]];
                            if (par[cur] == -1) break;

                            child[par[cur]]--;
                            if (child[par[cur]] == 0) {
                                cur = par[cur];
                            } else {
                                break;
                            }
                        }
                    } else {
                        for (int j : graph[k]) {
                            depth[j] = depth[k] + 1;
                            ans[j] = ans[k];
                            next.add(j);
                        }
                    }
                }
                toProcess = next;
            }

            out.println(ans);
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

        public void print(long[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(long[] array) {
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