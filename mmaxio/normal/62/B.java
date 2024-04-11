import java.io.*;
import java.util.*;

public class Bnew {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int INF = 100000000;
    
    int fix(Integer k) {
        return k == null ? INF : k;
    }

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        char[] s = nextToken().toCharArray();
        
        TreeSet<Integer>[] memo = new TreeSet[26];
        for (int i = 0; i < 26; i++)
            memo[i] = new TreeSet<Integer>();
        
        for (int i = 0; i < k; i++)
            memo[s[i] - 'a'].add(i);
        
        /*for (int i = 0; i < 26; i++)
            System.err.println(memo[i]);*/
        
        for (int i = 0; i < n; i++) {
            long ans = 0;
            char[] t = nextToken().toCharArray();
            for (int j = 0; j < t.length; j++) {
                int cur = t[j] - 'a';
                //System.err.println(memo[cur]);
                if (memo[cur].isEmpty()) {
                    ans += t.length;
                }
                else {
                    int k1 = fix(memo[cur].floor(j));
                    int k2 = fix(memo[cur].ceiling(j));
                    ans += Math.min(Math.abs(k1 - j), Math.abs(k2 - j));
                }
            }
            out.println(ans);
        }
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Bnew().inp();
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