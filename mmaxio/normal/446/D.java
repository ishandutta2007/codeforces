import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        boolean[] stop = new boolean[n];
        int mid = 0;
        for (int i = 0; i < n; i++) {
            stop[i] = nextInt() == 1;
            if (!stop[i]) {
                mid++;
            }
        }

        int[] newN = new int[n];
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (!stop[i]) {
                newN[i] = ptr++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (stop[i]) {
                newN[i] = ptr++;
            }
        }

        int[] deg = new int[n];
        int[][] g = new int[n][n];
        for (int i = 0; i < m; i++) {
            int v1 = newN[nextInt() - 1];
            int v2 = newN[nextInt() - 1];
            deg[v1]++;
            deg[v2]++;
            g[v1][v2]++;
            g[v2][v1]++;
        }

        double[][] a = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < mid) {
                    a[i][j] = 1.0 * g[i][j] / deg[i];
                } else {
                    a[i][j] = (i == j) ? 1 : 0;
                }
            }
        }

        double[][] Q = new double[mid][mid];
        for (int i = 0; i < mid; i++) {
            Q[i] = Arrays.copyOf(a[i], mid);
            for (int j = 0; j < mid; j++) {
                Q[i][j] = -Q[i][j];
            }
            Q[i][i] += 1;
        }

        double[][] N = inverse(Q);

        double[][] R = new double[mid][n - mid];
        for (int i = 0; i < mid; i++) {
            R[i] = Arrays.copyOfRange(a[i], mid, n);
        }

        double[][] B = multiply(N, R);

        double[] init = B[0];
        double[][] tr = new double[n - mid][n - mid];
        for (int i = mid; i < n; i++) {
            double[] trans = new double[mid];
            for (int j = 0; j < n; j++) {
                if (j < mid) {
                    trans[j] = 1.0 * g[i][j] / deg[i];
                } else {
                    tr[i - mid][j - mid] = 1.0 * g[i][j] / deg[i];
                }
            }
            for (int i1 = 0; i1 < mid; i1++)
                for (int j1 = mid; j1 < n; j1++) {
                    tr[i - mid][j1 - mid] += trans[i1] * B[i1][j1 - mid];
                }
        }

        double[][] A = pow(tr, k - 2);
        double ans = 0;
        for (int i = 0; i < n - mid; i++) {
            ans += init[i] * A[i][n - mid - 1];
        }
        out.println(ans);
    }
    
    double[][] pow(double[][] a, int k) {
        int n = a.length;
        double[][] res = new double[n][n];
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        while (k > 0) {
            if ((k & 1) == 1) {
                res = multiply(res, a);
            }
            a = multiply(a, a);
            k >>= 1;
        }
        return res;
    }

    double[][] multiply(double[][] a, double[][] b) {
        int n = a.length;
        int m = a[0].length;
        int k = b[0].length;
        double[][] res = new double[n][k];
        for (int i = 0; i < n; i++) {
            double[] A = a[i];
            for (int j = 0; j < k; j++) {
                double sum = 0;
                for (int jj = 0; jj < m; jj++) {
                    sum += A[jj] * b[jj][j];
                }
                res[i][j] = sum;
            }
        }
        return res;
    }

    static final double EPS = 1e-8;

    double[][] inverse(double[][] a) {
        int n = a.length;
        double[][] b = new double[n][n];
        for (int i = 0; i < n; i++) {
            b[i][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            double maxVal = 0;
            int row = -1;
            for (int j = i; j < n; j++) {
                if (Math.abs(a[j][i]) > maxVal) {
                    maxVal = Math.abs(a[j][i]);
                    row = j;
                }
            }
            if (maxVal < EPS) {
                throw new AssertionError();
            }
            double[] tmp = a[i];
            a[i] = a[row];
            a[row] = tmp;
            tmp = b[i];
            b[i] = b[row];
            b[row] = tmp;
            // DON'T USE ROW
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                double coef = a[j][i] / a[i][i];
                a[j][i] = 0;
                for (int k = i + 1; k < n; k++) {
                    a[j][k] -= a[i][k] * coef;
                }
                for (int k = 0; k < n; k++) {
                    b[j][k] -= b[i][k] * coef;
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                b[i][j] /= a[i][i];
            }
        return b;
    }

    D() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return null;
            }
        }
        return st.nextToken();
    }

    String nextString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            eof = true;
            return null;
        }
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