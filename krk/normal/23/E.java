import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

    static int n;
    static ArrayList<Integer> neigh[];
    static int siz[];
    static BigInteger dp[][];
    static BigInteger best[];
    
    private static void Calc(int v, int p)
    {
        siz[v] = 1;
        dp[v][0] = BigInteger.ZERO;
        dp[v][1] = BigInteger.ONE;
        for (int u: neigh[v]) if (u != p) {
            Calc(u, v); 
            for (int i = siz[v] + 1; i <= siz[v] + siz[u]; i++)
                dp[v][i] = BigInteger.ZERO;
            siz[v] += siz[u];
            for (int i = siz[v]; i >= 1; i--) {
                dp[v][i] = dp[v][i].multiply(best[u]);
                for (int j = 1; j <= siz[u] && i - j >= 0; j++)
                    dp[v][i] = dp[v][i].max(dp[v][i - j].multiply(dp[u][j]));
            }
        }
        best[v] = BigInteger.ZERO;
        for (int i = 1; i <= siz[v]; i++)
            best[v] = best[v].max(dp[v][i].multiply(BigInteger.valueOf(i)));
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter fout = new PrintWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(fin.readLine());
        neigh = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            neigh[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int a, b; String s[] = fin.readLine().split(" ");
            a = Integer.parseInt(s[0]); b = Integer.parseInt(s[1]);
            neigh[a].add(b); neigh[b].add(a);
        }
        siz = new int[n + 1];
        dp = new BigInteger[n + 1][n + 1]; best = new BigInteger[n + 1];
        Calc(1, 0);
        fout.println(best[1]);
        fin.close(); fout.close();
    }
}