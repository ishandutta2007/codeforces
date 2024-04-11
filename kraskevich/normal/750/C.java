import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Igor Kraskevich
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        long[] delta;
        long[] div;
        final long INF = (long) 1e9;

        boolean tooBig(long rating) {
            for (int i = 0; i < delta.length; i++) {
                if (div[i] == 2 && rating >= 1900)
                    return true;
                rating += delta[i];
            }
            return false;
        }

        boolean tooSmall(long rating) {
            for (int i = 0; i < delta.length; i++) {
                if (div[i] == 1 && rating < 1900)
                    return true;
                rating += delta[i];
            }
            return false;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            delta = new long[n];
            div = new long[n];
            boolean allDiv1 = true;
            long totalAdd = 0;
            for (int i = 0; i < n; i++) {
                delta[i] = in.nextLong();
                totalAdd += delta[i];
                div[i] = in.nextInt();
                if (div[i] == 2)
                    allDiv1 = false;
            }
            if (allDiv1) {
                out.println("Infinity");
                return;
            }
            long low = -INF;
            long high = INF;
            while (high - low > 1) {
                long mid = (low + high) / 2;
                if (tooBig(mid))
                    high = mid;
                else
                    low = mid;
            }
            long maxRating = high - 1;
            low = -INF;
            high = INF;
            while (high - low > 1) {
                long mid = (low + high) / 2;
                if (tooSmall(mid))
                    low = mid;
                else
                    high = mid;
            }
            long minRating = low + 1;
            if (minRating <= maxRating)
                out.println(maxRating + totalAdd);
            else
                out.println("Impossible");
        }

    }

    static class FastScanner {
        private StringTokenizer tokenizer;
        private BufferedReader reader;

        public FastScanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                String line = null;
                try {
                    line = reader.readLine();
                } catch (IOException e) {
                    // ignore
                }
                if (line == null)
                    return null;
                tokenizer = new StringTokenizer(line);
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