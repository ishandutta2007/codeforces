import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int INF = Integer.MAX_VALUE / 3;

    static class Node {
        int l, r;
        Node left, right;
        int add;
        int max;

        public Node(Node base, int newAdd) {
            l = base.l;
            r = base.r;
            left = base.left;
            right = base.right;
            max = base.max;
            add = newAdd;
        }

        public Node(int l, int r) {
            this.l = l;
            this.r = r;
            if (r - l > 1) {
                int mid = (l + r) >> 1;
                left = new Node(l, mid);
                right = new Node(mid, r);
            }
        }

        Node(Node base, Node newL, Node newR, int newMax) {
            l = base.l;
            r = base.r;
            left = newL;
            right = newR;
            add = base.add;
            max = newMax;
        }

        int getMax() {
            return max + add;
        }

        int get(int ql, int qr) {
            if (ql <= l && r <= qr) {
                return getMax();
            }
            if (l >= qr || ql >= r) {
                return -INF;
            }
            return Math.max(left.get(ql, qr), right.get(ql, qr)) + add;
        }

        Node add(int ql, int qr, int delta) {
            if (ql <= l && r <= qr) {
                return new Node(this, add + delta);
            }
            if (l >= qr || ql >= r) {
                return this;
            }
            Node newL = left.add(ql, qr, delta);
            Node newR = right.add(ql, qr, delta);
            return new Node(this, newL, newR, Math.max(newL.getMax(),
                    newR.getMax()));
        }

    }

    static class Column implements Comparable<Column> {
        int pos, h;

        public Column(int pos, int h) {
            this.pos = pos;
            this.h = h;
        }

        @Override
        public int compareTo(Column o) {
            return -Integer.compare(h, o.h);
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        Column[] a = new Column[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Column(i + 1, nextInt());
        }
        Arrays.sort(a);
        Node[] roots = new Node[n + 1];
        roots[0] = new Node(1, n + 1);

        int[] other = new int[n + 2];
        Arrays.fill(other, -1);

        for (int i = 0; i < n; i++) {
            int pos = a[i].pos;
            int leftAdd;
            if (other[pos - 1] == -1) {
                leftAdd = pos;
            } else {
                leftAdd = other[pos - 1];
            }
            int valAdd;
            if (other[pos + 1] == -1) {
                valAdd = 1;
            } else {
                valAdd = other[pos + 1] - pos + 1;
            }
            roots[i + 1] = roots[i].add(leftAdd, pos + 1, valAdd);
            int newLeft = other[pos - 1] == -1 ? pos : other[pos - 1];
            int newRight = other[pos + 1] == -1 ? pos : other[pos + 1];
            other[newLeft] = newRight;
            other[newRight] = newLeft;
        }

        int q = nextInt();
        while (q-- > 0) {
            int l = nextInt();
            int r = nextInt();
            int w = nextInt();
            r = r + 2 - w;
            int low = 0;
            int high = n;
            while (low + 1 < high) {
                int mid = (low + high) >> 1;
                if (roots[mid].get(l, r) >= w) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            out.println(a[high - 1].h);
        }
    }

    E() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new E();
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