import java.util.Arrays;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.BufferedReader;
import java.util.Map;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    ArrayList<Integer>[] g;
    ArrayList<Integer>[] gr;
    Map<Pair, Integer> count = new HashMap<>();
    int comps = 1;
    int[] compId;
    boolean[] was;
    int[] tin;
    int[] tup;
    int timer;
    int[] deltaUp;
    int[] deltaDown;
    boolean ok = true;

    void dfs1(int v, int par) {
        tin[v] = tup[v] = timer++;
        was[v] = true;
        for (int to : g[v]) {
            if (to == par)
                continue;
            if (!was[to]) {
                dfs1(to, v);
                tup[v] = Math.min(tup[v], tup[to]);
            } else {
                tup[v] = Math.min(tup[v], tin[to]);
            }
        }
    }

    void dfs2(int v, int curComp) {
        compId[v] = curComp;
        was[v] = true;
        for (int to : g[v])
            if (!was[to]) {
                int newComp = curComp;
                if (tup[to] > tin[v] && count.get(new Pair(to, v)) == 1)
                    newComp = comps++;
                dfs2(to, newComp);
            }
    }

    void dfs3(int v) {
        was[v] = true;
        for (int to : gr[v])
            if (!was[to]) {
                dfs3(to);
                deltaDown[v] += deltaDown[to];
                deltaUp[v] += deltaUp[to];
            }
        if (deltaDown[v] > 0 && deltaUp[v] > 0)
            ok = false;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        tin = new int[n];
        tup = new int[n];
        compId = new int[n];
        was = new boolean[n];
        Dsu dsu = new Dsu(n);
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            count.put(new Pair(a, b), count.getOrDefault(new Pair(a, b), 0) + 1);
            count.put(new Pair(b, a), count.getOrDefault(new Pair(b, a), 0) + 1);
            g[a].add(b);
            g[b].add(a);
            dsu.unite(a, b);
        }
        for (int i = 0; i < n; i++)
            if (!was[i])
                dfs1(i, i);
        Arrays.fill(was, false);
        for (int i = 0; i < n; i++)
            if (!was[i])
                dfs2(i, comps - 1);
        gr = new ArrayList[comps];
        for (int i = 0; i < comps; i++)
            gr[i] = new ArrayList<>();
        for (int a = 0; a < n; a++)
            for (int b : g[a]) {
                int u = compId[a];
                int v = compId[b];
                if (u != v) {
                    gr[v].add(u);
                    gr[u].add(v);
                }
            }
LcaComputer lcaComputer = new LcaComputer(gr);
        deltaDown = new int[comps];
        deltaUp = new int[comps];
        for (int i = 0; i < q; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            if (dsu.get(a) != dsu.get(b)) {
                out.println("No");
                return;
            }
            a = compId[a];
            b = compId[b];
            int lca = lcaComputer.getLca(a, b);
            deltaDown[a]++;
            deltaDown[lca]--;
            deltaUp[b]++;
            deltaUp[lca]--;
        }
        was = new boolean[comps];
        for (int i = 0; i < comps; i++)
            if (!was[i])
                dfs3(i);
        out.println(ok ? "Yes" : "No");
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

class Dsu {
    private int[] par;

    public Dsu(int n) {
        par = new int[n];
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    public int get(int v) {
        return par[v] == v ? v : (par[v] = get(par[v]));
    }

    public int unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a != b) {
            par[a] = b;
            return 1;
        } else {
            return 0;
        }
    }
}

class LcaComputer {

    private int LOG;
    private final ArrayList<Integer>[] g;
    private int[][] ancestorAtDepth;
    private int[] timeIn;
    private int[] timeOut;
    private int[] depth;
    private int[] subtreeSize;
    private boolean[] used;
    private int timer;
    private int vertexCount;
    private int root;

    public LcaComputer(ArrayList<Integer>[] g, int root) {
        this.g = g;
        this.root = root;
        vertexCount = g.length;
        LOG = 10;
        while ((1 << (LOG)) <= vertexCount)
            LOG++;
        LOG++;
        ancestorAtDepth = new int[vertexCount][LOG];
        timeIn = new int[vertexCount];
        timeOut = new int[vertexCount];
        depth = new int[vertexCount];
        subtreeSize = new int[vertexCount];
        used = new boolean[vertexCount];
        for (int i = 0; i < vertexCount; i++)
            if (!used[i])
                dfs(i, i, 0);
    }

    public LcaComputer(ArrayList<Integer>[] g) {
        this(g, 0);
    }

    private void dfs(int vertexId, int parent, int curHeight) {
        used[vertexId] = true;
        timeIn[vertexId] = timer++;
        depth[vertexId] = curHeight;
        subtreeSize[vertexId] = 1;
        ancestorAtDepth[vertexId][0] = parent;
        for (int i = 1; i < LOG; i++)
            ancestorAtDepth[vertexId][i] = ancestorAtDepth[ancestorAtDepth[vertexId][i - 1]][i - 1];
        for (int to : g[vertexId])
            if (!used[to]) {
                dfs(to, vertexId, curHeight + 1);
                subtreeSize[vertexId] += subtreeSize[to];
            }
        timeOut[vertexId] = timer++;
    }

    public boolean isAncestor(int a, int b) {
        return timeIn[a] <= timeIn[b] && timeIn[b] <= timeOut[a];
    }

    public int getLca(int a, int b) {
        if (a >= vertexCount || b >= vertexCount)
            throw new AssertionError("vertices are out of range");
        if (isAncestor(a, b))
            return a;
        if (isAncestor(b, a))
            return b;
        for (int i = LOG - 1; i >= 0; i--)
            if (!isAncestor(ancestorAtDepth[a][i], b))
                a = ancestorAtDepth[a][i];
        return ancestorAtDepth[a][0];
    }

}