import java.io.*;
import java.util.*;

public class cf91_D {

    final long MAX_NUMBER = 2000000000000000000L;
    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    void reverse(long[] a) {
        for (int l = 0, r = a.length - 1; l < r; l++, r--) {
            long tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
        }
    }
    
    long safeAdd(long a, long b) {
        return Math.min(a + b, MAX_NUMBER);
    }
    
    long safeMul(long a, long b) {
        if (a == 0 || b == 0)
            return 0;
        return a > MAX_NUMBER / b ? MAX_NUMBER : a * b;
    }

    void solve() throws IOException {
        int n = nextInt();
        
        long k = nextLong();
        long[] low = new long[n];
        long[] high = new long[n];
        
        long minLength = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            low[i] = nextLong();
            high[i] = nextLong();
            minLength = Math.min(minLength, high[i] - low[i]);
        }
        
        ArrayList<Long> lucky = new ArrayList<Long>();
        lucky.add(4L);
        lucky.add(7L);
        int head = 0;
        while (head < lucky.size()) {
            long cur = lucky.get(head++);
            if (cur * 10 + 4 < MAX_NUMBER) {
                lucky.add(cur * 10 + 4);
            }
            if (cur * 10 + 7 < MAX_NUMBER) {
                lucky.add(cur * 10 + 7);
            }
        }
        
        int m = lucky.size();
        long[] shiftLeft = new long[m];
        long[] shiftRight = new long[m];
        
        Arrays.sort(high);
        int uk = 0;
        long cur = 0;
        for (int i = 0; i < m; i++) {
            long curLucky = lucky.get(i);
            if (i != 0)
                cur = safeAdd(cur, safeMul(curLucky - lucky.get(i - 1), uk));
            while (uk < n && high[uk] <= curLucky)
                cur = safeAdd(cur, curLucky - high[uk++]);
            shiftRight[i] = cur;
        }
        
        Arrays.sort(low);
        reverse(low);
        uk = 0;
        cur = 0;
        for (int i = m - 1; i >= 0; i--) {
            long curLucky = lucky.get(i);
            if (i != m - 1)
                cur = safeAdd(cur, safeMul(lucky.get(i + 1) - curLucky, uk));
            while (uk < n && low[uk] >= curLucky)
                cur = safeAdd(cur, low[uk++] - curLucky);
            shiftLeft[i] = cur;
        }
        
        int ans = 0;
        
        int right = 0;
        for (int left = 0; left < m; left++) {
            while (right < m && shiftLeft[left] + shiftRight[right] <= k && lucky.get(right) - lucky.get(left) <= minLength)
                right++;
            ans = Math.max(ans, right - left);
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
        new cf91_D().inp();
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