import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.BufferedReader;
import java.util.Map;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    long[] cost = new long[26];

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        for (int i = 0; i < cost.length; i++)
            cost[i] = in.nextInt();
        String s = in.next();
        int n = s.length();
        Map<Long, Long>[] count = new HashMap[26];
        for (int i = 0; i < count.length; i++)
            count[i] = new HashMap<>();
        long sum = 0;
        long res = 0;
        for (int i = 0; i < n; i++) {
            int code = s.charAt(i) - 'a';
            res += count[code].getOrDefault(sum, 0L);
            sum += cost[code];
            count[code].put(sum, count[code].getOrDefault(sum, 0L) + 1);
        }
        out.println(res);
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