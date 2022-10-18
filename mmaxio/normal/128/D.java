import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        if (n % 2 == 1) {
            out.print("NO");
            return;
        }
        int[] a = new int[n];
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) { 
            a[i] = nextInt();
            min = Math.min(min, a[i]);
            max = Math.max(max, a[i]);
        }
        
        if (max - min > n / 2) {
            out.print("NO");
            return;
        }
        
        int[] cnt = new int[max - min + 1];
        for (int i = 0; i < n; i++)
            cnt[a[i] - min]++;
        
        int freeEnds = cnt[0];
        for (int i = 1; i < cnt.length; i++) {
            if (freeEnds == 0) {
                out.print("NO");
                return;
            }
            if (freeEnds > cnt[i]) {
                out.print("NO");
                return;
            }
            freeEnds = cnt[i] - freeEnds;
        }
        
        if (freeEnds != 0) {
            out.print("NO");
            return;
        }
        
        out.print("YES");
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