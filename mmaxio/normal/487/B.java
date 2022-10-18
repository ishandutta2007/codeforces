import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static class MultiTreeSet {
        private TreeMap<Integer, Integer> map = new TreeMap<>();

        int count(int x) {
            Integer ret = map.get(x);
            return ret == null ? 0 : ret;
        }

        void put(int x) {
            map.put(x, count(x) + 1);
        }
        
        void remove(int x) {
            int c = count(x);
            if (c == 1) {
                map.remove(x);
            } else {
                map.put(x, c - 1);
            }
        }
        
        int first() {
            return map.isEmpty() ? 1_000_000_001 : map.firstKey();
        }
        
        int last() {
            return map.isEmpty() ? -1 : map.lastKey();
        }
    }
    
    static final int INF = Integer.MAX_VALUE / 3;
    
    static class Node {
        int l, r;
        Node left, right;
        int min;
        public Node(int l, int r) {
            this.l = l;
            this.r = r;
            min = INF;
            if (r - l > 1) {
                int mid = (l + r) >> 1;
                left = new Node(l, mid);
                right = new Node(mid, r);
            }
        }
        
        int get(int ql, int qr) {
            if (l >= qr || ql >= r) {
                return INF;
            }
            if (ql <= l && r <= qr) {
                return min;
            }
            return Math.min(left.get(ql, qr), right.get(ql, qr));
        }
        
        void set(int ind, int val) {
            if (l == ind && ind + 1 == r){ 
                min = val;
                return;
            }
            (ind < left.r ? left : right).set(ind, val);
            min = Math.min(left.min, right.min);
        }
        
    }

    void solve() throws IOException {
        int n = nextInt();
        int s = nextInt();
        int l = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        
        int[] to = new int[n];
        
        MultiTreeSet set = new MultiTreeSet();
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n) {
                set.put(a[j]);
                if (set.last() - set.first() <= s) {
                    j++;
                } else {
                    set.remove(a[j]);
                    break;
                }
            }
            to[i] = j;
            set.remove(a[i]);
        }
        
        Node ans = new Node(0, n + 1);
        ans.set(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int from = i + l;
            int toQ = Math.min(to[i] + 1, n + 1);
//          System.err.println(i + " " + from + " " + toQ);
            
            if (from < toQ) {
//              System.err.println(ans.get(from, toQ));
                ans.set(i, ans.get(from, toQ) + 1);
            }
        }
        int ret = ans.get(0, 1);
        if (ret >= INF) {
            ret = -1;
        }
        out.println(ret);
    }

    B() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B();
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