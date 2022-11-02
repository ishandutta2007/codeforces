import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.ArrayDeque;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashSet;
import java.io.InputStream;

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

    long getHash(ArrayDeque<Integer> deque) {
        long h = 0;
        for (int d : deque)
            h = h * 11 + d;
        return h;
    }

    long combine(long a, long b) {
        return a * 1_000_000_000_009L + b;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k1 = in.nextInt();
        ArrayDeque<Integer> d1 = new ArrayDeque<>();
        for (int i = 0; i < k1; i++)
            d1.addLast(in.nextInt());
        ArrayDeque<Integer> d2 = new ArrayDeque<>();
        int k2 = in.nextInt();
        for (int i = 0; i < k2; i++)
            d2.addLast(in.nextInt());
        int cnt = 0;
        Set<Long> was = new HashSet<>();
        for (;;) {
            if (d1.isEmpty()) {
                out.println(cnt + " " + 2);
                return;
            }
            if (d2.isEmpty()) {
                out.println(cnt + " " + 1);
                return;
            }
            long cur = combine(getHash(d1), getHash(d2));
            if (was.contains(cur)) {
                out.println(-1);
                return;
            }
            was.add(cur);
            int a = d1.pollFirst();
            int b = d2.pollFirst();
            if (a > b) {
                d1.addLast(b);
                d1.addLast(a);
            } else {
                d2.addLast(a);
                d2.addLast(b);
            }
            cnt++;
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