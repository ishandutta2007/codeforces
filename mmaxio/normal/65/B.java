import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int[] date = new int[n];
        for (int i = 0; i < n; i++)
            date[i] = nextInt();

        int cur = 1000;
        for (int i = 0; i < n; i++) {
            char[] s = Integer.toString(date[i]).toCharArray();
            int best = 10000;
            for (int pos = 0; pos < 4; pos++)
                for (int dig = 0; dig < 10; dig++) {
                    if (pos == 0 && dig == 0)
                        continue;
                    char[] now = s.clone();
                    now[pos] = (char) (dig + '0');
                    //System.err.println(new String(now));
                    Integer ch = new Integer(new String(now));
                    if (ch < best && ch >= cur)
                        best = ch;
                }
            if (best == 10000) {
                out.print("No solution");
                return;
            }
            cur = best;
            date[i] = cur;
        }
        //System.err.println(cur);
        
        if (cur > 2011)
            out.print("No solution");
        else
            for (int i = 0; i < n; i++)
                out.println(date[i]);
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