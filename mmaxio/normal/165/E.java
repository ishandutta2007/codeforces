import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int LOG = 22;
    static final int fullMask = (1 << LOG) - 1;
    
    boolean test(int x, int i) {
        return ((x >> i) & 1) == 1;
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++)
            a[i] = nextInt();

        int[] good = new int[1 << LOG]; // good[i] - any number from a which is
                                        // submask of i
        Arrays.fill(good, -1);
        for (int x : a)
            good[x] = x;

        for (int mask = 0; mask < good.length; mask++)
            if (good[mask] == -1)
                for (int j = 0; j < LOG; j++)
                    if (test(mask, j) && good[mask ^ (1 << j)] != -1) {
                        good[mask] = good[mask ^ (1 << j)];
                        break;
                    }
        
        for (int x : a)
            out.print(good[fullMask ^ x] + " ");
            
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new E().inp();
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