import java.io.*;
import java.util.*;

public class F {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int[] par;
    int[] dep;

    int[][] up;

    int getUp(int v, int dist) {
        for (int i = 0; dist > 0; i++) {
            if ((dist & 1) == 1) {
                v = up[v][i];
            }
            dist >>= 1;
        }
        return v;
    }

    int dist(int v1, int v2) {
        int sum = dep[v1] + dep[v2];
            if (dep[v1] > dep[v2]) {
                v1 = getUp(v1, dep[v1] - dep[v2]);
            } else if (dep[v2] > dep[v1]) {
                v2 = getUp(v2, dep[v2] - dep[v1]);
            }

        if (v1 == v2) {
            return sum - 2 * dep[v1];
        }
        for (int j = up[v1].length - 1; j >= 0; j--) {
            if (up[v1].length > j) {
                int to1 = up[v1][j];
                int to2 = up[v2][j];
                if (to1 != to2) {
                    v1 = to1;
                    v2 = to2;
                }
            }
        }
        v1 = par[v1];
        return sum - 2 * dep[v1];
    }

    void solve() throws IOException {
        int q = nextInt();
        int n = 2 * q + 4;

        dep = new int[n];
        par = new int[n];
        dep[1] = dep[2] = dep[3] = 1;

        for (int i = 0; i < q; i++) {
            int v0 = nextInt() - 1;
            int v1 = 2 * i + 4;
            int v2 = 2 * i + 5;

            dep[v1] = dep[v2] = dep[v0] + 1;
            par[v1] = par[v2] = v0;
        }

        up = new int[n][];
        up[0] = new int[] {};
        up[1] = up[2] = up[3] = new int[] { 0 };

        for (int i = 4; i < n; i++) {
            up[i] = new int[32 - Integer.numberOfLeadingZeros(dep[i])];
            up[i][0] = par[i];
            for (int j = 1; j < up[i].length; j++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
            // System.err.println(i + " " + Arrays.toString(up[i]));
        }

        int diam = 2;
        int v0 = 1;
        int v1 = 2;

        for (int i = 0; i < q; i++) {
            int v = par[2 * i + 4];

            if (dist(v, v0) == diam) {
                diam++;
                v1 = 2 * i + 4;
            } else if (dist(v, v1) == diam) {
                diam++;
                v0 = 2 * i + 4;
            }
            out.println(diam);
            // System.err.println(v0 + " " + v1);
        }
    }

    F() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new F();
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