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
    char next(char c) {
        int code = c - 'a';
        code--;
        code += 26;
        code %= 26;
        return (char) (code + 'a');
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.next();
        int n = s.length();
        int i = 0;
        while (i < n && s.charAt(i) == 'a')
            i++;
        if (i == n) {
            for (int j = 0; j < n - 1; j++)
                out.print('a');
            out.print('z');
            return;
        }
        out.print(s.substring(0, i));
        while (i < n && s.charAt(i) != 'a') {
            out.print(next(s.charAt(i)));
            i++;
        }
        out.print(s.substring(i, n));
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

}