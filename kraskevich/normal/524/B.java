import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Task {

    final int INF = (int) (1e9 + 10);

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] w = new int[n];
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = in.nextInt();
            h[i] = in.nextInt();
        }
        int res = INF;
        for (int maxH = 0; maxH < n; maxH++) {
            int totW = w[maxH];
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                if (i == maxH)
                    continue;
                int cur = INF;
                if (h[i] <= h[maxH])
                    cur = Math.min(cur, w[i]);
                if (w[i] <= h[maxH])
                    cur = Math.min(cur, h[i]);
                if (cur == INF) {
                    ok = false;
                    break;
                }
                totW += cur;
            }
            if (ok) {
                res = Math.min(res, totW * h[maxH]);
            }
        }
        for (int i = 0; i < n; i++) {
            int t = w[i];
            w[i] = h[i];
            h[i] = t;
        }
        for (int maxH = 0; maxH < n; maxH++) {
            int totW = w[maxH];
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                if (i == maxH)
                    continue;
                int cur = INF;
                if (h[i] <= h[maxH])
                    cur = Math.min(cur, w[i]);
                if (w[i] <= h[maxH])
                    cur = Math.min(cur, h[i]);
                if (cur == INF) {
                    ok = false;
                    break;
                }
                totW += cur;
            }
            if (ok) {
                res = Math.min(res, totW * h[maxH]);
            }
        }
        out.println(res);
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int testsCount = 1;
        for (int i = 1; i <= testsCount; i++)
            new Task().solve(i, in, out);
        in.close();
        out.close();
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                return null;
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            return null;
        }
        return line;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {

        }
    }
}