import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    int calcScore() throws IOException {
        int res = 100 * nextInt() - 50 * nextInt();
        for (int i = 0; i < 5; i++)
            res += nextInt();
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        String ans = "";
        int score = -1000000;
        for (int i = 0; i < n; i++) {
            String name = nextToken();
            int c = calcScore();
            if (c > score) {
                score = c;
                ans = name;
            }
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