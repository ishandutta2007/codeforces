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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC1 solver = new TaskC1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC1 {
        public int[] par;

        public int find(int node) {
            return par[node] == node ? node : (par[node] = find(par[node]));
        }

        public boolean join(int a, int b) {
            int x = find(a), y = find(b);
            if (x == y) return false;
            par[y] = x;
            return true;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            if (m != n - 1) {
                out.println("no");
                return;
            }
            par = new int[n];
            for (int i = 0; i < n; i++) par[i] = i;
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                if (!join(a, b)) {
                    out.println("no");
                    return;
                }
            }
            out.println("yes");
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}