import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Task {

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        boolean[] was = new boolean[(int) 1e7 + 10];
        for (int i = 0; i < n; i++)
            was[a[i]] = true;
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int s = in.nextInt();
            int res = k + 1;
            for (int i = 0; i < n; i++)
                for (int k1 = 1; k1 <= k; k1++) {
                    if (a[i] * k1 == s)
                        res = Math.min(res, k1);
                    for (int k2 = 1; k2 + k1 <= k; k2++) {
                        int rem = s - a[i] * k1;
                        if (rem <= 0)
                            continue;
                        if (rem % k2 != 0 || rem / k2 >= was.length)
                            continue;
                        if (was[rem / k2])
                            res = Math.min(res, k1 + k2);
                    }
                }
            if (res == k + 1)
                res = -1;
            out.println(res);
        }
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