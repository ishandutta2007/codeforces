import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    final int N = 5_000_000 + 10;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int[] cnt = new int[N];
        int[] divs = new int[N];
        for (int i = 2; i < N; i++) {
            boolean fst = false;
            if (cnt[i] == 0) {
                cnt[i] = 1;
                fst = true;
            }
            if (cnt[i] == 1) {
                divs[i]++;
                for (int j = 2 * i; j < N; j += i) {
                    if (fst)
                        cnt[j]++;
                    divs[j]++;
                }
            }
        }
        for (int i = 1; i < N; i++)
            divs[i] += divs[i - 1];
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            out.println(divs[a] - divs[b]);
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