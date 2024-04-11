import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int k1 = nextInt();
        int k2 = nextInt();
        int k3 = nextInt();

        int t1 = nextInt();
        int t2 = nextInt();
        int t3 = nextInt();

        int n = nextInt();

        long[] arrive = new long[n];
        for (int i = 0; i < n; i++)
            arrive[i] = nextLong();

        ArrayDeque<Long> q1 = new ArrayDeque<Long>();
        ArrayDeque<Long> q2 = new ArrayDeque<Long>();
        ArrayDeque<Long> q3 = new ArrayDeque<Long>();

        long ans = 0;

        for (long time : arrive) {

            long arr = time;

            while (!q1.isEmpty() && q1.peek() <= time)
                q1.poll();
            while (q1.size() >= k1)
                time = q1.poll();
            time += t1;
            q1.add(time);

            // System.err.println(time);

            while (!q2.isEmpty() && q2.peek() <= time)
                q2.poll();
            while (q2.size() >= k2)
                time = q2.poll();
            time += t2;
            q2.add(time);
            // System.err.println(time);

            while (!q3.isEmpty() && q3.peek() <= time)
                q3.poll();
            while (q3.size() >= k3)
                time = q3.poll();
            time += t3;
            q3.add(time);

            // System.err.println(time);
            // System.err.println("-----------");

            ans = Math.max(ans, time - arr);
        }

        out.print(ans);

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