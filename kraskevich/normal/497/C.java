import java.util.Arrays;
import java.util.TreeSet;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    class Pair implements Comparable<Pair> {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair p) {
            if (first != p.first)
                return Integer.compare(first, p.first);
            return Integer.compare(second, p.second);
        }

        public boolean equals(Object o) {
            if (!(o instanceof Pair))
                return false;
            Pair p = (Pair) o;
            return this.compareTo(p) == 0;
        }
    }

    class Event implements Comparable<Event> {
        int x;
        int type;
        int id;

        Event(int x, int type, int id) {
            this.x = x;
            this.type = type;
            this.id = id;
        }

        public int compareTo(Event e) {
            if (x != e.x)
                return Integer.compare(x, e.x);
            return Integer.compare(type, e.type);
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] res = new int[n];
        Arrays.fill(res, -1);
        ArrayList<Event> e = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
            e.add(new Event(a[i], 2, i));
        }
        int m = in.nextInt();
        int[] c = new int[m];
        int[] d = new int[m];
        int[] cnt = new int[m];
        for (int i = 0; i < m; i++) {
            c[i] = in.nextInt();
            d[i] = in.nextInt();
            cnt[i] = in.nextInt();
            e.add(new Event(c[i], 1, i));
            e.add(new Event(d[i], 3, i));
        }
        Collections.sort(e);
        TreeSet<Pair> have = new TreeSet<>();
        for (Event event : e) {
            if (event.type == 1) {
                int i = event.id;
                have.add(new Pair(d[i], i));
            } else if (event.type == 3) {
                int i = event.id;
                have.remove(new Pair(d[i], i));
            } else {
                int i = event.id;
                int right = b[i];
                Pair p = have.ceiling(new Pair(right, 0));
                if (p == null) {
                    out.println("NO");
                    return;
                }
                res[i] = p.second;
                cnt[p.second]--;
                if (cnt[p.second] == 0)
                    have.remove(p);
            }
        }
        out.println("YES");
        for (int i = 0; i < n; i++)
            out.print((res[i] + 1) + " ");
        out.println();
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