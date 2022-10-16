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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            List<Integer>[] x = LUtils.genArrayList(4);
            for (int i = 0; i < n; i++) {
                int w = in.nextInt(), c = in.nextInt();
                x[w].add(c);
            }
            for (int i = 1; i <= 3; i++) {
                Collections.sort(x[i], Collections.reverseOrder());
            }
            long[] res = new long[m + 1];
            res[0] = 0;
            int pt1 = 0, pt2 = 0;
            for (int w = 2; w <= m; w += 2) {
                long x1 = (pt1 < x[1].size() ? x[1].get(pt1) : 0) + (pt1 + 1 < x[1].size() ? x[1].get(pt1 + 1) : 0);
                long x2 = (pt2 < x[2].size() ? x[2].get(pt2) : 0);
                res[w] = res[w - 2] + Math.max(x1, x2);
                if (x1 > x2) pt1 += 2;
                else pt2++;
            }
            pt1 = 1;
            pt2 = 0;
            if (x[1].size() > 0) {
                res[1] = x[1].get(0);
            }
            for (int w = 3; w <= m; w += 2) {
                long x1 = (pt1 < x[1].size() ? x[1].get(pt1) : 0) + (pt1 + 1 < x[1].size() ? x[1].get(pt1 + 1) : 0);
                long x2 = (pt2 < x[2].size() ? x[2].get(pt2) : 0);
                res[w] = res[w - 2] + Math.max(x1, x2);
                if (x1 > x2) pt1 += 2;
                else pt2++;
            }

            int pt3 = 0;
            long mx = res[m];
            long x3s = 0;
            for (int take = 3; take <= m; take += 3) {
                long x3 = (pt3 < x[3].size() ? x[3].get(pt3) : 0);
                x3s += x3;
                if (x3s + res[m - take] >= mx) {
                    mx = x3s + res[m - take];
                }
                pt3++;
            }
            out.println(mx);
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}