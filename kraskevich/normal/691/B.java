import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    String good = "AHIMOoTUVvWwXxY";

    boolean match(String s1, String s2) {
        if (s1.equals(s2) && good.contains(s1))
            return true;
        int c1 = s1.charAt(0);
        int c2 = s2.charAt(0);
        if (c1 == 'p' && c2 == 'q' || c1 == 'q' && c2 == 'p')
            return true;
        if (c1 == 'b' && c2 == 'd' || c1 == 'd' && c2 == 'b')
            return true;
        return false;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.next();
        int n = s.length();
        int l = (n - 1) / 2;
        int r = n / 2;
        boolean ok = true;
        while (l >= 0) {
            if (!match(s.substring(l, l + 1), s.substring(r, r + 1)))
                ok = false;
            l--;
            r++;
        }
        out.println(ok ? "TAK" : "NIE");
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