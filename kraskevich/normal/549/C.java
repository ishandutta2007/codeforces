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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    boolean winFast(int odd, int even, int k) {
        int steps = odd + even - k;
        if (steps == 0)
            return odd % 2 == 1;
        int my = steps / 2 + steps % 2;
        int his = steps - my;
        if (his >= odd)
            return false;
        if (his >= even && k % 2 == 0)
            return false;
        if (my >= even && k % 2 == 1)
            return true;
        return my > his;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int odd = 0;
        int even = 0;
        for (int i = 0; i < n; i++) {
            int a = in.nextInt();
            if (a % 2 == 0)
                even++;
            else
                odd++;
        }
        out.println(winFast(odd, even, k) ? "Stannis" : "Daenerys");
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