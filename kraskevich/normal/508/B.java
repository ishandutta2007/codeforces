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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.next();
        int last = -1;
        int lastDigit = s.charAt(s.length() - 1) - '0';
        for (int i = 0; i < s.length(); i++) {
            int curr = s.charAt(i) - '0';
            if (curr % 2 == 1)
                continue;
            last = i;
            if (curr < lastDigit) {
                break;
            }
        }
        if (last == -1) {
            out.println(-1);
            return;
        }
        out.println(s.substring(0, last) + s.substring(s.length() - 1) + 
                s.substring(last + 1, s.length() - 1) + s.substring(last, last + 1));
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