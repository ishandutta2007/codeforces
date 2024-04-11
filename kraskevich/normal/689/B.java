import java.util.Arrays;
import java.util.TreeSet;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    final int INF = 1_000_000_000;

    class Vertex  implements Comparable<Vertex> {
        int dist;
        int v;

        Vertex(int dist, int v) {
            this.dist = dist;
            this.v = v;
        }

        public boolean equals(Object o) {
            if (!(o instanceof Vertex))
                return false;
            return v == ((Vertex) o).v;
        }

        public int compareTo(Vertex o) {
            if (dist != o.dist)
                return Integer.compare(dist, o.dist);
            return Integer.compare(v, o.v);
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] to = new int[n];
        for (int i = 0; i < n; i++)
            to[i] = in.nextInt() - 1;
        int[] f = new int[n];
        Arrays.fill(f, INF);
        f[0] = 0;
        TreeSet<Vertex> queue = new TreeSet<>();
        queue.add(new Vertex(0, 0));
        while (queue.size() > 0) {
            int v = queue.pollFirst().v;
            if (v - 1 >= 0 && f[v - 1] > f[v] + 1) {
                queue.remove(new Vertex(f[v - 1], v - 1));
                f[v - 1] = f[v] + 1;
                queue.add(new Vertex(f[v - 1], v - 1));
            }
            if (v + 1 < n && f[v + 1] > f[v] + 1) {
                queue.remove(new Vertex(f[v + 1], v + 1));
                f[v + 1] = f[v] + 1;
                queue.add(new Vertex(f[v + 1], v + 1));
            }
            if (f[to[v]] > f[v] + 1) {
                queue.remove(new Vertex(f[to[v]], to[v]));
                f[to[v]] = f[v] + 1;
                queue.add(new Vertex(f[to[v]], to[v]));
            }
        }
        for (int i = 0; i < n; i++)
            out.print(f[i] + " ");
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