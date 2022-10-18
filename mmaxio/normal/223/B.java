import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        char[] t = nextToken().toCharArray();
        
        // find the leftmost occurence of t
        int[] posL = new int[t.length];     
        int j = 0;
        
        for (int i = 0; i < s.length && j < t.length; i++) {
            if (s[i] == t[j])
                posL[j++] = i; 
        }
        
        
        if (j != t.length) {
            out.println("No");
            return;
        }
        
        // find the rightmost occurence of t
        int[] posR = new int[t.length];
        j = t.length - 1;
        for (int i = s.length - 1; i >= 0 && j >= 0; i--) {
            if (s[i] == t[j])
                posR[j--] = i;
        }
        
        if (j != -1) {
            out.println("No");
            return;
        }
        
//      System.err.println(Arrays.toString(posL));
//      System.err.println(Arrays.toString(posR));
        
        ArrayList<Integer>[] posS = new ArrayList[26];
        ArrayList<Integer>[] posT = new ArrayList[26];
        
        for (int i = 0; i < 26; i++) {
            posS[i] = new ArrayList<Integer>();
            posT[i] = new ArrayList<Integer>();
        }
        
        for (int i = 0; i < s.length; i++) {
            int ind = s[i] - 'a';
            posS[ind].add(i);
        }
        
        for (int i = 0; i < t.length; i++) {
            int ind = t[i] - 'a';
            posT[ind].add(i);
        }
        
        for (int let = 0; let < 26; let++) {
            
            int[] sum = new int[s.length];
            
            for (int tj : posT[let]) {
                int lowVal = tj == 0 ? 0 : posL[tj - 1] + 1;
                int highVal = tj == t.length - 1 ? s.length - 1 : posR[tj + 1] - 1;
                
                sum[lowVal]++;
                if (highVal + 1 < s.length)
                    sum[highVal + 1]--;
                
                if (lowVal > highVal)
                    throw new AssertionError();
            }
            
            for (int i = 1; i < s.length; i++)
                sum[i] += sum[i - 1];
            
            for (int pos : posS[let])
                if (sum[pos] == 0) {
                    out.println("No");
                    return;
                }

            
        }
        
        out.println("Yes");
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