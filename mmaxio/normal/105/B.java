import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    int[] level;
    int[] loyal;
    double ans;
    int n, k, plLev, needVotes;
    
    double check() {
        
        //System.err.println(Arrays.toString(loyal));
        double res = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            double prob = 1;
            int vote = 0;
            int kill = 0;
            for (int i = 0; i < n; i++) 
                if (((mask >> i) & 1) == 1) {
                    prob *= loyal[i] / 100.0;
                    vote++;
                }
                else {
                    prob *= 1 - loyal[i] / 100.0;
                    kill += level[i];
                }
            if (vote >= needVotes)
                res += prob;
            else
                res += prob * plLev / (kill + plLev);
        }
        
        return res;
    }
    
    void go(int ind, int candy) {
        if (ind == n) {
            ans = Math.max(ans, check());
            return;
        }
        
        for (int i = 0; i <= candy; i++) {
            loyal[ind] += 10 * i;
            if (loyal[ind] > 100) {
                loyal[ind] -= 10 * i;
                break;
            }
            go(ind + 1, candy - i);
            loyal[ind] -= 10 * i;
        }
        
    }
    

    void solve() throws IOException {
        
        n = nextInt();
        k = nextInt();
        plLev = nextInt();
        needVotes = n / 2 + 1;
        ans = 0;
        
        level = new int[n];
        loyal = new int[n];
        
        for (int i = 0; i < n; i++) {
            level[i] = nextInt();
            loyal[i] = nextInt();
        }
        
        go(0, k);
        
        out.printf("%.12f", ans);
    }

    void inp() throws IOException {
        Locale.setDefault(Locale.US);
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