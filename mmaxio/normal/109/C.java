import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    ArrayList<Integer> lucky;
    ArrayList<Integer>[] g;

    void gen(int cur, int len) {
        lucky.add(cur);
        if (len < 9) {
            gen(cur * 10 + 4, len + 1);
            gen(cur * 10 + 7, len + 1);
        }
    }
    
    int cnt;
    boolean[] use;

    void dfs(int v) {
        use[v] = true;
        cnt++;
        
        for (int to : g[v]) {
            if (!use[to]) 
                dfs(to);
        }
    }

    void solve() throws IOException {

        lucky = new ArrayList<Integer>();

        gen(4, 1);
        gen(7, 1);

        Collections.sort(lucky);

        int n = nextInt();

        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();

        for (int i = 0; i < n - 1; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;

            boolean luck = Collections.binarySearch(lucky, nextInt()) >= 0;

            if (!luck) {
                g[v1].add(v2);
                g[v2].add(v1);
            }
        }

        use = new boolean[n];
        
        ArrayList<Integer> sz = new ArrayList<Integer>();
        for (int i = 0; i < n; i++)
            if (!use[i]) {
                cnt = 0;
                dfs(i);
                sz.add(cnt);
            }
        
        long ans = 0;
        
        for (int p : sz) {
            int hasLuck = n - p;
            
            ans += (long)p * hasLuck * (hasLuck - 1);
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
        new C().inp();
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