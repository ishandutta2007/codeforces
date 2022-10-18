import java.io.*;
import java.util.*;

public class TREES_test {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int MOD = 1000000007;

    List<Integer>[] g;
    int[] depth;
    int[] from, to;
    int[] order;
    int time = 0;

    void dfs(int v, int curD) {
        depth[v] = curD;
        order[time] = v;
        from[v] = time++;
        for (int i = 0; i < g[v].size(); i++) {
            int child = g[v].get(i);
            dfs(child, curD + 1);
        }
        to[v] = time;
    }

    class Node {
        int l, r;
        int sumDepth;
        Node left, right;
        int add, mult;
        int sum;

        public Node(int l, int r) {
            this.l = l;
            this.r = r;
            if (r - l > 1) {
                int mid = (l + r) >> 1;
                left = new Node(l, mid);
                right = new Node(mid, r);
                sumDepth = (left.sumDepth + right.sumDepth) % MOD;
            } else {
                sumDepth = (MOD - depth[order[l]]) % MOD;
            }
        }

        int getSum() {
            int ret = (sum + (int) ((long) add * (r - l) % MOD)) % MOD;
            ret = (ret + (int) ((long) mult * sumDepth % MOD)) % MOD;
            return ret;
        }

        void update(int ql, int qr, int deltaAdd, int deltaMult) {
            // System.err.println(ql + " " + qr + " " + deltaAdd + " " +
            // deltaMult);
            if (ql >= r || l >= qr) {
                return;
            }
            if (ql <= l && r <= qr) {
                add = (add + deltaAdd) % MOD;
                mult = (mult + deltaMult) % MOD;
                return;
            }
            left.update(ql, qr, deltaAdd, deltaMult);
            right.update(ql, qr, deltaAdd, deltaMult);
            sum = (left.getSum() + right.getSum()) % MOD;
        }

        int get(int ql, int qr) {
            if (ql >= r || l >= qr) {
                return 0;
            }
            if (ql <= l && r <= qr) {
                return getSum();
            }
            left.add = (left.add + add) % MOD;
            left.mult = (left.mult + mult) % MOD;
            right.add = (right.add + add) % MOD;
            right.mult = (right.mult + mult) % MOD;
            add = 0;
            mult = 0;
            int ret = (left.get(ql, qr) + right.get(ql, qr)) % MOD;
            sum = (left.getSum() + right.getSum()) % MOD;
            return ret;
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>(0);
        }

        for (int i = 0; i < n - 1; i++) {
            int v = nextInt() - 1;
            g[v].add(i + 1);
        }

        depth = new int[n];
        from = new int[n];
        to = new int[n];
        order = new int[n];
        dfs(0, 0);

        Node root = new Node(0, n);

        int qq = nextInt();
        while (qq-- > 0) {
            int type = nextInt();
            int v = nextInt() - 1;
            if (type == 1) {
                int x = nextInt();
                int k = nextInt();

                int val = (int) (x + (long) depth[v] * k % MOD) % MOD;
                root.update(from[v], to[v], val, k);
            } else {
                // System.err.println(Arrays.toString(res));
                int outp = root.get(from[v], from[v] + 1);
                out.println(outp);
            }
        }
    }

    TREES_test() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new TREES_test();
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