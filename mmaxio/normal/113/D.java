import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    ArrayList<Integer>[] g;

    int[][] f;
    
    final double EPS = 1e-7;
    
    boolean eq0(double x) {
        return Math.abs(x) < EPS;
    }
    
    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();

        f = new int[n][n];
        int cnt = 0;

//      for (int i = 0; i < n; i++)
//          for (int j = 0; j <= i; j++)
//              f[j][i] = f[i][j] = cnt++;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                f[i][j] = cnt++;

        int init = f[nextInt() - 1][nextInt() - 1];

        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>();
            g[i].add(i);
        }

        for (int i = 0; i < m; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            g[v1].add(v2);
            g[v2].add(v1);
        }

        double[] p = new double[n];
        for (int i = 0; i < n; i++)
            p[i] = nextDouble();

        double[][] matr = new double[cnt][cnt];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                int cur = f[i][j];
                for (int toI : g[i])
                    for (int toJ : g[j]) {
                        double prob = 1;
                        if (toI == i)
                            prob *= p[i];
                        else
                            prob *= (1 - p[i]) / (g[i].size() - 1);
                        if (toJ == j)
                            prob *= p[j];
                        else
                            prob *= (1 - p[j]) / (g[j].size() - 1);
                        matr[cur][f[toI][toJ]] += prob;
                    }

            }
        
//      for (int i = 0; i < cnt; i++)
//          System.err.println(Arrays.toString(matr[i]));
        
        for (int i = 0; i < cnt; i++)
            for (int j = 0; j < cnt; j++)
                matr[i][j] = (i == j ? 1 : 0) - matr[i][j];
        
//      for (int i = 0; i < cnt; i++)
//          System.err.println(Arrays.toString(matr[i]));
        
        double[][] inv = new double[cnt][cnt];
        for (int i = 0; i < cnt; i++)
            inv[i][i] = 1;
        
        for (int j = 0; j < cnt; j++) {
            int row = -1;
            for (int i = j; i < cnt; i++)
                if (!eq0(matr[i][j])) {
                    row = i;
                    break;
                }
            if (row == -1)
                throw new AssertionError("degnerate matrix, can't inverse");
            
            double[] tmp = matr[j];
            matr[j] = matr[row];
            matr[row] = tmp;
            tmp = inv[j];
            inv[j] = inv[row];
            inv[row] = tmp;
            
            for (int i = 0; i < cnt; i++)
                if (i != row) {
                    double coef = matr[i][j] / matr[row][j];
                    for (int k = 0; k < cnt; k++) {
                        matr[i][k] -= matr[row][k] * coef;
                        inv[i][k] -= inv[row][k] * coef;
                    }
                }
        }
        
        for (int i = 0; i < cnt; i++)
            for (int j = 0; j < cnt; j++)
                inv[i][j] /= matr[i][i];
        
        for (int i = 0; i < n; i++)
            out.printf(Locale.US, "%.9f ", inv[init][f[i][i]]);

    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D().inp();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }

    String nextString() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken("\n");
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

}