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
		TaskD1 solver = new TaskD1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD1 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int rows = in.nextInt();
        int cols = in.nextInt();
        for (int i = 0; i < rows - 1; i++)
            in.next();
        String s = in.next();
        boolean clear = true;
        int cnt = 0;
        for (int i = 0; i < cols; i++)
            if (s.charAt(i) == 'B') {
                if (clear) {
                    clear = false;
                    cnt++;
                }
            } else {
                clear = true;
            }
        out.println(cnt);
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