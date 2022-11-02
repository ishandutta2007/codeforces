import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    final long MOD = 1000 * 1000 * 1000 + 7;
    final int N = 200 * 1000 + 10;

    long[] f;

    long binPow(long x, long n) {
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = res * x % MOD;
            x = x * x % MOD;
            n /= 2;
        }
        return res;
    }

    long inverse(long x) {
        return binPow(x, MOD - 2);
    }

    void prec() {
        f = new long[N];
        f[0] = 1;
        for (int i = 1; i < N; i++)
            f[i] = f[i - 1] * i % MOD;
    }

    long cnk(int n, int k) {
        long res = f[n];
        res = res * inverse(f[k]) % MOD;
        return res * inverse(f[n - k]) % MOD;
    }

    class Event {
        int x;
        int delta;

        Event(int x, int delta) {
            this.x = x;
            this.delta = delta;
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        prec();
        int n = in.nextInt();
        int k = in.nextInt();
        ArrayList<Event> events = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int l = in.nextInt();
            int r = in.nextInt() + 1;
            events.add(new Event(l, 1));
            events.add(new Event(r, -1));
        }
        Collections.sort(events, new Comparator<Event>() {
            public int compare(Event o1, Event o2) {
                return Integer.compare(o1.x, o2.x);
            }
        });
        int open = 0;
        long res = 0;
        for (int i = 0; i < events.size() - 1; i++) {
            Event e = events.get(i);
            open += e.delta;
            int len = events.get(i + 1).x - e.x;
            if (open >= k && len != 0) {
                long cur = cnk(open, k);
                cur = cur * len % MOD;
                res = (res + cur) % MOD;
            }
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