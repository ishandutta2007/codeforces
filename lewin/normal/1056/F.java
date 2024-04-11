import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        FWriteTheContest solver = new FWriteTheContest();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class FWriteTheContest {
        long INF = 1L << 60;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            double C = in.nextDouble(), T = in.nextDouble();
            FWriteTheContest.Task[] ts = new FWriteTheContest.Task[n];
            int tp = 0;
            for (int i = 0; i < n; i++) {
                ts[i] = new FWriteTheContest.Task(in.nextInt(), in.nextInt());
                tp += ts[i].points;
            }
            Arrays.sort(ts, Comparator.comparingInt(x -> x.difficulty));
            double[][] dp = new double[n + 1][tp + 1];
            AUtils.deepFill(dp, INF);
            dp[0][0] = 0;

            for (FWriteTheContest.Task t : ts) {
                for (int ntasks = n - 1; ntasks >= 0; ntasks--) {
                    for (int j = tp; j >= t.points; j--) {
                        dp[ntasks + 1][j] = Math.min(dp[ntasks + 1][j], dp[ntasks][j - t.points] * 10.0 / 9.0 + t.difficulty);
                    }
                }
            }
            for (int i = tp; i >= 0; i--) {
                for (int ntasks = 0; ntasks <= n; ntasks++) {
                    if (dp[ntasks][i] >= INF) {
                        continue;
                    }
                    double nT = T - 10 * ntasks;
                    if (nT < 0) continue;
                    dp[ntasks][i] *= 10.0 / 9.0;
                    double root = C * C * nT * nT - 4 * C * dp[ntasks][i] + 2 * C * nT + 1;
                    if (root < -1e-10) {
                        continue;
                    }
                    root = Math.max(root, 0);
                    root = Math.sqrt(root);
                    double ans = (root + C * nT + 1) / 2.0 / C;
                    if (ans >= 0 && ans <= nT) {
                        out.println(i);
                        return;
                    }
                    ans = (C * nT + 1 - root) / 2.0 / C;
                    if (ans >= 0 && ans <= nT) {
                        out.println(i);
                        return;
                    }
                }
            }
            out.println(0);
        }

        static class Task {
            public int difficulty;
            public int points;

            public Task(int difficulty, int points) {
                this.difficulty = difficulty;
                this.points = points;
            }

        }

    }

    static class AUtils {
        public static void deepFill(double[][] x, double val) {
            for (double[] y : x) deepFill(y, val);
        }

        public static void deepFill(double[] x, double val) {
            Arrays.fill(x, val);
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

        public double nextDouble() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            double res = 0.0D;

            while (true) {
                if (!isSpaceChar(c) && c != 46) {
                    if (c != 101 && c != 69) {
                        if (c >= 48 && c <= 57) {
                            res *= 10.0D;
                            res += (double) (c - 48);
                            c = this.read();
                            continue;
                        }

                        throw new InputMismatchException();
                    }

                    return res * Math.pow(10.0D, (double) this.nextInt());
                }

                if (c == 46) {
                    c = this.read();

                    for (double m = 1.0D; !isSpaceChar(c); c = this.read()) {
                        if (c == 101 || c == 69) {
                            return res * Math.pow(10.0D, (double) this.nextInt());
                        }

                        if (c < 48 || c > 57) {
                            throw new InputMismatchException();
                        }

                        m /= 10.0D;
                        res += (double) (c - 48) * m;
                    }
                }

                return res * (double) sgn;
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}