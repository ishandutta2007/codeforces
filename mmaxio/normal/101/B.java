import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    final int MOD = 1000000007;

    class Bus implements Comparable<Bus> {
        int l, r;

        public Bus(int l, int r) {
            super();
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Bus o) {
            return r - o.r;
        }

    }

    int[] fen;

    void upd(int x, int delta) {
        while (x < fen.length) {
            fen[x] += delta;
            if (fen[x] >= MOD)
                fen[x] -= MOD;
            x |= x + 1;
        }
    }

    int query(int x) {
        int res = 0;
        while (x >= 0) {
            res += fen[x];
            if (res >= MOD)
                res -= MOD;
            x = (x & (x + 1)) - 1;
        }
        return res;
    }

    int query(int l, int r) {
        int res = query(r) - query(l - 1);
        if (res < 0)
            res += MOD;
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();

        Bus[] table = new Bus[m];
        for (int i = 0; i < m; i++)
            table[i] = new Bus(nextInt(), nextInt());

        Arrays.sort(table);

        ArrayList<Integer> end = new ArrayList<Integer>();
        end.add(0);
        for (int i = 0; i < m; i++) {
            if (table[i].r != end.get(end.size() - 1))
                end.add(table[i].r);
        }

        if (n != end.get(end.size() - 1))
            end.add(n);

        fen = new int[end.size()];
        upd(0, 1);

        for (Bus b : table) {
            int dest = Collections.binarySearch(end, b.r);
            int l = Collections.binarySearch(end, b.l);
            if (l < 0)
                l = -l - 1;
            int r = dest - 1;
            int add = query(l, r);
            upd(dest, add);
        }
        
        out.print(query(fen.length - 1, fen.length - 1));

    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B().inp();
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