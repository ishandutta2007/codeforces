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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
        int[][] a;
        int[][][] f;
        int[] diag;
        int n;
        int cur = 0;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                n = in.nextInt();
                a = new int[n][n];
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++)
                                a[i][j] = in.nextInt();
                f = new int[n][2][2];
                diag = new int[n];
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++)
                                if (i != j)
                                        f[i][a[i][j]][a[j][i]]++;
                                else
                                        diag[i] = a[i][j];
                for (int i = 0; i < n; i++) {
                        cur += f[i][1][1];
                        if (diag[i] == 1)
                                cur++;
                }
                //out.println(cur);
                cur %= 2;
                int q = in.nextInt();
                for (int i = 0; i < q; i++) {
                        int t = in.nextInt();
                        if (t == 1) {
                                int r = in.nextInt();
                                r--;
                                flipRow(r);
                        } else if (t == 2) {
                                int r = in.nextInt();
                                r--;
                                flipCol(r);
                        } else {
                                out.print(cur);
                        }
                }
        }

        void flipRow(int i) {
                /*cur -= f[i][1][1];
                temp[0][0] = f[i][1][0];
                temp[0][1] = f[i][1][1];
                temp[1][0] = f[i][0][0];
                temp[1][1] = f[i][0][1];
                for (int x = 0; x < 2; x++)
                        for (int y = 0; y < 2; y++)
                                f[i][x][y] = temp[x][y];
                cur += f[i][1][1];
                cur %= 2;
                if (cur == -1)
                        cur = 1;  */
                cur ^= 1;
        }

        void flipCol(int i) {
                /*cur -= f[i][1][1];
                temp[0][0] = f[i][0][1];
                temp[0][1] = f[i][0][0];
                temp[1][0] = f[i][1][1];
                temp[1][1] = f[i][1][0];
                for (int x = 0; x < 2; x++)
                        for (int y = 0; y < 2; y++)
                                f[i][x][y] = temp[x][y];
                cur += f[i][1][1];
                cur %= 2;
                if (cur == -1)
                        cur = 1;  */
                cur ^= 1;
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