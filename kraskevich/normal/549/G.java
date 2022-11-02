import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
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
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++)
            a.add(in.nextInt() + i);
        Collections.sort(a);
        for (int i = n - 2; i >= 0; i--)
            if (a.get(i) >= a.get(i + 1)) {
                out.println(":(");
                return;
            }
        for (int i = n - 1; i >= 0; i--) {
            if (a.get(i) - i < 0) {
                out.println(":(");
                return;
            }
        }
        for (int i = 0; i < n; i++)
            out.print((a.get(i) - i) + " ");
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