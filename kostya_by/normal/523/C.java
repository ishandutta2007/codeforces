import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author kostya_by
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        String t = in.next();
        int a = firstOccurrence(s, t);
        if (a == -1) {
            out.println(0);
            return;
        }
        s = new StringBuilder(s).reverse().toString();
        t = new StringBuilder(t).reverse().toString();
        int b = firstOccurrence(s, t);
        b = t.length() - b - 1;
        out.println( Math.max(0, b - a) );
    }

    int firstOccurrence(String s, String t) {
        int ptr = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t.charAt(i) == s.charAt(ptr)) {
                ptr += 1;
                if (ptr == s.length()) {
                    return i;
                }
            }
        }
        return -1;
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public String readLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return line;
    }
}