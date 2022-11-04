import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private long sqr(long x) {
            return x * x;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long x1, y1, x2, y2;
            int n;
            n = in.nextInt();
            x1 = in.nextLong();
            y1 = in.nextLong();
            x2 = in.nextLong();
            y2 = in.nextLong();

            long[] x, y;
            x = new long[n];
            y = new long[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextLong();
                y[i] = in.nextLong();
            }

            long answer = Long.MAX_VALUE;
            long current = 0;
            for (int i = 0; i < n; ++i) {
                current = Math.max(current, sqr(x[i] - x1) + sqr(y[i] - y1));
            }
            answer = Math.min(answer, current);
            current = 0;
            for (int i = 0; i < n; ++i) {
                current = Math.max(current, sqr(x[i] - x2) + sqr(y[i] - y2));
            }
            answer = Math.min(answer, current);


            for (int i = 0; i < n; ++i) {
                long threshold = sqr(x[i] - x1) + sqr(y[i] - y1);
                current = 0;
                for (int j = 0; j < n; ++j) {
                    long d1 = sqr(x[j] - x1) + sqr(y[j] - y1);
                    long d2 = sqr(x[j] - x2) + sqr(y[j] - y2);
                    if (d1 > threshold) {
                        current = Math.max(current, d2);
                    }
                }

                answer = Math.min(answer, current + threshold);
            }

            out.println(answer);
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}