import java.io.InputStreamReader;
import java.io.IOException;
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
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int zeros = in.nextInt();
                int ones = in.nextInt();
                int[] res = new int[zeros + ones];
                int have0 = zeros;
                int have1 = ones;
                boolean was0 = false;
                for (int pos = 0; pos < zeros + ones; pos++) {
                        if (was0) {
                                if (have1 == 0) {
                                        out.print(-1);
                                        return;
                                }
                                was0 = false;
                                have1--;
                                res[pos] = 1;
                        }  else {
                                if (have0 == 0) {
                                        was0 = false;
                                        have1--;
                                        res[pos] = 1;
                                        continue;
                                }
                                if (have1 == 0) {
                                        was0 = true;
                                        have0--;
                                        res[pos] = 0;
                                        continue;
                                }
                                int need0 = Math.max(0, (have1 - 1) / 2);
                                if (need0 > have0 - 1) {
                                        have1--;
                                        was0 = false;
                                        res[pos] = 1;
                                } else {
                                        have0--;
                                        was0 = true;
                                        res[pos] = 0; 
                                }
                        }
                }
                for (int i = 2; i < res.length; i++)
                        if (res[i - 2] == 1 && res[i - 1] == 1 && res[i] == 1) {
                                out.print(-1);
                                return;
                        }
                for (int i = 1; i < res.length; i++)
                        if (res[i - 1] == 0 && res[i] == 0) {
                                out.print(-1);
                                return;
                        }
                for (int val : res)
                        out.print(val);
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