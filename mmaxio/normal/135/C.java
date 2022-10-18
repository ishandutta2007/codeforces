import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        
        int n = s.length;
        int movesFirst = (n - 1) / 2;
        int movesSecond = (n - 2) / 2;
        
        int zero = 0;
        int one = 0;
        int dunno = 0;
        
        for (char c : s) {
            if (c == '0')
                zero++;
            else if (c == '1')
                one++;
            else if (c == '?')
                dunno++;
            else
                throw new AssertionError();
        }
        
        if (one <= movesFirst) {
            out.println("00");
        }
        
        int goodOne = (n + 1) / 2;
        int goodZero = n / 2;
        if (one <= goodOne && one + dunno >= goodOne) {
            boolean canMakeOne = one != goodOne;
            boolean canMakeZero = zero != goodZero;
            
            if (s[n - 1] == '0') {
                out.println("10");
            } else if (s[n - 1] == '1') {
                out.println("01");
            } else {
                if (canMakeOne)
                    out.println("01");
                if (canMakeZero)
                    out.println("10");
            }
        }
        
        
        if (zero <= movesSecond) {
            out.println("11");
        }
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