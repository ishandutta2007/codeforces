import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.BufferedReader;
import java.util.Map;
import java.util.Collection;
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
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            Map<Pair, Integer> pairs = new HashMap<>();
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    Pair cur = norm(x[i] - x[j], y[i] - y[j]);
                    pairs.put(cur, pairs.getOrDefault(cur, 0) + 1);
                }
            }
            for (int elem : pairs.values())
                res += elem * (elem - 1) / 2;
        }
        out.println(n * (n - 1) * 1L * (n - 2) / 6 - res / 3);
    }

    Pair norm(int a, int b) {
        if (a < 0) {
            a = -a;
            b = -b;
        }
        if (a == 0 && b < 0)
            b = -b;
        int g = gcd(Math.abs(a), Math.abs(b));
        a /= g;
        b /= g;
        return new Pair(a, b);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
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

class Pair implements Comparable<Pair> {
    public long first;
    public int second;

    public Pair(long first, int second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(Pair p) {
        if (first != p.first)
            return Long.compare(first, p.first);
        return Integer.compare(second, p.second);
    }

    public int hashCode() {
        return (int) first * 1_000_003 + second;
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (!(o instanceof Pair))
            return false;
        Pair p = (Pair) o;
        return first == p.first && second == p.second;
    }
}