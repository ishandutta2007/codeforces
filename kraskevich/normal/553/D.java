import java.util.Arrays;
import java.util.TreeSet;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    ArrayList<Integer>[] g;
    boolean[] have;
    int[] bad;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        have = new boolean[n];
        bad = new int[k];
        for (int i = 0; i < k; i++)
            bad[i] = in.nextInt() - 1;
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        Arrays.fill(have, true);
        for (int i = 0; i < k; i++)
            have[bad[i]] = false;
        Ratio[] ratios = new Ratio[n];
        TreeSet<Ratio> q = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            if (have[i]) {
                int good = 0;
                for (int to : g[i])
                    if (have[to])
                        good++;
                ratios[i] = new Ratio(good, g[i].size(), i);
                q.add(ratios[i]);
            }
        }
        Ratio best = new Ratio(q.first().num, q.first().denom, -1);
        while (q.size() > 1) {
            int v = q.pollFirst().id;
            have[v] = false;
            for (int to : g[v])
                if (have[to]) {
                    q.remove(ratios[to]);
                    ratios[to].subtractOne();
                    q.add(ratios[to]);
                }
            Ratio cur = q.first();
            if (best.compareTo(cur) < 0)
                best = new Ratio(cur.num, cur.denom, -1);
        }

        Arrays.fill(have, true);
        for (int i = 0; i < k; i++)
            have[bad[i]] = false;
        ratios = new Ratio[n];
        q.clear();
        for (int i = 0; i < n; i++) {
            if (have[i]) {
                int good = 0;
                for (int to : g[i])
                    if (have[to])
                        good++;
                ratios[i] = new Ratio(good, g[i].size(), i);
                q.add(ratios[i]);
            }
        }
        if (best.equals(q.first())) {
            print(out, have);
            return;
        }
        while (q.size() > 1) {
            int v = q.pollFirst().id;
            have[v] = false;
            for (int to : g[v])
                if (have[to]) {
                    q.remove(ratios[to]);
                    ratios[to].subtractOne();
                    q.add(ratios[to]);
                }
            Ratio cur = q.first();
            if (best.equals(cur)) {
                print(out, have);
                return;
            }
        }
    }

    void print(PrintWriter out, boolean[] have) {
        int cnt = 0;
        for (int i = 0; i < have.length; i++)
            if (have[i])
                cnt++;
        out.println(cnt);
        for (int i = 0; i < have.length; i++)
            if (have[i])
                out.print((i + 1) + " ");
        out.println();
    }

    class Ratio implements Comparable<Ratio> {
        int num;
        int denom;
        int id;

        Ratio(int num, int denom, int id) {
            this.num = num;
            this.denom = denom;
            this.id = id;
        }

        void subtractOne() {
            this.num--;
        }

        public int compareTo(Ratio other) {
            long left = num * 1L * other.denom;
            long right = denom * 1L * other.num;
            if (left != right)
                return Long.compare(left, right);
            return Integer.compare(id, other.id);
        }

        public boolean equals(Object o) {
            if (!(o instanceof Ratio))
                return false;
            Ratio other = (Ratio) o;
            long left = num * 1L * other.denom;
            long right = denom * 1L * other.num;
            return left == right;
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