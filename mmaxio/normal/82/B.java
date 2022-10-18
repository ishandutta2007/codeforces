import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int MAX_NUMBER = 200;

    void solve() throws IOException {
        int n = nextInt();
        int[][] cnt = new int[MAX_NUMBER][MAX_NUMBER];
        boolean[] use = new boolean[MAX_NUMBER];
        Arrays.fill(use, true);
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            int k = nextInt();
            int[] tmp = new int[k];
            for (int j = 0; j < k; j++) {
                tmp[j] = nextInt() - 1;
                use[tmp[j]] = false;
            }
            for (int j1 = 0; j1 < k; j1++)
                for (int j2 = j1 + 1; j2 < k; j2++) {
                    cnt[tmp[j1]][tmp[j2]]++;
                    cnt[tmp[j2]][tmp[j1]]++;
                }
        }
        
        if (n == 2) {
            for (int i = 0; i < MAX_NUMBER; i++) if (!use[i]) {
                out.println(1 + " " + (i + 1));
                int cc = 0;
                for (int j = i + 1; j < MAX_NUMBER; j++)
                    if (!use[j]) cc++;
                out.print(cc + " ");
                for (int j = i + 1; j < MAX_NUMBER; j++)
                    if (!use[j]) out.print((j + 1) + " ");
                return;
            }
        }
        
        for (int i = 0; i < MAX_NUMBER; i++) if (!use[i]){
            int cc = 1; use[i] = true;
            for (int j = 0; j < MAX_NUMBER; j++)
                if (cnt[i][j] == n - 1) {
                    cc++;
                    use[j] = true;
                }
            out.print(cc + " " + (i + 1) + " ");
            for (int j = 0; j < MAX_NUMBER; j++)
                if (cnt[i][j] == n - 1)
                    out.print((j + 1) + " ");
            out.println();
        }
        
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