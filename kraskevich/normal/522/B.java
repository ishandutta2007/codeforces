import java.io.*;
import java.util.StringTokenizer;

public class Task {

    class TwoMax {
        int first;
        int second;

        void add(int value) {
            if (value >= first) {
                second = first;
                first = value;
            } else if (value > second) {
                second = value;
            }
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] w = new int[n];
        int[] h = new int[n];
        TwoMax twoMax = new TwoMax();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            w[i] = in.nextInt();
            h[i] = in.nextInt();
            twoMax.add(h[i]);
            sum += w[i];
        }
        for (int i = 0; i < n; i++) {
            int curW = sum - w[i];
            int curH = twoMax.first == h[i] ? twoMax.second : twoMax.first;
            out.print(curH * curW + " ");
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        for (int i = 1; i <= t; i++)
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