import java.util.ArrayList;
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
		TaskC3 solver = new TaskC3();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC3 {

    ArrayList<Integer>[] g;
    LcaComputer lcaComputer;
    int[] h;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        int[] par = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            par[i] = in.nextInt() - 1;
            g[i + 1].add(par[i]);
            g[par[i]].add(i + 1);
        }
        lcaComputer = new LcaComputer(g);
        h = lcaComputer.getDepths();
        int v = 0;
        int u = 0;
        int curD = 0;
        for (int i = 1; i < n; i++) {
            if (getDist(v, i) > curD) {
                curD = getDist(v, i);
                u = i;
            }
            else if (getDist(u, i) > curD) {
                curD = getDist(u, i);
                v = i;
            }
            out.print(curD + " ");
        }
    }

    int getDist(int a, int b) {
        int l = lcaComputer.getLca(a, b);
        return h[a] + h[b] - 2 * h[l];
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

    public int[] getDepths() {
        return depth;
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