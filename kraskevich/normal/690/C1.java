import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.io.InputStreamReader;

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
		TaskC1 solver = new TaskC1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC1 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        if (m != n - 1) {
            out.println("no");
            return;
        }
        Dsu dsu = new Dsu(n);
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            dsu.unite(a, b);
        }
        for (int i = 1; i < n; i++) {
            if (dsu.get(i) != dsu.get(0)) {
                out.println("no");
                return;
            }
        }
        out.println("yes");
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