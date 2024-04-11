import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        long h = nextLong();
        long w = nextLong();
        
        long ans_h = -1, ans_w = -1, ans_sq = -1;
        
        for (long cut_h = 1; cut_h <= h; cut_h <<= 1) {
            long min_cut_w = (cut_h * 4 + 4) / 5;
            long max_cut_w = cut_h * 5 / 4;
            min_cut_w = Math.max(min_cut_w, 1);
            max_cut_w = Math.min(max_cut_w, w);
            if (min_cut_w > max_cut_w) continue;
            long cut_w = max_cut_w;
            long cut_sq = cut_w * cut_h;
            if (cut_sq > ans_sq || (cut_sq == ans_sq && cut_h > ans_h)) {
                ans_h = cut_h;
                ans_w = cut_w;
                ans_sq = cut_sq;
            }
        }
        
        for (long cut_w = 1; cut_w <= w; cut_w <<= 1) {
            long min_cut_h = (cut_w * 4 + 4) / 5;
            long max_cut_h = cut_w * 5 / 4;
            min_cut_h = Math.max(min_cut_h, 1);
            max_cut_h = Math.min(max_cut_h, h);
            if (min_cut_h > max_cut_h) continue;
            long cut_h = max_cut_h;
            long cut_sq = cut_w * cut_h;
            if (cut_sq > ans_sq || (cut_sq == ans_sq && cut_h > ans_h)) {
                ans_h = cut_h;
                ans_w = cut_w;
                ans_sq = cut_sq;
            }
        }
        
        out.print(ans_h + " " + ans_w);
        
        
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