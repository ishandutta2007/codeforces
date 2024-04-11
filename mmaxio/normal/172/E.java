import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Node {
        String parentTag;
        Node child;
        Node sibling;
        Node parent;

        public Node() {
        }

        public Node(String parentTag, Node parent) {
            this.parentTag = parentTag;
            this.parent = parent;
            sibling = parent.child;
            parent.child = this;
        }

    }
    
    String[] sub;
    
    int dfs(Node v, int pos) {
        int res = 0;
        for (Node to = v.child; to != null; to = to.sibling) {
            if (to.parentTag.equals(sub[pos]))
                res += (pos == sub.length - 1) ? 1 + dfs(to, pos) : dfs(to, pos + 1);  
            else
                res += dfs(to, pos);
        }
        return res;
    }

    void solve() throws IOException {
        String[] walk = nextToken().split("[<>]+");
        walk = Arrays.copyOfRange(walk, 1, walk.length);

        Node root = new Node();
        Node v = root;

        for (String s : walk) {
            if (s.charAt(0) == '/')
                v = v.parent;
            else if (s.charAt(s.length() - 1) == '/')
                v.child = new Node(s.substring(0, s.length() - 1), v);
            else
                v = v.child = new Node(s, v);
        }
        
        int q = nextInt();
        while (q-- > 0) {
            sub = nextString().split(" ");
            out.println(dfs(root, 0));
        }
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new E().inp();
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