import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
import java.util.ArrayList;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public static final int INF = 1 << 29;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            ArrayList<TaskD.Point>[] pt = new ArrayList[2];
            for (int i = 0; i < 2; i++) pt[i] = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt(), y = in.nextInt();
                int t = (x + y) % 2;
                if (t < 0) t += 2;
                pt[t].add(new TaskD.Point(x + y, x - y));
            }
            long ans = 0;
            for (int md = 0; md < 2; md++) {
                pt[md].sort(Comparator.comparingInt(a -> a.x));
                int m = pt[md].size();
                int[] aymin = new int[m + 2];
                int[] aymax = new int[m + 2];
                int[] bymin = new int[m + 2];
                int[] bymax = new int[m + 2];
                aymin[0] = INF;
                aymax[0] = -INF;
                for (int i = 1; i <= m; i++) {
                    aymin[i] = Math.min(aymin[i - 1], pt[md].get(i - 1).y + 1);
                    aymax[i] = Math.max(aymax[i - 1], pt[md].get(i - 1).y - 1);
                }
                bymin[m + 1] = INF;
                bymax[m + 1] = -INF;
                for (int i = m; i >= 1; i--) {
                    bymin[i] = Math.min(bymin[i + 1], pt[md].get(i - 1).y + 1);
                    bymax[i] = Math.max(bymax[i + 1], pt[md].get(i - 1).y - 1);
                }

                int idx1 = 0, idx2 = 0;
                for (int cx = -200010 + 1 - md; cx <= 200010; cx += 2) {
                    while (idx1 < pt[md].size() && pt[md].get(idx1).x < cx) {
                        idx1++;
                    }
                    while (idx2 < pt[md].size() && pt[md].get(idx2).x <= cx) {
                        idx2++;
                    }

                    int ymin = Math.max(aymin[idx1], bymin[idx2 + 1]);
                    int ymax = Math.min(aymax[idx1], bymax[idx2 + 1]);
                    if ((cx + ymin) % 2 != 0) ymin++;
                    if ((cx + ymax) % 2 != 0) ymax--;
                    if (ymin <= ymax) {
                        ans += (ymax - ymin) / 2 + 1;
                    }
                }
            }
            out.println(ans);
        }

        static class Point {
            public int x;
            public int y;

            public Point(int x, int y) {
                this.x = x;
                this.y = y;
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}