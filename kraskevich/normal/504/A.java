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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] deg = new int[n];
        int[] sum = new int[n];
        for (int i = 0; i < n; i++) {
            deg[i] = in.nextInt();
            sum[i] = in.nextInt();
        }
        TreeSet<Integer> one = new TreeSet<>();
        for (int i = 0; i < n; i++)
            if (deg[i] == 1)
                one.add(i);
        ArrayList<Integer> from = new ArrayList<>();
        ArrayList<Integer> to = new ArrayList<>();
        while (!one.isEmpty()) {
            int v = one.pollFirst();
            from.add(v);
            int u = sum[v];
            to.add(sum[v]);
            sum[v] = 0;
            sum[u] ^= v;
            deg[u]--;
            if (deg[u] == 1)
                one.add(u);
            else
                one.remove(u);
        }
        out.println(from.size());
        for (int i = 0; i < from.size(); i++)
            out.println(from.get(i) + " " + to.get(i));
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