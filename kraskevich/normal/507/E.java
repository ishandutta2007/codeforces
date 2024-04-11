import java.util.Arrays;
import java.util.TreeSet;
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
import java.util.Set;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    final int INF = 1_000_000_000;
    ArrayList<Integer>[] g;
    ArrayList<Integer>[] works;
    int[] dist;
    int[] mem;
    int[] par;

    int findShortestPath(int v) {
        if (mem[v] >= 0)
            return mem[v];
        if (v == 0)
            return 0;
        mem[v] = INF;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            int cost = 1 - works[v].get(i);
            if (dist[to] + 1 != dist[v])
                continue;
            int costTo = findShortestPath(to) + cost;
            if (costTo < mem[v]) {
                mem[v] = costTo;
                par[v] = to;
            }
        }
        return mem[v];
    }

    class Pair implements Comparable<Pair> {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair p) {
            if (first != p.first)
                return Integer.compare(first, p.first);
            return Integer.compare(second, p.second);
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        g = new ArrayList[n];
        works = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            works[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            a--;
            b--;
            g[a].add(b);
            g[b].add(a);
            works[a].add(c);
            works[b].add(c);
        }
        dist = new int[n];
        Arrays.fill(dist, INF);
        dist[0] = 0;
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(0);
        while (!queue.isEmpty()) {
            int v = queue.poll();
            for (int to : g[v])
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    queue.add(to);
                }
        }
        par = new int[n];
        mem = new int[n];
        Arrays.fill(mem, -1);
        findShortestPath(n - 1);
        Set<Pair> was = new TreeSet<>();
        for (int v = n - 1; v != 0; v = par[v]) {
            int a = Math.min(v, par[v]);
            int b = Math.max(v, par[v]);
            was.add(new Pair(a, b));
        }
        ArrayList<Integer> first = new ArrayList<>();
        ArrayList<Integer> second = new ArrayList<>();
        ArrayList<Integer> state = new ArrayList<>();
        for (int v = 0; v < n; v++) {
            for (int i = 0; i < g[v].size(); i++) {
                int to = g[v].get(i);
                boolean good = works[v].get(i) == 1 ? true : false;
                if (to < v)
                    continue;
                Pair cur = new Pair(v, to);
                if (was.contains(cur) && !good) {
                    first.add(v);
                    second.add(to);
                    state.add(1);
                } else if (!was.contains(cur) && good) {
                    first.add(v);
                    second.add(to);
                    state.add(0);
                }
            }
        }
        out.println(first.size());
        for (int i = 0; i < first.size(); i++) {
            int a = first.get(i);
            int b = second.get(i);
            int c = state.get(i);
            a++;
            b++;
            out.println(a + " " + b + " " + c);
        }
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
                // ignore
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