import java.util.TreeSet;
import java.util.TreeMap;
import java.io.InputStream;
import java.io.InputStreamReader;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int w = in.nextInt();
        int h = in.nextInt();
        int n = in.nextInt();
        TreeMap<Integer, Integer> cntX = new TreeMap<>();
        cntX.put(w, 1);
        TreeMap<Integer, Integer> cntY = new TreeMap<>();
        cntY.put(h, 1);
        TreeSet<Integer> ver = new TreeSet<>();
        TreeSet<Integer> hor = new TreeSet<>();
        hor.add(0);
        ver.add(0);
        hor.add(h);
        ver.add(w);
        for (int i = 0; i < n; i++) {
            String type = in.next();
            int c = in.nextInt();
            if (type.equals("H")) {
                int lower = hor.lower(c);
                int upper = hor.higher(c);
                int cur = cntY.get(upper - lower);
                if (cur == 1)
                    cntY.remove(upper - lower);
                else
                    cntY.put(upper - lower, cur - 1);
                hor.add(c);
                cntY.put(c - lower, cntY.getOrDefault(c - lower, 0) + 1);
                cntY.put(upper - c, cntY.getOrDefault(upper - c, 0) + 1);
            } else {
                int lower = ver.lower(c);
                int upper = ver.higher(c);
                int cur = cntX.get(upper - lower);
                if (cur == 1)
                    cntX.remove(upper - lower);
                else
                    cntX.put(upper - lower, cur - 1);
                ver.add(c);
                cntX.put(c - lower, cntX.getOrDefault(c - lower, 0) + 1);
                cntX.put(upper - c, cntX.getOrDefault(upper - c, 0) + 1);
            }
            out.println(cntX.lastKey() * 1L * cntY.lastKey());
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