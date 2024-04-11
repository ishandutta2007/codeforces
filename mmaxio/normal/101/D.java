import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Edge {
        int to, cost;

        public Edge(int to, int cost) {
            super();
            this.to = to;
            this.cost = cost;
        }
    }

    ArrayList<Edge>[] g;
    long[] ans;
    int[] size;
    int[] traverse;

    class SubTree implements Comparable<SubTree> {
        int cost, size;

        public SubTree(int cost, int size) {
            super();
            this.cost = cost;
            this.size = size;
        }

        @Override
        public int compareTo(SubTree o) {
            long val1 = (long) cost * o.size;
            long val2 = (long) o.cost * size;
            if (val1 == val2)
                return 0;
            return val1 < val2 ? -1 : 1;
        }
    }

    void dfs(int v, int pr) {
        size[v] = 1;
        ans[v] = 0;
        traverse[v] = 0;
        int cnt = 0;
        for (Edge e : g[v])
            if (e.to != pr) {
                dfs(e.to, v);
                cnt++;
                size[v] += size[e.to];
                ans[v] += ans[e.to] + (long) e.cost * size[e.to];
                traverse[v] += traverse[e.to] + 2 * e.cost;
            }

        SubTree[] arr = new SubTree[cnt];
        for (Edge e : g[v])
            if (e.to != pr) {
                arr[--cnt] = new SubTree(2 * e.cost + traverse[e.to],
                        size[e.to]);
            }

        Arrays.sort(arr);

        if (arr.length > 1) {

            long totCost = arr[0].cost;
            for (int i = 1; i < arr.length; i++) {
                ans[v] += totCost * arr[i].size;
                totCost += arr[i].cost;
            }
        }

    }

    void solve() throws IOException {
        int n = nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Edge>();
        for (int i = 0; i < n - 1; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            int cost = nextInt();
            g[v1].add(new Edge(v2, cost));
            g[v2].add(new Edge(v1, cost));
        }

        ans = new long[n];
        traverse = new int[n];
        size = new int[n];
        dfs(0, -1);

        out.printf("%.9f\n", 1.0 * ans[0] / (n - 1));
    }

    void inp() throws IOException {
        Locale.setDefault(Locale.US);
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