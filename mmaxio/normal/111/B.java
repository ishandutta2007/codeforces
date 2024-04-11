import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int MAX = 100000;
    
    int getLast(ArrayList<Integer> ls) {
        return ls.isEmpty() ? -1 : ls.get(ls.size() - 1);
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        
        ArrayList<Integer>[] isDiv = new ArrayList[MAX + 1];
        for (int i = 0; i < MAX + 1; i++)
            isDiv[i] = new ArrayList<Integer>();
        
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
            y[i] = nextInt();
            
            int ans = 0;
            
            for (int div = 1; div * div <= x[i]; div++)
                if (x[i] % div == 0) {
                    int last = getLast(isDiv[div]);
                    if (last < i - y[i])
                        ans++;
                    isDiv[div].add(i);
                    if (x[i] != div * div) {
                        last = getLast(isDiv[x[i] / div]);
                        if (last < i - y[i])
                            ans++;
                        isDiv[x[i] / div].add(i);
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