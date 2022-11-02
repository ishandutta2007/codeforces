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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        char[] s = in.next().toCharArray();
        char[] t = in.next().toCharArray();
        long[][][] f = new long[2][2][n + 2];
        f[0][0][0] = 1;
        for (int pos = 0; pos <= n; pos++) {
            for (int d1 = 0; d1 < 2; d1++) {
                for (int d2 = 0; d2 < 2; d2++) {
                    int p1 = pos - d1;
                    int p2 = pos - d2;
                    if (p1 < 0 || p2 < 0)
                        continue;
                    for (char c = 'a'; c <= 'z'; c++) {
                        int inc1 = 0;
                        int inc2 = 0;
                        if (p1 >= s.length || s[p1] != c)
                            inc1 = 1;
                        if (p2 >= t.length || t[p2] != c)
                            inc2 = 1;
                        int nd1 = d1 + inc1;
                        int nd2 = d2 + inc2;
                        if (nd1 >= 2 || nd2 >= 2)
                            continue;
                        f[nd1][nd2][pos + 1] += f[d1][d2][pos];
                    }
                }
            }
            //out.println(f[0][0][pos] + " " + f[0][1][pos] + " " + f[1][0][pos] + " " + f[1][1][pos]);
        }
        out.println(f[1][1][n + 1]);
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