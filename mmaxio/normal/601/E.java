import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int k;

    static final int P = 10_000_000 + 19;
    static final int MOD = 1_000_000_000 + 7;

    class Knapsack {

        List<int[]> dps = new ArrayList<>();

        public Knapsack() {
            dps.add(new int[k + 1]);
        }

        void put(int value, int mass) {
//          System.err.println("push " + value + " " + mass);
            int[] next = dps.get(dps.size() - 1).clone();
            for (int i = k; i >= mass; i--) {
                next[i] = Math.max(next[i], next[i - mass] + value);
            }
            dps.add(next);
        }

        void rollback(int time) {
            while (dps.size() > time) {
//              System.err.println("pop");
                dps.remove(dps.size() - 1);
            }
        }

        int getHash() {
            int[] top = dps.get(dps.size() - 1);
            int ret = 0;
            for (int i = k; i >= 1; i--) {
                ret = (int) (((long) ret * P + top[i]) % MOD);
            }
            return ret;
        }
    }

    static class Query {
        boolean item; // false - get
        int value, mass;
        int from, to;

        public Query(boolean item, int value, int mass, int from, int to) {
            this.item = item;
            this.value = value;
            this.mass = mass;
            this.from = from;
            this.to = to;
        }

        @Override
        public String toString() {
            return "Query [item=" + item + ", value=" + value + ", mass="
                    + mass + ", from=" + from + ", to=" + to + "]";
        }
    }

    void go(List<Query> qs, int low, int high, Knapsack sack) {
        List<Query> newQs = new ArrayList<>();
        int time = sack.dps.size();
        for (Query q : qs) {
            if (q.item && q.from <= low && q.to >= high - 1) {
                sack.put(q.value, q.mass);
            } else if (q.from >= high || q.to < low) {

            } else {
                newQs.add(q);
            }
        }
        if (high - low == 1) {
            for (Query q : newQs) {
                if (!q.item && q.from == low) {
                    out.println(sack.getHash());
//                  System.err.println(low + " " + high + " " + q);
                }
            }
        } else {
            int mid = (low + high) >> 1;

            go(newQs, low, mid, sack);
            go(newQs, mid, high, sack);
        }
        sack.rollback(time);
    }

    void solve() throws IOException {
        int n = nextInt();
        k = nextInt();

        int[] vals = new int[n];
        int[] masses = new int[n];
        for (int i = 0; i < n; i++) {
            vals[i] = nextInt();
            masses[i] = nextInt();
        }

        int q = nextInt();
        int[] ids = new int[n + q];
        int[] types = new int[n + q];
        int[] remove = new int[n + q];
        Arrays.fill(remove, n + q);
        for (int i = 0; i < n; i++) {
            ids[i] = i;
            types[i] = 1;
        }
        vals = Arrays.copyOf(vals, n + q);
        masses = Arrays.copyOf(masses, n + q);

        List<Integer> addPos = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            addPos.add(i);
        }

        int addCnt = n;

        for (int i = n; i < n + q; i++) {
            types[i] = nextInt();
            if (types[i] == 1) {
                vals[i] = nextInt();
                masses[i] = nextInt();
                ids[i] = addCnt++;
                addPos.add(i);
            } else if (types[i] == 2) {
                int remId = nextInt() - 1;
                remove[addPos.get(remId)] = i;
            }
        }

        List<Query> qs = new ArrayList<>();

        for (int i = 0; i < n + q; i++) {
            if (types[i] == 1) {
                qs.add(new Query(true, vals[i], masses[i], i, remove[i]));
            } else if (types[i] == 3) {
                qs.add(new Query(false, 0, 0, i, i));
            }
        }

        // System.err.println(qs);
        go(qs, 0, n + q, new Knapsack());
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