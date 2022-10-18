import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Thing implements Comparable<Thing> {
        int cost;
        int id;

        public Thing(int cost, int id) {
            this.cost = cost;
            this.id = id;
        }

        @Override
        public int compareTo(Thing o) {
            if (cost != o.cost)
                return cost > o.cost ? -1 : 1;
            return 0;
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();

        ArrayList<Thing> disc = new ArrayList<Thing>();
        ArrayList<Thing> rest = new ArrayList<Thing>();

        for (int i = 0; i < n; i++) {
            int cost = nextInt();
            int type = nextInt();
            Thing tmp = new Thing(cost, i + 1);
            if (type == 1)
                disc.add(tmp);
            else
                rest.add(tmp);
        }

        Collections.sort(disc);
        Collections.sort(rest);

        ArrayList<Integer>[] ans = new ArrayList[k];
        for (int i = 0; i < k; i++)
            ans[i] = new ArrayList<Integer>();
        long totalCost = 0;

        if (k >= disc.size() + 1) {
            for (int i = 0; i < disc.size(); i++) {
                ans[i].add(disc.get(i).id);
                totalCost += disc.get(i).cost;
            }
            int uk = 0;
            for (int i = disc.size(); i < k - 1; i++) {
                ans[i].add(rest.get(uk).id);
                totalCost += 2 * rest.get(uk).cost;
                uk++;
            }
            while (uk < rest.size()) {
                ans[k - 1].add(rest.get(uk).id);
                totalCost += 2 * rest.get(uk).cost;
                uk++;
            }
        } else {
            for (int i = 0; i < k - 1; i++) {
                ans[i].add(disc.get(i).id);
                totalCost += disc.get(i).cost;
            }
            int minCost = Integer.MAX_VALUE;
            for (int i = k - 1; i < disc.size(); i++) {
                ans[k - 1].add(disc.get(i).id);
                totalCost += 2 * disc.get(i).cost;
                minCost = Math.min(minCost, disc.get(i).cost);
            }
            for (int i = 0; i < rest.size(); i++) {
                ans[k - 1].add(rest.get(i).id);
                totalCost += 2 * rest.get(i).cost;
                minCost = Math.min(minCost, rest.get(i).cost);
            }
            totalCost -= minCost;
        }

        out.println((totalCost / 2) + "."
                + (((totalCost & 1) == 1) ? "5" : "0"));

        for (ArrayList<Integer> x : ans) {
            out.print(x.size() + " ");
            for (int y : x)
                out.print(y + " ");
            out.println();
        }

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