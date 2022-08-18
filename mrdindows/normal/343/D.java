
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;

public class WaterTree {

    static StreamTokenizer in;
    static PrintWriter out;

    static int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }
    static final int MAXN = 500005;
    static ArrayList<ArrayList<Integer>> G;
    static int timer;
    static int[] tin = new int[MAXN];
    static int[] tout = new int[MAXN];
    static int[] parent = new int[MAXN];

    static void dfs(int u, int p) {
        parent[u] = p;
        tin[u] = timer;
        for (int v : G.get(u)) {
            if (v != p) {
                dfs(v, u);
            }
        }
        tout[u] = timer++;
    }
    static boolean[] T = new boolean[8 * MAXN];
    static boolean[] promise = new boolean[8 * MAXN];

    static void build(int v, int tl, int tr) {
        if (tl < tr) {
            int tm = (tl + tr) >> 1;
            int dv = v + v;
            build(dv, tl, tm);
            build(dv + 1, tm + 1, tr);
        }
        T[v] = true;
    }

    static void push(int v) {
        if (promise[v]) {
            promise[v] = false;
            int dv = v+v;
            promise[dv] = promise[dv + 1] = true;
            T[dv] = T[dv + 1] = false;
        }
    }

    static boolean get(int l, int r, int v, int tl, int tr) {
      /*  if (l > r) {
            return false;
        }*/
        push(v);
        if (tl == l && tr == r) {
            return T[v];
        } else {
            int tm = (tl + tr) >> 1;
            int dv = v+v;
            if (r<=tm)
                return get(l, r, dv, tl, tm);
            else if (l>tm)
                return get(l, r, dv + 1, tm + 1, tr);
            else return get(l, tm, dv, tl, tm) || get(tm + 1, r, dv + 1, tm + 1, tr);
        }
    }

    static void update(int p, int v, int tl, int tr) {
        push(v);
        T[v] = true;
        if (tl < tr) {
            int tm = (tl + tr) >> 1;
            
            if (p <= tm) {
                update(p, v + v, tl, tm);
            } else {
                update(p, v + v + 1, tm + 1, tr);
            }
        }
    }

    static void color(int l, int r, int v, int tl, int tr) {
        if (promise[v]) {
            return;
        }
        if (l == tl && r == tr) {
            promise[v] = true;
            T[v] = false;
        } else {
            int tm = (tl + tr) >> 1;
            int dv = v + v;
            if (r<=tm)
                color(l, r, dv, tl, tm);
            else if (l>tm)
                color(l, r, dv + 1, tm + 1, tr);
            else
            {
                color(l, tm, dv, tl, tm);
                color(tm + 1, r, dv + 1, tm + 1, tr);
            }
            T[v] = T[dv] || T[dv + 1];
        }
    }

    public static void main(String[] args) throws IOException {
        in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        out = new PrintWriter(System.out);

        int n = nextInt();
        G = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < n; i++) {
            G.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < n - 1; i++) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            G.get(a).add(b);
            G.get(b).add(a);
        }

        timer = 0;
        dfs(0, 0);
        build(1, 0, n - 1);

        int q = nextInt();
        for (int i = 0; i < q; i++) {
            int c = nextInt();
            int v = nextInt() - 1;
            if (c == 1) {
                boolean up = get(tin[v], tout[v], 1, 0, n - 1);
                color(tin[v], tout[v], 1, 0, n - 1);
                if (up && v > 0) {
                    update(tout[parent[v]], 1, 0, n - 1);
                }
            } else if (c == 2) {
                update(tout[v], 1, 0, n - 1);
            } else {
                out.println(get(tin[v], tout[v], 1, 0, n - 1) ? 0 : 1);
            }
        }
        out.flush();
    }
}