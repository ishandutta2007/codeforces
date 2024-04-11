import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final Random rng = new Random();

    static class Pair implements Comparable<Pair> {
        int val, ind;

        public Pair(int val, int ind) {
            this.val = val;
            this.ind = ind;
        }

        @Override
        public int compareTo(Pair o) {
            return Integer.compare(val, o.val);
        }

    }

    void solve() throws IOException {
        int n = nextInt();
        Pair[] a = new Pair[n];
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            a[i] = new Pair(x, i);
        }

        Arrays.sort(a);

        int[] ans = new int[n];
        int leastFree = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].val >= leastFree) {
                ans[a[i].ind] = a[i].val;
                leastFree = a[i].val + 1;
            } else {
                ans[a[i].ind] = leastFree;
                leastFree++;
            }
        }

        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
        }

        out.println();
    }

    C() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C();
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