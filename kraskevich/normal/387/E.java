import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                int k = in.nextInt();
                int[] pos = new int[n];
                for (int i = 0; i < n; i++) {
                        int x = in.nextInt();
                        pos[x - 1] = i;
                }
                boolean[] need = new boolean[n];
                for (int i = 0; i < k; i++) {
                        int x = in.nextInt();
                        need[x - 1] = true;
                }
                BinaryIndexTree tree = new BinaryIndexTree(n);
                for (int i = 0; i < n; i++)
                        tree.add(i, 1);
                TreeSet<Integer> taken = new TreeSet<>();
                taken.add(n);
                taken.add(-1);
                long res = 0;
                for (int i = 0; i < n; i++) {
                        if (!need[i]) {
                                int now = pos[i];
                                int up = taken.higher(now);
                                int down = taken.lower(now);
                                res += tree.get(down + 1, up - 1);
                        } else {
                                taken.add(pos[i]);
                        }
                        tree.add(pos[i], -1);
                }
                out.println(res);
        }
}

class BinaryIndexTree {
        int[] val;

        BinaryIndexTree(int size) {
                val = new int[size];
        }

        int get(int at) {
                int res = 0;
                for (; at >= 0; at = (at & (at + 1)) - 1)
                        res += val[at];
                return res;
        }

        int get(int low, int high) {
                return get(high) - get(low - 1);
        }

        void add(int at, int by) {
                for (; at < val.length; at = (at | (at + 1)))
                        val[at] += by;
        }
}

class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream)  {
                reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextToken() {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                        String line;
                        try {
                                line = reader.readLine();
                        } catch (IOException e) {
                                return null;
                        }
                        tokenizer = new StringTokenizer(line);
                }
                return tokenizer.nextToken();
        }

        public int nextInt() {
                return Integer.parseInt(nextToken());
        }

        }