import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by aksenov on 17.04.2015.
 */
public class C2 {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int n = in.nextInt();
        int[] p = new int[n];

        for (int i = 0; i < p.length; i++) {
            p[i] = in.nextInt() - 1;
        }

        BigInteger ans = BigInteger.ONE;

        int[] color = new int[n];
        int nc = 0;
        int[] cl = new int[n];
        boolean[] failed = new boolean[n];
        int ml = 0;
        for (int i = 0; i < n; i++) {
            if (color[i] != 0)
                continue;
            boolean[] was = new boolean[n];
            int v = i;
            while (!was[v]) {
                was[v] = true;
                v = p[v];
            }

            if (v == i) {
                int u = p[v];
                color[v] = nc + 1;
                cl[nc]++;
                while (u != v) {
                    cl[nc]++;
                    color[u] = nc + 1;
                    u = p[u];
                }

                nc++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (color[i] != 0)
                continue;
            int u = i;
            int l = 0;
            while (color[u] == 0) {
                l++;
                u = p[u];
            }
            ml = Math.max(ml, l);
            failed[color[u] - 1] = true;
        }

        cl = Arrays.copyOf(cl, nc);
        failed = Arrays.copyOf(failed, nc);
        for (int i = 0; i < nc; i++) {
            int c = cl[i];
            BigInteger clen = BigInteger.valueOf(c);
            BigInteger gcd = clen.gcd(ans);
            ans = ans.multiply(clen).divide(gcd);
        }

        BigInteger res = ans;
        while (res.compareTo(BigInteger.valueOf(ml)) < 0) {
            res = res.add(ans);
        }

        out.println(res);
    }

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new C2().run();
    }
}