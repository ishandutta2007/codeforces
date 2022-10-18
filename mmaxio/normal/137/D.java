import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int INF = Integer.MAX_VALUE / 2;
    
    char[] s;
    
    int getMin(int l, int r) {
        //System.err.println(l + " " + r);
        int cnt = 0;
        for (; l < r; l++, r--)
            if (s[l] != s[r])
                cnt++;
        
        return cnt;
    }
    
    void goPrint(int l, int r) {
        int iL = l;
        int iR = r;
        for (; l < r; l++, r--)
            if (s[l] != s[r])
                s[r] = s[l];
        
        for (int i = iL; i <= iR; i++)
            out.print(s[i]);
    }

    void solve() throws IOException {
        s = nextToken().toCharArray();
        int k = nextInt();
        
        int[][] dp = new int[s.length + 1][k + 1];
        
        Arrays.fill(dp[0], INF);
        dp[0][0] = 0;
        
        for (int i = 0; i < s.length; i++) {
            Arrays.fill(dp[i + 1], INF);
            for (int j = 0; j <= i; j++) {
                int cnt = getMin(j, i);
                for (int prev = 0; prev < k; prev++)
                    dp[i + 1][prev + 1] = Math.min(dp[i + 1][prev + 1], dp[j][prev] + cnt);
            }
        }
        
        int best = INF;
        int curMod = 0;
        for (int i = 0; i <= k; i++) {
            if (dp[s.length][i] < best) {
                best = dp[s.length][i];
                curMod = i;
            }
        }
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        int en = s.length;
        list.add(en);
        while (en != 0) {
            for (int j = 0; j <= en; j++) {
                int cnt = getMin(j, en - 1);
                if (dp[en][curMod] == dp[j][curMod - 1] + cnt) {
                    list.add(j);
                    en = j;
                    curMod--;
                    break;
                }
            }
        }
        
        Collections.reverse(list);
        
        out.println(best);
        for (int i = 0; i < list.size() - 1; i++) {
            if (i != 0)
                out.print("+");
            goPrint(list.get(i), list.get(i + 1) - 1);
        }
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