import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    List<Integer>[] g;

    static class Node {
        static int lastID = 0;

        Node child, sibling;
        char parSymb;

        int id;

        public Node() {
            id = lastID++;
        }

        public Node(Node sibling, char parSymb) {
            this();
            this.sibling = sibling;
            this.parSymb = parSymb;
        }

        Node go(char c) {
            for (Node to = child; to != null; to = to.sibling) {
                if (to.parSymb == c) {
                    return to;
                }
            }
            Node newNode = new Node(child, c);
            child = newNode;
            return newNode;
        }

    }

    int[] vId;
    char[] s;

    int[] low, high;
    int time = 0;

    int[] order;

    void dfs1(int v, int p, Node trieV) {
        order[time] = v;
        low[v] = time++;
        trieV = trieV.go(s[v]);
        vId[v] = trieV.id;
        for (int to : g[v]) {
            if (to != p) {
                dfs1(to, v, trieV);
            }
        }
        high[v] = time;
    }

    void add(int[] f, int pos, int delta) {
        for (int i = pos; i < f.length; i |= i + 1) {
            f[i] += delta;
        }
    }

    int get(int[] f, int pos) {
        int ret = 0;
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
            ret += f[i];
        }
        return ret;
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] delta = new int[n];
        for (int i = 0; i < n; i++) {
            delta[i] = nextInt();
        }
        s = nextToken().toCharArray();

        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>(2);
        }

        for (int i = 0; i < n - 1; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            g[v1].add(v2);
            g[v2].add(v1);
        }

        vId = new int[n];

        low = new int[n];
        high = new int[n];
        order = new int[n];

        dfs1(0, -1, new Node());

        // System.err.println(Arrays.toString(vId));

        int[] lastOcc = new int[Node.lastID];
        Arrays.fill(lastOcc, -1);

        int[] prevOcc = new int[n]; // from VERTEX NUMBER, not ORDERING

        for (int i = 0; i < n; i++) {
            int v = order[i];
            prevOcc[v] = lastOcc[vId[v]];
            lastOcc[vId[v]] = i;
        }

        Integer[] putQueries = new Integer[n];
        for (int i = 0; i < n; i++) {
            putQueries[i] = i;
        }

        Arrays.sort(putQueries, new Comparator<Integer>() {

            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(prevOcc[o1], prevOcc[o2]);
            }

        });

        // System.err.println(Arrays.toString(low));
        // System.err.println(Arrays.toString(high));
//      System.err.println(Arrays.toString(order));
//      System.err.println(Arrays.toString(prevOcc));

        int[] diffSub = new int[n]; // from VERTEX NUMBER, not ORDERING

        int[] fen = new int[n];
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && prevOcc[putQueries[j]] < low[order[i]]) {
                add(fen, low[putQueries[j]], 1);
                j++;
            }
            diffSub[order[i]] = get(fen, high[order[i]] - 1) - get(fen, i - 1);
        }

        int maxSum = -1;
        for (int i = 0; i < n; i++) {
            maxSum = Math.max(maxSum, diffSub[i] + delta[i]);
        }

        int cntMaxSum = 0;
        for (int i = 0; i < n; i++) {
            if (diffSub[i] + delta[i] == maxSum) {
                cntMaxSum++;
            }
        }

        out.println(maxSum);
        out.println(cntMaxSum);
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