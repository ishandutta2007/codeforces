import java.util.Arrays;
import java.util.TreeSet;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.math.BigInteger;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    int[] f;
    boolean[] used;
    int[] cycleLength;

    int dfs(int v, int start, int len) {
        if (f[v] == start)
            return len + 1;
        if (used[f[v]])
            return 0;
        used[v] = true;
        return dfs(f[v], start, len + 1);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        f = new int[n];
        for (int i = 0; i < n; i++)
            f[i] = in.nextInt() - 1;
        used = new boolean[n];
        cycleLength = new int[n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(used, false);
            cycleLength[i] = dfs(i, i, 0);
        }
        int low = 0;
        for (int i = 0; i < n; i++) {
            int v = i;
            int cur = 0;
            while (cycleLength[v] == 0) {
                cur++;
                v = f[v];
            }
            low = Math.max(low, cur);
        }
        TreeSet<Integer> all = new TreeSet<>();
        for (int i = 0; i < n; i++)
            if (cycleLength[i] >= 2)
                all.add(cycleLength[i]);
        BigInteger lcm = BigInteger.ONE;
        for (int elem : all) 
            lcm = lcm.divide(lcm.gcd(BigInteger.valueOf(elem))).multiply(BigInteger.valueOf(elem));
        BigInteger sol = lcm;
        while (sol.compareTo(BigInteger.valueOf(low)) < 0)
            sol = sol.add(lcm);
        out.println(sol);
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