import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.List;
import java.io.BufferedReader;
import java.util.Map;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    final int ALPHABET = 256;
    final int N = ALPHABET * ALPHABET;

    ArrayList<Integer>[] g;
    ArrayList<Integer> res = new ArrayList<>();

    int getId(char c1, char c2) {
        return c1 * ALPHABET + c2;
    }

    void dfs(int v) {
        while (g[v].size() > 0) {
            int to = g[v].get(g[v].size() - 1);
            g[v].remove(g[v].size() - 1);
            dfs(to);
        }
        res.add(v);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++)
            s[i] = in.next();
        g = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            g[i] = new ArrayList<>();
        }
        int[] degIn = new int[N];
        int[] degOut = new int[N];
        Map<Pair, Integer> toId = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int pref = getId(s[i].charAt(0), s[i].charAt(1));
            int suf = getId(s[i].charAt(1), s[i].charAt(2));
            degIn[suf]++;
            degOut[pref]++;
            toId.put(new Pair(pref, suf), i);
            g[pref].add(suf);
        }
        int start = 0;
        for (int i = 0; i < N; i++)
            if (degOut[i] > 0)
                start = i;
        for (int i = 0; i < N; i++)
            if (degOut[i] > degIn[i])
                start = i;
        int cntOut = 0;
        int cntIn = 0;
        boolean ok = true;
        for (int i = 0; i < N; i++) {
            if (degOut[i] - degIn[i] == 1)
                cntOut++;
            if (degIn[i] - degOut[i] == 1)
                cntIn++;
            if (Math.abs(degIn[i] - degOut[i]) >= 2)
                ok = false;
        }
        if (cntIn > 1 || cntOut > 1)
            ok = false;
        dfs(start);
        Collections.reverse(res);
        if (!ok || res.size() != n + 1) {
            out.println("NO");
            return;
        }
        out.println("YES");
        for (int i = 1; i <= n; i++) {
            int a = res.get(i - 1);
            int b = res.get(i);
            String curr = s[toId.get(new Pair(a, b))];
            if (i == 1)
                out.print(curr);
            else
                out.print(curr.charAt(2));
        }
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

class Pair implements Comparable<Pair> {
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(Pair p) {
        if (first != p.first)
            return Integer.compare(first, p.first);
        return Integer.compare(second, p.second);
    }

    public int hashCode() {
        return first * 1_000_003 + second;
    }

    public boolean equals(Object o) {
        if (o == null || !(o instanceof Pair))
            return false;
        Pair p = (Pair) o;
        return first == p.first && second == p.second;
    }
}