import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    long[] cnt, inv;
    
    int n;
    
    long get(long[] f, int x) {
        long res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            res += f[i];
        return res;
    }
    
    void set(long[] f, int pos, long d) {
        for (int i = pos; i < n; i |= (i + 1)) {
            f[i] += d;
        }
    }
    
    long get(long[] f, int l, int r) {
        return get(f, r) - get(f, l - 1);
    }
    
    class Soldier implements Comparable<Soldier>{
        int str, pos;

        public Soldier(int str, int pos) {
            this.str = str;
            this.pos = pos;
        }

        @Override
        public int compareTo(Soldier o) {
            return str - o.str;
        }
    }

    void solve() throws IOException {
        n = nextInt();
        cnt = new long[n];
        inv = new long[n];
        Soldier[] a = new Soldier[n];
        
        for (int i = 0; i < n; i++)
            a[i] = new Soldier(nextInt(), i);
        
        Arrays.sort(a);
        
        long ans = 0;
        
        for (int i = 0; i < n; i++) {
            long tmp = get(cnt, a[i].pos, n - 1);
            set(cnt, a[i].pos, 1);
            ans += get(inv, a[i].pos, n - 1);
            set(inv, a[i].pos, tmp);
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
        new E().inp();
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