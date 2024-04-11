import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        
        ArrayList<Integer> ans = new ArrayList<Integer>();
        if (k > 32) {
            while (n != 0) {
                int x = Integer.highestOneBit(n);
                ans.add(x);
                n -= x;
            }
        } else {
            ArrayList<Long> f = new ArrayList<Long>();
            f.add(1L);
            for (int i = 1; true; i++) {
                long cur = 0;
                for (int j = Math.max(i - k, 0); j < i; j++)
                    cur += f.get(j);
                if (cur > n)
                    break;
                f.add(cur);
            }
            
            for (int i = f.size() - 1; i >= 0; i--) {
                if (n >= f.get(i)) {
                    ans.add((int)f.get(i).longValue());
                    n = (int) (n - f.get(i));
                }
            }
        }
        
        if (ans.size() == 1)
            ans.add(0);
        out.println(ans.size());
        for (int x : ans)
            out.print(x + " ");
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