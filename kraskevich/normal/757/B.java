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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int MAX_N = 1000 * 1000;
            int[] cnt = new int[MAX_N];
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int cur = x;
                for (int d = 2; d * d <= x; d++)
                    if (cur % d == 0) {
                        cnt[d]++;
                        while (cur % d == 0)
                            cur /= d;
                    }
                if (cur > 1)
                    cnt[cur]++;
            }
            int res = 1;
            for (int i = 0; i < cnt.length; i++)
                res = Math.max(res, cnt[i]);
            out.println(res);
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

    }
}