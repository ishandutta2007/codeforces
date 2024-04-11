import java.util.Arrays;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Collection;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Queue;
import java.io.IOException;
import java.util.StringTokenizer;

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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    final int INF = 1000 * 1000;

    ArrayList<Integer>[] g;

    int[] bfs(int st) {
        int n = g.length;
        int[] dist = new int[n];
        Arrays.fill(dist, INF);
        dist[st] = 0;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(st);
        while (!q.isEmpty()) {
            int v = q.poll();
            for (int to : g[v])
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.add(to);
                }
        }
        return dist;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        int s1 = in.nextInt() - 1;
        int t1 = in.nextInt() - 1;
        int l1 = in.nextInt();
        int s2 = in.nextInt() - 1;
        int t2 = in.nextInt() - 1;
        int l2 = in.nextInt();
        int[][] dist = new int[n][];
        for (int i = 0; i < n; i++)
            dist[i] = bfs(i);
        if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
            out.println(-1);
            return;
        }
        int res = dist[s1][t1] + dist[s2][t2];
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++) {
                int d1 = Math.min(dist[s1][a] + dist[t1][b], dist[s1][b] + dist[t1][a]);
                int d2 = Math.min(dist[s2][a] + dist[t2][b], dist[s2][b] + dist[t2][a]);
                if (d1 + dist[a][b] <= l1 && d2 + dist[a][b] <= l2) 
                    res = Math.min(res, d1 + d2 + dist[a][b]);
            }
        out.println(m - res);
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

}