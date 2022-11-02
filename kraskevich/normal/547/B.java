import java.util.ArrayDeque;
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
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] goLeft = new int[n];
        int[] goRight = new int[n];
        int[] a = new int[n];
        int[] res = new int[n + 1];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        ArrayDeque<Integer> pos = new ArrayDeque<>();
        ArrayDeque<Integer> val = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            while (val.size() > 0 && a[i] <= val.getFirst()) {
                val.pollFirst();
                pos.pollFirst();
            }
            if (val.size() == 0)
                goLeft[i] = -1;
            else
                goLeft[i] = pos.getFirst();
            val.addFirst(a[i]);
            pos.addFirst(i);
        }
        pos.clear();
        val.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (val.size() > 0 && a[i] <= val.getFirst()) {
                val.pollFirst();
                pos.pollFirst();
            }
            if (val.size() == 0)
                goRight[i] = n;
            else
                goRight[i] = pos.getFirst();
            val.addFirst(a[i]);
            pos.addFirst(i);
        }
        for (int i = 0; i < n; i++)
            res[goRight[i] - goLeft[i] - 1] = Math.max(res[goRight[i] - goLeft[i] - 1], a[i]);
        for (int i = n - 1; i >= 0; i--)
            res[i] = Math.max(res[i], res[i + 1]);
        for (int i = 1; i <= n; i++)
            out.print(res[i] + " ");
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