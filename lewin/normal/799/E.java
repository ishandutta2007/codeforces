import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.stream.Stream;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        public int n;
        public int m;
        public int k;
        public int[] c;
        public int[] e;
        public PriorityQueue<Integer>[] items;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            if (k > m) {
                out.println(-1);
                return;
            }
            c = in.readIntArray(n);
            e = new int[n];
            int a = in.nextInt();
            for (int i = 0; i < a; i++) {
                int x = in.nextInt() - 1;
                e[x] |= 1;
            }
            int b = in.nextInt();
            for (int i = 0; i < b; i++) {
                int x = in.nextInt() - 1;
                e[x] |= 2;
            }
            items = Stream.generate(PriorityQueue::new).limit(4).toArray(PriorityQueue[]::new);
            PriorityQueue<Integer> used0 = new PriorityQueue<>();
            long ccost = 0;
            for (int i = 0; i < n; i++) {
                if (e[i] == 1 || e[i] == 2) {
                    items[e[i]].add(-c[i]);
                    ccost += c[i];
                    if (items[e[i]].size() > k) {
                        int w = -items[e[i]].poll();
                        ccost -= w;
                        items[0].add(w);
                    }
                } else {
                    items[e[i]].add(c[i]);
                }
            }

            int ccount = items[1].size() + items[2].size();
            long best = 1L << 60;
            if (ccount == 2 * k) {
                while (ccount < m && items[0].size() > 0) {
                    ccount++;
                    int w = items[0].poll();
                    ccost += w;
                    used0.add(-w);
                }
                if (ccount == m) best = ccost;
            }
            for (int fixed = 1; fixed <= m && items[3].size() > 0; fixed++) {
                ccost += items[3].poll();
                ccount++;
                int need = Math.max(0, k - fixed);
                for (int w = 1; w <= 2; w++) {
                    if (items[w].size() > need) {
                        int x = -items[w].poll();
                        ccost -= x;
                        items[0].add(x);
                        ccount--;
                    }
                }
                if (items[1].size() == need && items[2].size() == need) {
                    while (ccount < m && items[0].size() > 0) {
                        ccount++;
                        int w = items[0].poll();
                        ccost += w;
                        used0.add(-w);
                    }
                    while (ccount > m && used0.size() > 0) {
                        ccount--;
                        int w = -used0.poll();
                        ccost -= w;
                        items[0].add(w);
                    }

                    while (items[0].size() > 0 && used0.size() > 0 && -used0.peek() > items[0].peek()) {
                        int x1 = -used0.poll(), x2 = items[0].poll();
                        ccost -= x1;
                        ccost += x2;
                        used0.add(-x2);
                        items[0].add(x1);
                    }

                    if (ccount == m) best = Math.min(best, ccost);
                }
            }

            out.println(best >= 1L << 60 ? -1 : best);
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
}