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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int k = in.nextInt();
        if (k == 1) {
            out.println("YES");
            out.println("2 1");
            out.println("1 2");
            return;
        }
        if (k % 2 == 0) {
            out.println("NO");
            return;
        }
        ArrayList<Integer> treeFrom = new ArrayList<>();
        ArrayList<Integer> treeTo = new ArrayList<>();
        for (int i = 1; i <= k - 1; i++) {
            treeFrom.add(0);
            treeTo.add(i);
        }
        int firstLeave = k;
        int lastLeave = firstLeave + (k - 1) * (k - 1) - 1;
        for (int i = firstLeave; i <= lastLeave; i++) {
            int par = 1 + (i - firstLeave) / (k - 1);
            treeFrom.add(par);
            treeTo.add(i);
        }
        for (int from = 0; from < (k - 1) * (k - 1); from++)
            for (int d = 1; d <= (k - 1) / 2; d++) {
                int to = (from + d) % ((k - 1) * (k - 1));
                treeFrom.add(from + firstLeave);
                treeTo.add(to + firstLeave);
            }
        out.println("YES");
        int[] deg = new int[(lastLeave + 1) * 2];
        out.println((lastLeave + 1) * 2 + " " + (treeFrom.size() * 2 + 1));
        for (int i = 0; i < treeFrom.size(); i++) {
            out.println((treeFrom.get(i) + 1) + " " + (treeTo.get(i) + 1));
            deg[treeFrom.get(i)]++;
            deg[treeTo.get(i)]++;
        }
        for (int i = 0; i < treeFrom.size(); i++) {
            out.println((treeFrom.get(i) + lastLeave + 2) + " " + (treeTo.get(i) + lastLeave + 2));
            deg[treeFrom.get(i) + lastLeave + 1]++;
            deg[treeTo.get(i) + lastLeave + 1]++;
        }
        out.println(1 + " " + (lastLeave + 2));
        deg[0]++;
        deg[lastLeave + 1]++;
        for (int i = 0; i < deg.length; i++)
            if (deg[i] != k)
                throw new AssertionError(i + "");
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