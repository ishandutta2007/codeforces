import java.util.TreeMap;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.util.Map;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Set;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    final long INF = (long) 1e16 + 10;

    long[] fact;
    int[] pw;

    void init() {
        fact = new long[30];
        fact[0] = 1;
        for (int i = 1; i < fact.length; i++) {
            fact[i] = Math.min(INF, fact[i - 1] * i);
        }
        pw = new int[15];
        pw[0] = 1;
        for (int i = 1; i < pw.length; i++)
            pw[i] = pw[i - 1] * 3;
    }

    long getFact(int n) {
        if (n < fact.length)
            return fact[n];
        return INF;
    }

    int getPow(int p) {
        return pw[p];
    }

    int getBit(int mask, int pos) {
        return mask / getPow(pos) % 3;
    }

    Map<Long, Integer>[] gen(List<Integer> list, int max) {
        Map<Long, Integer>[] res = new Map[max + 1];
        for (int i = 0; i < res.length; i++)
            res[i] = new TreeMap<>();
        int n = list.size();
        for (int mask = 0; mask < getPow(n); mask++) {
            long s = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int b = getBit(mask, i);
                if (b == 0) {
                    s += getFact(list.get(i));
                    cnt++;
                } else if (b == 1) {
                    s += list.get(i);
                }
            }
            res[cnt].put(s, 1 + res[cnt].getOrDefault(s, 0));
        }
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        init();
        int n = in.nextInt();
        int k = in.nextInt();
        long s = in.nextLong();
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(in.nextInt());
        }
        Map<Long, Integer>[] left = gen(a.subList(0, n / 2), n);
        Map<Long, Integer>[] right = gen(a.subList(n / 2, n), n);
        long res = 0;
        for (int c1 = 0; c1 <= k; c1++)
            for (Map.Entry<Long, Integer> entry : left[c1].entrySet())
                for (int c2 = 0; c1 + c2 <= k; c2++)
                    res += entry.getValue() * 1L * right[c2].getOrDefault(s - entry.getKey(), 0);
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}