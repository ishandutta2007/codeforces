import java.util.TreeMap;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Map;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    TreeMultiSet<Integer>[] g;
    ArrayList<Integer> order = new ArrayList<>();

    void dfs(int v) {
        while (g[v].size() > 0) {
            int to = g[v].getFirst();
            g[v].remove(to);
            g[to].remove(v);
            dfs(to);
            order.add(v);
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] deg = new int[n];
        g = new TreeMultiSet[n];
        for (int i = 0; i < n; i++) {
            g[i] = new TreeMultiSet<>();
        }
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
            deg[a]++;
            deg[b]++;
        }
        ArrayList<Integer> odd = new ArrayList<>();
        for (int i = 0; i < n; i++)
            if (deg[i] % 2 == 1)
                odd.add(i);
        for (int i = 0; i < odd.size(); i += 2) {
            int a = odd.get(i);
            int b = odd.get(i + 1);
            g[a].add(b);
            g[b].add(a);
            m++;
        }
        if (m % 2 == 1) {
            m++;
            g[0].add(0);
            g[0].add(0);
        }
        dfs(0);
        out.println(m);
        System.err.println(order);
        for (int i = 0; i < order.size(); i += 2) {
            out.println(order.get(i) + 1 + " " + (order.get(i + 1) + 1));
        }
        for (int i = 1; i < order.size(); i += 2) {
            out.println(order.get((i + 1) % order.size()) + 1 + " " + (order.get(i) + 1));
        }
    }
}

class TreeMultiSet<T extends Comparable<? super T>> {

    private Map<T, Integer> map = new TreeMap<>();
    int size;

    public void add(T value) {
        size++;
        map.put(value, map.getOrDefault(value, 0) + 1);
    }

    public int count(T value) {
        return map.getOrDefault(value, 0);
    }

    public boolean remove(T value) {
        int cur = count(value);
        if (cur == 0)
            return false;
        size--;
        if (cur == 1) {
            map.remove(value);
        } else {
            map.put(value, cur - 1);
        }
        return true;
    }

    public int size() {
        return size;
    }

    public T getFirst() {
        return map.keySet().iterator().next();
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