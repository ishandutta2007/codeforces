import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Task {

    boolean isFriend(boolean[][] g, int x, int y, int k) {
        int tot = 0;
        for (int i = 0; i < g.length; i++)
            if (g[x][i])
                tot++;
        int withY = 0;
        for (int i = 0; i < g.length; i++)
            if (g[x][i] && g[y][i])
                withY++;
        return tot * k <= withY * 100;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        TreeMap<Integer, Integer> toId = new TreeMap<>();
        TreeMap<Integer, Integer> fromId = new TreeMap<>();
        TreeSet<Integer> all = new TreeSet<>();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
            all.add(a[i]);
            all.add(b[i]);
        }
        int cnt = 0;
        for (int elem : all) {
            toId.put(elem, cnt);
            fromId.put(cnt, elem);
            cnt++;
        }
        boolean[][] g = new boolean[cnt][cnt];
        for (int i = 0; i < n; i++) {
            a[i] = toId.get(a[i]);
            b[i] = toId.get(b[i]);
            g[a[i]][b[i]] = g[b[i]][a[i]] = true;
        }
        for (int i = 0; i < cnt; i++) {
            ArrayList<Integer> res = new ArrayList<>();
            for (int j = 0; j < cnt; j++)
                if (i != j && !g[i][j] && isFriend(g, i, j, k))
                    res.add(j);
            out.print(fromId.get(i) + ": ");
            out.print(res.size() + " ");
            for (int elem : res)
                out.print(fromId.get(elem) + " ");
            out.println();
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