import java.util.TreeMap;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.util.Map;
import java.util.Collection;
import java.io.OutputStream;
import java.util.Collections;
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

    Map<Long, Long> parEdgeCost = new TreeMap<>();

    ArrayList<Long> generatePath(long v) {
        ArrayList<Long> res = new ArrayList<>();
        while (v != 1) {
            res.add(v);
            v /= 2;
        }
        Collections.reverse(res);
        return res;
    }

    ArrayList<Long> combine(long v, long u) {
        ArrayList<Long> pv = generatePath(v);
        ArrayList<Long> pu = generatePath(u);
        int p = 0;
        while (p < pv.size() && p < pu.size() && pv.get(p).equals(pu.get(p)))
            p++;
        ArrayList<Long> res = new ArrayList<>(pv.subList(p, pv.size()));
        res.addAll(pu.subList(p, pu.size()));
        return res;
    }

    long getCost(ArrayList<Long> vs) {
        long res = 0;
        for (long v : vs)
            res += parEdgeCost.getOrDefault(v, 0L);
        return res;
    }

    void addCost(ArrayList<Long> vs, long delta) {
        for (long v : vs)
            parEdgeCost.put(v, parEdgeCost.getOrDefault(v, 0L) + delta);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int type = in.nextInt();
            if (type == 1) {
                long v = in.nextLong();
                long u = in.nextLong();
                long w = in.nextLong();
                addCost(combine(v, u), w);
            } else {
                long v = in.nextLong();
                long u = in.nextLong();
                out.println(getCost(combine(v, u)));
            }
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}