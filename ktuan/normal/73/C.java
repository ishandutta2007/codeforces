import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    public void run() {
        char[] ca = nextStr().toCharArray();
        int[] a = new int[ca.length];
        for(int i=0;i<ca.length;++i)
            a[i] = ca[i] - 'a';
        int k = nextInt();
        int np = nextInt();
        int[][] c = new int[26][26];
        for(int i=0;i<np;++i) {
            String s1 = nextStr();
            String s2 = nextStr();
            int cost = nextInt();
            c[s1.charAt(0)-'a'][s2.charAt(0)-'a'] = cost;
        }
        int[][][] F = new int[a.length+1][k+1][26];
        for(int[][] a2 : F)
            for(int[] a1 : a2)
                Arrays.fill(a1,-1000000000);
        F[0][0][0] = 0;
        for(int i=0;i<a.length;++i)
            for(int j=0;j<=k;++j) 
                for(int last=0;last<26;++last) {
                    for(int next=0;next<26;++next) {
                        int nj = j + (next != a[i] ? 1 : 0);
                        if(nj <= k)
                            F[i+1][nj][next] = Math.max(F[i+1][nj][next], F[i][j][last] + (i == 0 ? 0 : c[last][next]));
                    }
                }
        int best = -1000000000;
        for(int j=0;j<=k;++j)
            for(int last=0;last<26;++last)
                best = Math.max(best, F[a.length][j][last]);
        System.out.println(best);
    }
    
    BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer strtok = null;
    
    String nextStr() {
        try {
            while(strtok == null || !strtok.hasMoreTokens())
                strtok = new StringTokenizer(keyboard.readLine());
            return strtok.nextToken();
        }
        catch(Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
            return null;
        }
    }
    
    int nextInt() {
        return Integer.parseInt(nextStr());
    }
    
    long nextLong() {
        return Long.parseLong(nextStr());
    }
    
    double nextDouble() {
        return Double.parseDouble(nextStr());
    }
    
    public static void main(String[] args) {
        new BaiA().run();
    }
}