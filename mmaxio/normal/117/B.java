import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int MULT = 1000000000;

    void solve() throws IOException {
        int a = nextInt();
        int b = nextInt();
        
        int mod = nextInt();
        
        int aMult = MULT % mod;
        
        if (mod == 1) {
            out.print(2);
            return;
        }
        
        int maxBRem = Math.min(b, mod - 1);
        
        for (int i = 0; i < mod && i <= a; i++) {
            int aRem = (int) ((long)i * aMult % mod);
            if (aRem == 0 || aRem + maxBRem >= mod)
                continue;
            out.printf("1 %09d", i);
            return;
        }
        
        out.print(2);
        
        
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