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
        final int MAX_X = 20000;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int x = 0;
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                int len = in.nextInt();
                String dir = in.next();
                if (dir.equals("East") || dir.equals("West")) {
                    if (x == 0 || x == MAX_X) {
                        out.println("NO");
                        return;
                    }
                    continue;
                }
                if (dir.equals("North")) {
                    x -= len;
                    if (x < 0) {
                        out.println("NO");
                        return;
                    }
                } else if (dir.equals("South")) {
                    x += len;
                    if (x > MAX_X) {
                        out.println("NO");
                        return;
                    }
                }
            }
            out.println(x == 0 ? "YES" : "NO");
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