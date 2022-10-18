import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    ArrayList<Integer>[] g;

    int[] path;
    int[] depth;

    int[][] fen;

    void add(int[] f, int i, int x) {
        while (i < f.length) {
            f[i] += x;
            i |= i + 1;
        }
    }

    int get(int[] f, int i) {
        int res = 0;
        while (i >= 0) {
            res += f[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();
        int[] v1 = new int[n - 1];
        int[] v2 = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            v1[i] = nextInt() - 1;
            v2[i] = nextInt() - 1;
            g[v1[i]].add(v2[i]);
            g[v2[i]].add(v1[i]);
        }

        int root = -1;
        for (int i = 0; i < n; i++)
            if (g[i].size() > 2) {
                root = i;
                break;
            }

        if (root == -1) {
            for (int i = 0; i < n; i++)
                if (g[i].size() == 1) {
                    root = i;
                    break;
                }
        }
        assert root != -1;
        depth = new int[n];
        path = new int[n];
        fen = new int[g[root].size()][];
        path[root] = -1;
        depth[root] = -1;

        for (int i = 0; i < g[root].size(); i++) {
            int v = g[root].get(i);
            int curDepth = 0;
            int prev = root;
            boolean isEnd = false;
            while (!isEnd) {
                path[v] = i;
                depth[v] = curDepth;
                isEnd = true;
                for (int to : g[v])
                    if (to != prev) {
                        prev = v;
                        v = to;
                        curDepth++;
                        isEnd = false;
                        break;
                    }
            }
            fen[i] = new int[curDepth + 1];
        }

        int q = nextInt();
        while (q-- > 0) {
            int type = nextInt();
            switch (type) {
            case 1:
                int id = nextInt() - 1;
                int v = depth[v1[id]] > depth[v2[id]] ? v1[id] : v2[id];
                add(fen[path[v]], depth[v], -1);
                break;
            case 2:
                id = nextInt() - 1;
                v = depth[v1[id]] > depth[v2[id]] ? v1[id] : v2[id];
                add(fen[path[v]], depth[v], 1);
                break;
            case 3:
                int a = nextInt() - 1;
                int b = nextInt() - 1;
                if (a == b) {
                    out.println(0);
                    break;
                }
                if (depth[a] > depth[b]) {
                    int tmp = a;
                    a = b;
                    b = tmp;
                }
                if (a == root) {
                    if (get(fen[path[b]], depth[b]) == 0)
                        out.println(depth[b] + 1);
                    else
                        out.println(-1);
                } else if (path[a] != path[b]) {
                    if (get(fen[path[a]], depth[a])
                            + get(fen[path[b]], depth[b]) == 0)
                        out.println(depth[a] + 1 + depth[b] + 1);
                    else
                        out.println(-1);
                } else {
                    if (get(fen[path[a]], depth[b])
                            - get(fen[path[a]], depth[a]) == 0)
                        out.println(depth[b] - depth[a]);
                    else
                        out.println(-1);
                }
            }
        }

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