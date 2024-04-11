import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    class Pair implements Comparable<Pair>{
        char c;
        int freq;
        public Pair(char c, int freq) {
            super();
            this.c = c;
            this.freq = freq;
        }
        @Override
        public int compareTo(Pair o) {
            return o.freq - freq;
        }

    }

    void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        
        int k = nextInt();
        if (k >= s.length) {
            out.println(0);
            out.println();
            return;
        }
        
        k = s.length - k;
        
        int[] occ = new int[26];
        for (char c : s)
            occ[c - 'a']++;
        
        Pair[] arr = new Pair[26];
        
        for (int i = 0; i < 26; i++)
            arr[i] = new Pair((char)('a' + i), occ[i]);
        
        Arrays.sort(arr);
        
        int[] ans = new int[26];
        int res = 0;
        
        for (Pair p : arr) {
            res++;
            if (p.freq < k) {
                k -= p.freq;
                ans[p.c - 'a'] = p.freq;
            } else {
                ans[p.c - 'a'] = k;
                break;
            }
        }
        
        //System.err.println(Arrays.toString(ans));
        
        out.println(res);
        for (char c : s) {
            if (ans[c - 'a'] > 0) {
                out.print(c);
                ans[c - 'a']--;
            }
        }
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