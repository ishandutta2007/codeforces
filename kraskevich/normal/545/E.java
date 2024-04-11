import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Igor Kraskevich
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    final long INF = (long) 1e18;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        ArrayList<Integer>[] g = new ArrayList[n];
        ArrayList<Long>[] w = new ArrayList[n];
        ArrayList<Integer>[] nums = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            w[i] = new ArrayList<>();
            nums[i] = new ArrayList<>();
        }
        int[] from = new int[m];
        int[] to = new int[m];
        long[] weight = new long[m];
        for (int i = 0; i < m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            long len = in.nextLong();
            a--;
            b--;
            g[a].add(b);
            g[b].add(a);
            w[a].add(len);
            w[b].add(len);
            nums[a].add(i);
            nums[b].add(i);
            from[i] = a;
            to[i] = b;
            weight[i] = len;
        }
        TreeSet<Pair> queue = new TreeSet<>();
        int st = in.nextInt() - 1;
        queue.add(new Pair(0L, st));
        long[] dist = new long[n];
        int[] parId = new int[n];
        Arrays.fill(parId, -1);
        Arrays.fill(dist, INF);
        dist[st] = 0;
        while (!queue.isEmpty()) {
            int v = queue.pollFirst().second;
            for (int i = 0; i < g[v].size(); i++) {
                int tt = g[v].get(i);
                long len = w[v].get(i);
                if (dist[tt] > dist[v] + len || dist[tt] == dist[v] + len && len < weight[parId[tt]]) {
                    queue.remove(new Pair(dist[tt], tt));
                    dist[tt] = dist[v] + len;
                    parId[tt] = nums[v].get(i);
                    queue.add(new Pair(dist[tt], tt));
                }
            }
        }
        long res = 0;
        for (int i = 0; i < n; i++)
            if (i != st)
                res += weight[parId[i]];
        out.println(res);
        for (int i = 0; i < n; i++)
            if (i != st)
                out.print(parId[i] + 1 + " ");
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
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException e) {
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

class Pair implements Comparable<Pair> {
    public long first;
    public int second;

    public Pair(long first, int second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(Pair p) {
        if (first != p.first)
            return Long.compare(first, p.first);
        return Integer.compare(second, p.second);
    }

    public int hashCode() {
        return (int) first * 1_000_003 + second;
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (!(o instanceof Pair))
            return false;
        Pair p = (Pair) o;
        return first == p.first && second == p.second;
    }
}