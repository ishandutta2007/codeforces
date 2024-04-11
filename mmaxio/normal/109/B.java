import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    ArrayList<Integer> luck;
    
    final int INF = 1000000100;
    
    void gen(int cur, int len) {
        luck.add(cur);
        if (len < 9) {
            gen(cur * 10 + 4, len + 1);
            gen(cur * 10 + 7, len + 1);
        }
    }
    
    int inter(int a, int b, int c, int d) {
        int res = Math.min(b, d) - Math.max(a, c) + 1;
        return res < 0 ? 0 : res;
    }

    void solve() throws IOException {
        int pl = nextInt();
        int pr = nextInt();
        int vl = nextInt();
        int vr = nextInt();
        
        int k = nextInt();
        
        luck = new ArrayList<Integer>();
        
        gen(4, 1);
        gen(7, 1);
        
        Collections.sort(luck);
        
        //System.err.println(luck);
        
        int lenP = pr - pl + 1;
        int lenV = vr - vl + 1;
        
        long total = (long)lenP * lenV;
        long good = 0;
        
        for (int st = 0; st <= luck.size() - k; st++) {
            int en = st + k - 1;
            
            int low1, high1, low2, high2;
            
            low1 = st == 0 ? 0 : luck.get(st - 1) + 1;
            high1 = luck.get(st);
            
            low2 = luck.get(en);
            high2 = en == luck.size() - 1 ? INF : luck.get(en + 1) - 1;
            
            good += (long)inter(low1, high1, pl, pr) * inter(low2, high2, vl, vr);
            good += (long)inter(low1, high1, vl, vr) * inter(low2, high2, pl, pr);

            if (k == 1 && pl <= luck.get(st) && luck.get(st) <= pr && vl <= luck.get(st) && luck.get(st) <= vr)
                good--;
        }
        
//      System.err.println(good);
//      System.err.println(total);
        
        out.printf(Locale.US, "%.12f", 1.0 * good / total);
        
        
        
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