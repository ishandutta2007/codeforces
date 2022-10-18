import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        
        String[] tmp = nextString().split("\\.");
        int k = Integer.parseInt(tmp[1]);
        
        TreeMap<String, Integer> res = new TreeMap<String, Integer>();
        
        for (int i = 0; i < n; i++) {
            String s = nextToken();
            int exp = nextInt();
            exp = exp * k / 100;
            if (exp >= 100) {
                res.put(s, exp);
            }
        }
        
        for (int i = 0; i < m; i++) {
            String s = nextToken();
            if (!res.containsKey(s))
                res.put(s, 0);
        }
        
        
        out.println(res.size());
        for (String s : res.keySet())
            out.println(s + " " + res.get(s));
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A().inp();
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