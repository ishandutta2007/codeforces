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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        private final int[] dirX = new int[]{-1, -2, -1, 1, 2, 1};
        private final int[] dirY = new int[]{2, 0, -2, -2, 0, 2};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            if (n == 0) {
                out.println("0 0");
                return;
            }

            long low = 1, high = 1000000000;
            while (low < high) {
                long mid = (low + high) >> 1L;
                if ((1 + mid) * mid / 2 * 6 + 1 > n) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }

            long pre = low - 1;
            n -= (pre + 1) * pre / 2 * 6 + 1;

            long x = 1 + 2 * pre;
            long y = 2;

            for (int i = 0; i < 6; ++i) {
                long delta = Math.min(i > 0 ? low : low - 1, n);
                x += dirX[i] * delta;
                y += dirY[i] * delta;

                n -= delta;
            }

            out.println(x + " " + y);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}