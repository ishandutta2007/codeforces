import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by Aksenov239 on 08.03.2015.
 */
public class B {
    public static void main(String[] args) {
        new B().run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public class Query {
        int q;
        int[] param;

        public Query(int q, int... p) {
            this.q = q;
            this.param = p;
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int q = nextInt();

        int[][] a = new int[n][m];
        Query[] queries = new Query[q];
        for (int i = 0; i < q; i++) {
            int t = nextInt();
            if (t < 3) {
                queries[i] = new Query(t, nextInt() - 1);
            } else {
                queries[i] = new Query(t, nextInt() - 1, nextInt() - 1, nextInt());
            }
        }

        for (int i = q - 1; i >= 0; i--) {
            if (queries[i].q == 1) {
                int r = queries[i].param[0];
                int last = a[r][m - 1];
                for (int j = m - 2; j >= 0; j--) {
                    a[r][j + 1] = a[r][j];
                }
                a[r][0] = last;
            } else if (queries[i].q == 2) {
                int c = queries[i].param[0];
                int last = a[n - 1][c];
                for (int j = n - 2; j >= 0; j--) {
                    a[j + 1][c] = a[j][c];
                }
                a[0][c] = last;
            } else {
                int r = queries[i].param[0];
                int c = queries[i].param[1];
                a[r][c] = queries[i].param[2];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(a[i][j] + " ");
            }
            out.println();
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}