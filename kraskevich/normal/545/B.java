import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.next();
        String t = in.next();
        ArrayList<Integer> diff = new ArrayList<>();
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) != t.charAt(i))
                diff.add(i);
        if (diff.size() % 2 == 1) {
            out.println("impossible");
            return;
        }
        char[] res = s.toCharArray();
        for (int i = 0; i < diff.size(); i++)
            if (i < diff.size() / 2)
                res[diff.get(i)] = s.charAt(diff.get(i));
            else
                res[diff.get(i)] = t.charAt(diff.get(i));
        out.println(new String(res));
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