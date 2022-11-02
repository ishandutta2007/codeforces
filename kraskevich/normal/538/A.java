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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.next();
        for (int i = 0; i < s.length(); i++)
            for (int j = i + 1; j <= s.length(); j++)
                if ((s.substring(0, i) + s.substring(j, s.length())).equals("CODEFORCES")) {
                    out.println("YES");
                    return;
                }
        out.println("NO");
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

}