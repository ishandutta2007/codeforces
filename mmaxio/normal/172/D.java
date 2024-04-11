import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int st = nextInt();
        int len = nextInt();
        int en = st + len - 1;
        
        int up = (int) Math.sqrt(en);
        
        int[] a = new int[len];
        
        for (int i = 0; i < len; i++)
            a[i] = st + i;
        
        for (int i = up; i >= 2; i--) {
            int sq = i * i;
            for (int j = en / sq * sq - st; j >= 0; j -= sq)
                if (a[j] % sq == 0)
                    a[j] /= sq;
        }
        
        long ans = 0;
        for (int x : a)
            ans += x;
                
        out.println(ans);
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