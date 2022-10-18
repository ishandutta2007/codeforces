import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    static final int INF = Integer.MIN_VALUE;

    static class Node {
        int l, r;
        Node left, right;
        int[] dirs;

        public Node(int l, int r, char[][] field) {
            this.l = l;
            this.r = r;
            if (r - l == 1) {
                dirs = getDirs(field[l], l);
            } else {
                int mid = (l + r) >> 1;
                left = new Node(l, mid, field);
                right = new Node(mid, r, field);
                dirs = combine(right.dirs, left.dirs);
            }
        }
        
        int[] get(int ql, int qr) {
            if (l >= qr || ql >= r) {
                return null;
            }
            if (ql <= l && r <= qr) {
                return dirs;
            }
            return combine(right.get(ql, qr), left.get(ql, qr));
        }
        
        void set(int pos, int[] newD) {
            if (l == pos && pos + 1 == r) {
                dirs = newD;
                return;
            }
            (pos < left.r ? left : right).set(pos, newD);
            dirs = combine(right.dirs, left.dirs);
        }

    }

    static int[] combine(int[] d1, int[] d2) {
        if (d1 == null) {
            return d2;
        }
        if (d2 == null) {
            return d1;
        }
        int[] ret = new int[d1.length];
        for (int i = 0; i < d1.length; i++) {
            if (d1[i] < 0 || d1[i] >= d1.length) {
                ret[i] = d1[i];
            } else {
                ret[i] = d2[d1[i]];
            }
        }
        return ret;
    }

    // -1 -> left, n -> right, -2 -> gg
    static int[] getDirs(char[] c, int row) {
        int[] ret = new int[c.length];
        boolean[] vis = new boolean[c.length];
        outer: for (int i = 0; i < c.length; i++) {
            Arrays.fill(vis, false);
            int j = i;
            vis[j] = true;
            while (true) {
                if (c[j] == '<') {
                    j--;
                    if (j == -1) {
                        ret[i] = -1 - row;
                        continue outer;
                    }
                } else if (c[j] == '>') {
                    j++;
                    if (j == c.length) {
                        ret[i] = c.length + row;
                        continue outer;
                    }
                } else {
                    ret[i] = j;
                    continue outer;
                }
                if (vis[j]) {
                    ret[i] = INF;
                    continue outer;
                }
                vis[j] = true;
            }
        }
        return ret;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int q = nextInt();
        char[][] f = new char[n][];
        for (int i = 0; i < n; i++) {
            f[i] = nextToken().toCharArray();
        }
        
        Node root = new Node(0, n, f);
        while (q-- > 0) {
            char type = nextToken().charAt(0);
            int x = nextInt() - 1;
            int y = nextInt() - 1;
//          System.err.println(x + " " +y);
            if (type == 'A') {
                int[] dirs = root.get(0, x + 1);
                int targ = dirs[y];
                if (targ >= 0 && targ < m) {
                    out.println("0 " + (targ + 1));
                } else if (targ == INF) {
                    out.println("-1 -1");
                } else if (targ < 0) {
                    int row = -1 - targ;
                    out.println((row + 1) + " " + 0);
                } else if (targ >= m) {
                    int row = targ - m;
                    out.println((row + 1) + " " + (m + 1));
                }
            } else {
                char newC = nextToken().charAt(0);
                f[x][y] = newC;
                int[] newD = getDirs(f[x], x);
                root.set(x, newD);
            }
        }
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