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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    
    LcaComputer lcaComputer;
    
    int getSolution(int a, int b) {
        if (a == b)
            return lcaComputer.getVertexCount();
        int lca = lcaComputer.getLca(a, b);
        int[] height = lcaComputer.getDepths();
        int[] size = lcaComputer.getSubtreeSizes();
        int dist = height[a] + height[b] - 2 * height[lca];
        if (dist % 2 == 1)
            return 0;
        if (height[a] < height[b]) {
            int t = a;
            a = b;
            b = t;
        }
        if (height[a] == height[b]) {
            int d1 = height[a] - height[lca];
            int ancA = lcaComputer.getAncestorByDepth(a, d1 - 1);
            int ancB = lcaComputer.getAncestorByDepth(b, d1 - 1);
            return lcaComputer.getVertexCount() - size[ancA] - size[ancB];
        } else {
            int d1 = dist / 2;
            int ancA = lcaComputer.getAncestorByDepth(a, d1);
            int ancLow = lcaComputer.getAncestorByDepth(a, d1 - 1);
            return size[ancA] - size[ancLow];
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            a--;
            b--;
            g[a].add(b);
            g[b].add(a);
        }
        lcaComputer = new LcaComputer(g);
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            a--;
            b--;
            out.println(getSolution(a, b));
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
        dfs(0, 0, 0);
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
        if (isAncestor(a, b))
            return a;
        if (isAncestor(b, a))
            return b;
        for (int i = LOG - 1; i >= 0; i--)
            if (!isAncestor(ancestorAtDepth[a][i], b))
                a = ancestorAtDepth[a][i];
        return ancestorAtDepth[a][0];
    }

    public int getAncestorByDepth(int v, int deltaDepth) {
        for (int i = 0; i < LOG; i++)
            if ((deltaDepth & (1 << i)) != 0)
                v = ancestorAtDepth[v][i];
        return v;
    }
    
    public int[] getSubtreeSizes() {
        return subtreeSize;
    }
    
    public int[] getDepths() {
        return depth;
    }
    
    public int getVertexCount() {
        return vertexCount;
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