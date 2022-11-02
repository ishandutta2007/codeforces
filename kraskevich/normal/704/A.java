import java.util.TreeSet;
import java.util.ArrayList;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int unread = 0;
        TreeSet<Integer>[] ts = new TreeSet[n];
        for (int i = 0; i < n; i++)
            ts[i] = new TreeSet<>();
        int q = in.nextInt();
        int curTime = 0;
        ArrayList<Integer> all = new ArrayList<>();
        int last = 0;
        for (int qq = 0; qq < q; qq++) {
            int t = in.nextInt();
            if (t == 1) {
                int x = in.nextInt() - 1;
                ts[x].add(curTime);
                all.add(x);
                curTime++;
                unread++;
            } else if (t == 2) {
                int x = in.nextInt() - 1;
                unread -= ts[x].size();
                ts[x] = new TreeSet<>();
            } else {
                int time = in.nextInt();
                for (int i = last; i < time; i++) {
                    int x = all.get(i);
                    if (ts[x].contains(i))
                        unread--;
                    ts[x].remove(i);
                }
                last = Math.max(last, time);
            }
            out.println(unread);
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

}