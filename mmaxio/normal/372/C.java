import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int d = nextInt();

        long ans = 0;

        int[] a = new int[m];
        int[] t = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = nextInt() - 1;
            ans += nextInt();
            t[i] = nextInt();
        }

        long[] dp = new long[n];
        long[] next = new long[n];

        int prevTime = 1;

        Deque<Integer> q = new ArrayDeque<>();

        for (int i = 0; i < m;) {
            
            int j = i;
            while (j < m && t[j] == t[i]) {
                j++;
            }
            int delta = (int) Math.min((long) d * (t[i] - prevTime), n);
            int[] where = new int[j - i];
            for (int k = i; k < j; k++) {
                where[k - i] = a[k];
            }

            q.clear();
            int curFrom = 0;
            int curTo = -1;
            for (int k = 0; k < n; k++) {
                next[k] = 0;
                for (int kk = 0; kk < j - i; kk++) {
                    next[k] += Math.abs(k - where[kk]);
                }
                
                int nextFrom = Math.max(k - delta, 0);
                int nextTo = Math.min(k + delta, n - 1);

                while (curTo < nextTo) {
                    int indAdd = ++curTo;
                    while (!q.isEmpty() && dp[q.peekLast()] >= dp[indAdd]) {
                        q.pollLast();
                    }
                    q.addLast(indAdd);
                }
                while (curFrom < nextFrom) {
                    int indRemove = curFrom++;
                    if (q.peekFirst() == indRemove) {
                        q.pollFirst();
                    }
                }

                next[k] += dp[q.peekFirst()];
            }

            long[] tmp = dp;
            dp = next;
            next = tmp;

            prevTime = t[i];
            i = j;
        }

        long sub = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            sub = Math.min(sub, dp[i]);
        }

        out.println(ans - sub);

    }

    void myAdd(Deque<Long> q, long x) {
        while (!q.isEmpty() && q.peekLast() >= x) {
            q.pollLast();
        }
        q.addLast(x);
    }

    void myRemove(Deque<Long> q, long x) {

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