import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
        ArrayList<Integer>[] g;
        int[] want;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                int k = in.nextInt();
                want = ArrayUtils.readIntArray(in, n);
                ArrayList<Integer>[] at = new ArrayList[n];
                g = new ArrayList[n];
                ArrayList<Integer> left = new ArrayList<>();
                ArrayList<Integer> right = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                        g[i] = new ArrayList<>();
                        at[i] = new ArrayList<>();
                }
                int[] ptr = new int[n];
                for (int i = 0; i < n; i++)
                        at[want[i]].add(i);
                if (at[0].size() != 1) {
                        out.print(-1);
                        return;
                }
                for (int i = 1; i < n; i++)
                        for (int v : at[i]) {
                                if (at[i - 1].size() == 0) {
                                        out.print(-1);
                                        return;
                                }
                                int a = at[i - 1].get(ptr[i - 1]);
                                int b = v;
                                ptr[i - 1]++;
                                ptr[i - 1] %= at[i - 1].size();
                                g[a].add(b);
                                g[b].add(a);
                                left.add(a);
                                right.add(b);
                        }
                for (int i = 0; i < n; i++)
                        if (g[i].size() > k) {
                                out.print(-1);
                                return;
                        }
                out.println(n - 1);
                for (int i = 0; i < left.size(); i++)
                        out.println((left.get(i) + 1) + " " + (right.get(i) + 1));
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

class ArrayUtils {

        public static int[] readIntArray(FastScanner in, int count) {
                int[] array = new int[count];
                for (int i = 0; i < count; i++)
                        array[i] = in.nextInt();
                return array;
        }


        }