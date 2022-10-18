import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    ArrayList<Integer> f(int a, int b) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        for (int i = a; i <= b; i++) {
            if (i % a == 0 && b % i == 0)
                res.add(i);
        }
        return res;
    }
    
    ArrayList<Integer> getPeriods(char[] s) {
        int[] pi = new int[s.length];
        pi[0] = 0;
        for (int i = 1; i < s.length; i++) {
            int q = pi[i - 1];
            while (q != 0 && s[i] != s[q])
                q = pi[q - 1];
            if (s[i] == s[q])
                q++;
            pi[i] = q;
        }
        if (s.length % (s.length - pi[s.length - 1]) == 0) {
            int minPeriod = s.length - pi[s.length - 1];
            return f(minPeriod, s.length);
        } else {
        	ArrayList<Integer> res = new ArrayList<Integer>();
        	res.add(s.length);
            return res;
        }
    }

    void solve() throws IOException {
        char[] s1 = nextToken().toCharArray();
        char[] s2 = nextToken().toCharArray();
        if (s1.length > s2.length) {
            char[] tmp = s1;
            s1 = s2;
            s2 = tmp;
        }
        
        for (int i = 0; i < s2.length; i++) {
            if (s1[i % s1.length] != s2[i]) {
                out.println(0);
                return;
            }
        }
        
        ArrayList<Integer> a = getPeriods(s1);
        ArrayList<Integer> b = getPeriods(s2);
        
        int ukB = 0;
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            while (ukB != b.size() && b.get(ukB) < a.get(i))
                ukB++;
            if (ukB != b.size() && b.get(ukB).intValue() == a.get(i).intValue())
                res++;
        }
        out.println(res);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D().inp();
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