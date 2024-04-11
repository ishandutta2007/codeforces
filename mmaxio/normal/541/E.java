import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * Created by aksenov on 17.04.2015.
 */
public class E2 {
    FastScanner in;
    PrintWriter out;

    int[] color;
    ArrayList<Integer>[] e;

    public void color(int v, int c) {
        if (color[v] != 0)
            return;
        color[v] = c;
        for (int u : e[v]) {
            color(u, c);
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();

        e = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            e[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            e[a].add(b);
            e[b].add(a);
        }

        int nc = 0;
        color = new int[n];
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                color(i, ++nc);
            }
        }

        int[] ans = new int[nc];
        for (int i = 0; i < n; i++) {
            int[] d = new int[n];
            Queue<Integer> q = new ArrayDeque<Integer>();
            q.add(i);
            boolean bad = false;
            int max = 0;
            d[i] = 1;
            while (!q.isEmpty()) {
                int u = q.poll();
                max = Math.max(max, d[u]);
                for (int v : e[u]) {
                    if (d[v] == 0) {
                        d[v] = d[u] + 1;
                        q.add(v);
                    }
                    if (d[v] == d[u]) {
                        bad = true;
                        break;
                    }
                }
                if (bad) {
                    out.println(-1);
                    return;
                }
            }
            ans[color[i] - 1] = Math.max(ans[color[i] - 1], max - 1);
        }

        int res = 0;
        for (int i = 0; i < nc; i++) {
            res += ans[i];
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
        new E2().run();
    }
}