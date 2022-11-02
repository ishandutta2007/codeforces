import java.util.Arrays;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
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
    ArrayList<Integer>[] g;
    ArrayList<Integer>[] gr;
    ArrayList<Integer> od = new ArrayList<>();
    boolean[] was;
    int size;
    int cnt;
    int[] comp;

    void dfs1(int v) {
        was[v] = true;
        for (int to : g[v])
            if (!was[to])
                dfs1(to);
        od.add(v);
    }

    void dfs2(int v) {
        comp[v] = cnt;
        size++;
        was[v] = true;
        for (int to : gr[v])
            if (!was[to])
                dfs2(to);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        g = new ArrayList[n];
        gr = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            gr[i] = new ArrayList<>();
        }
        was = new boolean[n];
        for (int i = 0; i < m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            a--;
            b--;
            g[a].add(b);
            gr[b].add(a);
        }
        for (int i = 0; i < n; i++)
            if (!was[i])
                dfs1(i);
        Collections.reverse(od);
        Arrays.fill(was, false);
        comp = new int[n];
        ArrayList<Integer> sizes = new ArrayList<>();
        for (int v : od)
            if (!was[v]) {
                size = 0;
                dfs2(v);
                sizes.add(size);
                cnt++;
            }
        //System.err.println(Arrays.toString(comp));
        Dsu dsu = new Dsu(cnt);
        for (int i = 0; i < n; i++)
            for (int to : g[i])
                dsu.unite(comp[i], comp[to]);
        boolean[] strong = new boolean[cnt];
        int[] size = new int[cnt];
        for (int i = 0; i < cnt; i++) {
            int r = dsu.get(i);
            size[r] += sizes.get(i);
            if (sizes.get(i) > 1)
                strong[r] = true;
        }
        int res = 0;
        for (int i = 0; i < cnt; i++)
            if (size[i] >= 1) {
                if (strong[i])
                    res += size[i];
                else
                    res += size[i] - 1;
            }
        out.println(res);
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