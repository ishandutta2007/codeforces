import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Node {
        long val;
        long add;

        public Node(long val, long add) {
            this.val = val;
            this.add = add;
        }
    }

    // final String TASKNAME = "";
    final int DOWN = 262144;
    final long INF = 1000000000000000L;

    Node tree[] = new Node[2 * DOWN - 1];

    void upd(int v, int lv, int rv, int lq, int rq, int add) {
        if (lv > rq || rv < lq)
            return;
        if (lv >= lq && rv <= rq) {
            tree[v].add += add;
            return;
        }

        if (tree[v].add != 0) {
            tree[2 * v + 1].add += tree[v].add;
            tree[2 * v + 2].add += tree[v].add;
            tree[v].add = 0;
        }

        upd(2 * v + 1, lv, (lv + rv) >> 1, lq, rq, add);
        upd(2 * v + 2, ((lv + rv) >> 1) + 1, rv, lq, rq, add);

        tree[v].val = Math.min(tree[2 * v + 1].val + tree[2 * v + 1].add,
                tree[2 * v + 2].val + tree[2 * v + 2].add);

    }

    long get(int v, int lv, int rv, int lq, int rq) {
        if (lv > rq || rv < lq)
            return INF;
        if (lv >= lq && rv <= rq)
            return tree[v].add + tree[v].val;

        if (tree[v].add != 0) {
            tree[2 * v + 1].add += tree[v].add;
            tree[2 * v + 2].add += tree[v].add;
            tree[v].add = 0;
        }

        long res = Math.min(get(2 * v + 1, lv, (lv + rv) >> 1, lq, rq),
                get(2 * v + 2, ((lv + rv) >> 1) + 1, rv, lq, rq));

        tree[v].val = Math.min(tree[2 * v + 1].val + tree[2 * v + 1].add,
                tree[2 * v + 2].val + tree[2 * v + 2].add);

        return res;
    }

    void solve() throws IOException {
        int n = nextInt();

        for (int i = DOWN - 1; i < 2 * DOWN - 1; i++)
            tree[i] = new Node(INF, 0);
        for (int i = 0; i < n; i++)
            tree[i + DOWN - 1].val = nextLong();
        for (int i = DOWN - 2; i >= 0; i--) {
            tree[i] = new Node(Math.min(tree[2 * i + 1].val,
                    tree[2 * i + 2].val), 0);
        }
        int m = nextInt();
        for (int i = 0; i < m; i++) {
            String[] s = nextString().split(" ");
            //Scanner tmp = new Scanner(s);
            //System.err.println(s);
            int l = Integer.parseInt(s[0]);
            int r = Integer.parseInt(s[1]);
            if (s.length == 3) {
                int del = Integer.parseInt(s[2]);
                if (l <= r) {
                    upd(0, 0, DOWN - 1, l, r, del);
                } else {
                    upd(0, 0, DOWN - 1, 0, r, del);
                    upd(0, 0, DOWN - 1, l, n - 1, del);
                }
            } else {
                if (l <= r) {
                    out.println(get(0, 0, DOWN - 1, l, r));
                } else {
                    out.println(Math.min(get(0, 0, DOWN - 1, 0, r),
                            get(0, 0, DOWN - 1, l, n - 1)));
                }
            }
        }
    }

    void inp() throws IOException {
        // br = new BufferedReader(new FileReader(TASKNAME + ".in"));
        // out = new PrintWriter(TASKNAME + ".out");
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().inp();
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