import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int x = nextInt();
        int y = nextInt();
        int z = nextInt();
        
        int X = nextInt();
        int Y = nextInt();
        int Z = nextInt();
        
        int ans = 0;
        int val;
        
        val = nextInt();
        if (y < 0)
            ans += val;
        val = nextInt();
        if (y > Y)
            ans += val;
        val = nextInt();
        if (z < 0)
            ans += val;
        val = nextInt();
        if (z > Z)
            ans += val;
        val = nextInt();
        if (x < 0)
            ans += val;
        val = nextInt();
        if (x > X)
            ans += val;
        
        out.println(ans);
    }

    D() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D();
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