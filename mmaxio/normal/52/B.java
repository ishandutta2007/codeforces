import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    //final String TASKNAME = "";

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        char f[][] = new char[n][];
        for (int i = 0; i < n; i++)
            f[i] = nextToken().toCharArray();
        long ans = 0;
        int row[] = new int[n];
        int col[] = new int[m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (f[i][j] == '*') {
                    row[i]++;
                    col[j]++;
                }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (f[i][j] == '*')
                    ans = ans + (long)(row[i] - 1) * (col[j] - 1);
        
        out.print(ans);
                    
    }

    void inp() throws IOException {
        //br = new BufferedReader(new FileReader(TASKNAME + ".in"));
        //out = new PrintWriter(TASKNAME + ".out");
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

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

}