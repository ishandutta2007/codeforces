import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    //final String TASKNAME = "";

    void solve() throws IOException {
        int n = nextInt();
        int cnt[] = new int[3];
        for (int i = 0; i < n; i++) cnt[nextInt() - 1]++;
        int ans = Math.max(cnt[0], Math.max(cnt[1], cnt[2]));
        out.print(n - ans);
    }

    void inp() throws IOException {
        
        //br = new BufferedReader(new FileReader(TASKNAME + ".in"));
        //out = new PrintWriter(TASKNAME + ".out");
        
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

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

}