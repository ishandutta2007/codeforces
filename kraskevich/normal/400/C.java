import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
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
        int n, m;

        void rot1(int[] c) {
                int x = c[0];
                int y = c[1];
                //System.out.println(x + " " + y + " " + n + " " + m);
                c[0] = y;
                c[1] = n - 1 - x;
        }

        void rot2(int[] c) {
                c[1] = m - 1 - c[1];
        }

        void rot3(int[] c) {
                int x = c[0];
                int y = c[1];
                c[0] = m - 1 - y;
                c[1] = x;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int x, y, z, cnt;
                n = in.nextInt();
                m = in.nextInt();
                x = in.nextInt();
                y = in.nextInt();
                z = in.nextInt();
                cnt = in.nextInt();
                int[][] res = new int[cnt][2];
                for (int i = 0; i < cnt; i++) {
                        res[i][0] = in.nextInt();
                        res[i][1] = in.nextInt();
                        res[i][0]--;
                        res[i][1]--;
                }
                for (int rep = 0; rep < x % 4; rep++) {
                        for (int i = 0; i < cnt; i++)
                                rot1(res[i]);
                        int t = n;
                        n = m;
                        m = t;
                }
                for (int rep = 0; rep < y % 2; rep++)
                        for (int i = 0; i < cnt; i++)
                                rot2(res[i]);
                for (int rep = 0; rep < z % 4; rep++) {
                        for (int i = 0; i < cnt; i++)
                                rot3(res[i]);
                        int t = n;
                        n = m;
                        m = t;
                }
                for (int i = 0; i < cnt; i++) {
                        res[i][0]++;
                        res[i][1]++;
                        out.println(res[i][0] + " " + res[i][1]);
                }
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