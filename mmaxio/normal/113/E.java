import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int hNum, mNum, k, newHourK;
    int newDayChange;
    
    long pow10;
    long pow10Hour;

    long go(int h, int m) {
        // good moments from (0, 0) to (h, m)
        //System.err.println(h + " " + m + " ");
        if (m < 0) {
            m += mNum;
            h--;
        }

        if (h < 0)
            return 0;
        
        long res = 0;
        
        // when hour doesn't change
        
        // first h full hours
        res += (long)h * ((mNum - 1) / pow10);
        
        //System.err.println(res);
        
        //last hour also full
        if (m == mNum - 1)
            res += (mNum - 1) / pow10;
        //last hour not full
        else
            res += (m + 1) / pow10;
        
        //hour also changes
        //in fact everything is the same, but we use newHourK instead of k
        if (m != mNum - 1)
            h--;
        
        //hour changes for hours [0, h]
        
        if (h == hNum - 1) {
            if (newDayChange >= newHourK)
                res++;
            h--;
        }
        // if it's full day, last change must be treated separately
        res += (h + 1) / pow10Hour;
        
        //System.err.println(res);
        
        return res;
    }

    void solve() throws IOException {
        hNum = nextInt();
        mNum = nextInt();
        k = nextInt();

        int h1 = nextInt();
        int m1 = nextInt();

        int h2 = nextInt();
        int m2 = nextInt();
        
        int newHourChange = 0;
        
        String s = Integer.toString(mNum - 1);
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) != '0')
                newHourChange++;
        
        pow10 = 1;
        for (int i = 0; i < k - 1; i++)
            pow10 *= 10;
        
        newHourK = Math.max(k - newHourChange, 1);
        
        pow10Hour = 1;
        for (int i = 0; i < newHourK - 1; i++)
            pow10Hour *= 10;
        
        newDayChange = 0;
        s = Integer.toString(hNum - 1);
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) != '0')
                newDayChange++;

        if (h1 < h2 || (h1 == h2 && m1 <= m2))
            // good moments from (h1,m1) to (h2,m2-1)
            out.print(go(h2, m2 - 1) - go(h1, m1 - 1));
        else 
            // good moments from (h1, m1) to (hNum - 1, mNum - 1) and from (0, 0) to (h2, m2 - 1)
            out.print(go(hNum - 1, mNum - 1) - go(h1, m1 - 1) + go(h2, m2 - 1));
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