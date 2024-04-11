import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
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

    final long INF = (long) 1e18;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        ArrayList<PairLong> events = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int w = in.nextInt();
            events.add(new PairLong(x + w, x - w));
        }
        Collections.sort(events);
        long last = -INF;
        int res = 0;
        for (PairLong p : events) {
            if (p.second >= last) {
                res++;
                last = p.first;
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

class PairLong implements Comparable<PairLong> {
    public long first;
    public long second;


    public PairLong(long first, long second) {
        this.first = first;
        this.second = second;
    }


    public int compareTo(PairLong p) {
        if (first != p.first) {
            return Long.compare(first, p.first);
        }
        return Long.compare(second, p.second);
    }

    public int hashCode() {
        return (int) (first * 1_000_003 + second);
    }

    public boolean equals(Object o) {
        if (!(o instanceof PairLong)) {
            return false;
        }
        PairLong p = (PairLong) o;
        return first == p.first && second == p.second;
    }
}