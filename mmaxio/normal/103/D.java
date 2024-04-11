import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    final int ROOT = 548;

    class Query implements Comparable<Query> {
        int st, gap, num;

        public Query(int a, int b, int num) {
            super();
            this.st = a;
            this.gap = b;
            this.num = num;
        }

        @Override
        public int compareTo(Query o) {
            // TODO Auto-generated method stub
            return gap - o.gap;
        }

    }

    void solve() throws IOException {
        int n = nextInt();
        int[] w = new int[n];

        for (int i = 0; i < n; i++)
            w[i] = nextInt();

        int qq = nextInt();
        long[] ans = new long[qq];

        Query[] list = new Query[qq];

        for (int i = 0; i < qq; i++)
            list[i] = new Query(nextInt() - 1, nextInt(), i);

        Arrays.sort(list);

        Query prev = null;

        long[] pref = new long[n];
        for (Query q : list) {
            
            //System.err.println(q.st + " " + q.gap + " " + q.num);
            
            long res = 0;
            if (q.gap <= ROOT) {
                if (prev == null || q.gap != prev.gap) {
                    for (int i = 0; i < n; i++)
                        if (i < q.gap)
                            pref[i] = w[i];
                        else
                            pref[i] = pref[i - q.gap] + w[i];
                }
                
                int first = q.st;
                int x = (n - q.st - 1) / q.gap;
                int last = q.st + x * q.gap;
                
                //System.err.println(first + " " + last);
                
                if (first < q.gap)
                    res = pref[last];
                else
                    res = pref[last] - pref[first - q.gap];
            } else {
                for (int i = q.st; i < n; i += q.gap)
                    res = res + w[i];
            }

            ans[q.num] = res;
            prev = q;
        }
        
        for (long x : ans)
            out.println(x);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D().inp();
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