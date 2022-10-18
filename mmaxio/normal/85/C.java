import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Node {
        int key;
        int l, r;

        int minKey, maxKey;

        long ifComeKeys;
        int ifComeNodes;

        public Node(int key) {
            this.key = key;
            this.l = -1;
            this.r = -1;
        }
    }

    Node[] tree;

    void calcMinMax(Node v) {
        if (v.l != -1) {
            calcMinMax(tree[v.l]);
            calcMinMax(tree[v.r]);
            v.minKey = tree[v.l].minKey;
            v.maxKey = tree[v.r].maxKey;
        } else
            v.minKey = v.maxKey = v.key;
    }

    ArrayList<Integer> keys;
    ArrayList<Node> nodes;

    void calcIfComeAndAdd(Node v) {
        if (v.l == -1) {
            keys.add(v.key);
            nodes.add(v);
            return;
        }

        Node left = tree[v.l];
        Node right = tree[v.r];

        left.ifComeKeys = v.ifComeKeys + right.minKey;
        left.ifComeNodes = v.ifComeNodes + 1;

        right.ifComeKeys = v.ifComeKeys + left.maxKey;
        right.ifComeNodes = v.ifComeNodes + 1;

        calcIfComeAndAdd(tree[v.l]);        
        keys.add(v.key);
        nodes.add(v);
        calcIfComeAndAdd(tree[v.r]);
    }

    void solve() throws IOException {
        int n = nextInt();

        tree = new Node[n];
        int[] par = new int[n];

        for (int i = 0; i < n; i++) {
            par[i] = nextInt() - 1;
            tree[i] = new Node(nextInt());
        }

        Node root = null;

        for (int i = 0; i < n; i++) {
            if (par[i] == -2)
                root = tree[i];
            else if (tree[par[i]].key > tree[i].key)
                tree[par[i]].l = i;
            else
                tree[par[i]].r = i;
        }

        if (root == null)
            throw new AssertionError();

        calcMinMax(root);

        root.ifComeKeys = root.ifComeNodes = 0;
        
        keys = new ArrayList<Integer>();
        nodes = new ArrayList<Node>();

        calcIfComeAndAdd(root);

        int k = nextInt();
        for (int i = 0; i < k; i++) {
            int q = nextInt();
            int ind = Collections.binarySearch(keys, q);
            ind = -(ind + 1);
            ind -= ind % 2;

            Node ans = nodes.get(ind);

            double res = 1.0 * ans.ifComeKeys / ans.ifComeNodes;

            out.printf("%.12f\n", res);
        }

    }

    void inp() throws IOException {
        Locale.setDefault(Locale.US);
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