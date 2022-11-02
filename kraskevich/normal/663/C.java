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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    final int BLUE = 0;
    final int RED = 1;
    final int INF = 1_000_000;

    int res = INF;
    ArrayList<Integer> resList;
    int finalColor;
    ArrayList<Integer>[] g;
    ArrayList<Integer>[] edgeColor;
    ArrayList<Integer> first;
    ArrayList<Integer> second;
    int[] color;
    boolean ok;

    void dfs(int v, int curColor) {
        if (color[v] != -1 && color[v] != curColor) {
            ok = false;
            return;
        }
        if (color[v] != -1)
            return;
        color[v] = curColor;
        if (curColor == BLUE)
            first.add(v);
        else
            second.add(v);
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            int col = edgeColor[v].get(i);
            if (col == finalColor)
                dfs(to, curColor);
            else
                dfs(to, 1 - curColor);
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        edgeColor = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            edgeColor[i] = new ArrayList<>();
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            String s = in.next();
            g[a].add(b);
            g[b].add(a);
            int col = s.equals("B") ? BLUE : RED;
            edgeColor[a].add(col);
            edgeColor[b].add(col);
        }
        for (finalColor = 0; finalColor < 2; finalColor++) {
            color = new int[n];
            Arrays.fill(color, -1);
            ok = true;
            ArrayList<Integer> all = new ArrayList<>();
            for (int i = 0; i < n && ok; i++) {
                if (color[i] == -1) {
                    first = new ArrayList<>();
                    second = new ArrayList<>();
                    dfs(i, 0);
                    if (!ok)
                        break;
                    if (first.size() > second.size())
                        first = second;
                    for (int v : first)
                        all.add(v);
                }
            }
            if (!ok)
                continue;
            if (res > all.size()) {
                res = all.size();
                resList = all;
            }
        }
        if (res == INF) {
            out.println(-1);
            return;
        }
        out.println(res);
        Collections.sort(resList);
        for (int v : resList)
            out.print((v + 1) + " ");
        out.println();
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