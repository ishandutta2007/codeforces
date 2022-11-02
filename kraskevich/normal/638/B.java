import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    final int N = 26;

    boolean[][] g = new boolean[N][N];
    ArrayList<Integer> vs = new ArrayList<>();
    boolean[] was = new boolean[N];
    boolean[] exists = new boolean[N];

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            char[] c = in.next().toCharArray();
            for (int j = 0; j < c.length; j++) {
                exists[c[j] - 'a'] = true;
                if (j > 0)
                    g[c[j - 1] - 'a'][c[j] - 'a'] = true;
            }
        }
        for (;;) {
            boolean any = false;
            for (int i = 0; i < N && !any; i++)
                if (!was[i] && exists[i]) {
                    int cnt = 0;
                    for (int j = 0; j < N; j++)
                        if (was[j] && g[j][i])
                            cnt++;
                    if (cnt > 0) {
                        was[i] = true;
                        any = true;
                        out.print((char) (i + 'a'));
                    }
                }
            for (int i = 0; i < N && !any; i++)
                if (!was[i] && exists[i]) {
                    int cnt = 0;
                    for (int j = 0; j < N; j++)
                        if (g[j][i])
                            cnt++;
                    if (cnt == 0) {
                        was[i] = true;
                        any = true;
                        out.print((char) (i + 'a'));
                    }
                }
            if (!any)
                break;
        }
    }

    public static void main(String[] args)throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Main().solve(0, in, out);
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
                throw new RuntimeException(e);
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

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        tokenizer = null;
        return line;
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}