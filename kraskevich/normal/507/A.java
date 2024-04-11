import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
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
    class Pair {
        int first;
        int second;
        
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        ArrayList<Pair> pairs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int a = in.nextInt();
            pairs.add(new Pair(a, i + 1));
        }
        Collections.sort(pairs, new Comparator<Pair>() {
            public int compare(Pair o1, Pair o2) {
                return Integer.compare(o1.first, o2.first);
            }
        });
        ArrayList<Integer> result = new ArrayList<>();
        for (Pair p : pairs)
            if (p.first <= k) {
                k -= p.first;
                result.add(p.second);
            }
        out.println(result.size());
        for (int elem : result)
            out.print(elem + " ");
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