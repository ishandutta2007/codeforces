import java.util.Arrays;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskC2 solver = new TaskC2();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC2 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        int foo = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        int[] d1 = bfs(0);
        int v1 = getMaxIndex(d1);
        int[] d2 = bfs(v1);
        out.println(d2[getMaxIndex(d2)]);
    }

    ArrayList<Integer>[] g;
    int n;
    final int INF = 1_000_000;
    
    int getMaxIndex(int[] a) {
        int i = 0;
        for (int j = 0; j < a.length; j++)
            if (a[j] > a[i])
                i = j;
        return i;
    }

    int[] bfs(int v) {
        int[] dist = new int[n];
        Arrays.fill(dist, INF);
        dist[v] = 0;
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.addLast(v);
        while (q.size() > 0) {
            int u = q.pollFirst();
            for (int to : g[u])
                if (dist[to] > dist[u] + 1) {
                    dist[to] = dist[u] + 1;
                    q.addLast(to);
                }
        }
        return dist;
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