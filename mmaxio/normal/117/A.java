import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt() - 1;

        for (int i = 0; i < n; i++) {
            int s = nextInt() - 1;
            int f = nextInt() - 1;

            int t = nextInt();

            if (s == f) {
                out.println(t);
                continue;
            }

            int tmp = t % (2 * m);
            
            int getIn = t;
            
            if (tmp < m) {
                //going up
                int floor = tmp;
                if (s >= floor)
                    getIn += (s - floor);
                else
                    getIn += (m - floor) + (m - s);
            } else {
                //going down
                int floor = 2 * m - tmp;
                if (s <= floor)
                    getIn += (floor - s);
                else
                    getIn += floor + s;
            }
            
            tmp = getIn % (2 * m);
            if (tmp < m) {
                //going up
                int floor = tmp;
                if (floor != s)
                    throw new AssertionError();
                if (f >= floor)
                    getIn += (f - floor);
                else
                    getIn += (m - floor) + (m - f);
            } else {
                //going down
                int floor = 2 * m - tmp;
                if (floor != s)
                    throw new AssertionError();
                if (f <= floor)
                    getIn += (floor - f);
                else
                    getIn += floor + f;
            }
            
            out.println(getIn);

        }
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A().inp();
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