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
    }

    Pair check(int[] sum1, int[] sum2, int t) {
        int n =sum1.length - 1;
        int win1 = 0;
        int win2 = 0;
        int last = -1;
        int pos = 0;
        while (pos < n) {
            int low = pos - 1;
            int high = n - 1;
            if (Math.max(sum1[high + 1] - sum1[pos], sum2[high + 1] - sum2[pos]) < t)
                return null;
            while (high - low > 1) {
                int mid = (low + high) / 2;
                int max = Math.max(sum1[mid + 1] - sum1[pos], sum2[mid + 1] - sum2[pos]);
                if (max >= t)
                    high = mid;
                else
                    low = mid;
            }
            if (sum1[high + 1] - sum1[pos] > sum2[high + 1] - sum2[pos]) {
                win1++;
                last = 1;
            } else {
                win2++;
                last = 2;
            }
            pos = high + 1;
        }
        if (win1 == win2)
            return null;
        if (win1 > win2 && last != 1)
            return null;
        if (win2 > win1 && last != 2)
            return null;
        return new Pair(Math.max(win1, win2), t);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        int[] s1 = new int[n + 1];
        int[] s2 = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            s1[i] = s1[i - 1];
            s2[i] = s2[i - 1];
            if (a[i - 1] == 1)
                s1[i]++;
            else
                s2[i]++;
        }
        ArrayList<Pair> res = new ArrayList<>();
        for (int t = 1; t <= n; t++) {
            Pair p = check(s1, s2, t);
            if (p != null)
                res.add(p);
        }
        Collections.sort(res);
        out.println(res.size());
        for (int i = 0; i < res.size(); i++)
            out.println(res.get(i).first + " " + res.get(i).second);
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