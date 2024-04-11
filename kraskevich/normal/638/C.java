import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    ArrayList<Integer>[] g;
    ArrayList<Integer>[] id;
    ArrayList<Integer>[] at;
    boolean[] was;
    int[] par;
    int[] parColor;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        id = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            id[i] = new ArrayList<>();
        }
        par = new int[n];
        parColor = new int[n];
        was = new boolean[n];
        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
            id[a].add(i);
            id[b].add(i);
        }
        int maxV = 0;
        for (int i = 0; i < n; i++)
            if (g[i].size() > g[maxV].size())
                maxV = i;
        int v = maxV;
        int res = g[v].size();
        Arrays.fill(par, -1);
        Arrays.fill(parColor, -1);
        at = new ArrayList[res];
        for (int d = 0; d < res; d++)
            at[d] = new ArrayList<>();
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        queue.addLast(v);
        was[v] = true;
        while (!queue.isEmpty()) {
            int from = queue.pollFirst();
            //System.err.println(from);
            int color = 0;
            for (int i = 0; i < g[from].size(); i++) {
                int to = g[from].get(i);
                int curId = id[from].get(i);
                if (to == par[from])
                    continue;
                if (color == parColor[from])
                    color++;
                was[to] = true;
                par[to] = from;
                parColor[to] = color;
                at[color].add(curId);
                queue.addLast(to);
                color++;
            }
        }
        out.println(at.length);
        for (ArrayList<Integer> atDay : at) {
            out.print(atDay.size() + " ");
            for (int elem : atDay)
                out.print((elem + 1) + " ");
            out.println();
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