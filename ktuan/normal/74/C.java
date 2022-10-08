import java.io.*;
import java.util.*;
import java.math.*;

public class BaiC implements Runnable {
    
    int m, n;
    boolean[] vs;
    
    int find1minx(int total) {
        return Math.max(0, total - n + 1);
    }
    
    int find1maxx(int total) {
        return Math.min(total, m-1);
    }
    
    int find2minx(int total) {
        return Math.max(0, total);
    }
    
    int find2maxx(int total) {
        return Math.min(total + n - 1, m - 1);
    }
    
    int[] q;
    int le, ri;
    
    void bfs(int i) {
        le = ri = 0;
        q[0] = i;
        vs[i] = true;
        while(le <= ri) {
            i = q[le++];
            for(int t=0;t<2;++t) {
                int x = 0;
                if(t == 0) x = find1minx(i);
                else x = find1maxx(i);
                int y = i - x;
                int sub = x - y;
                int nx = find2minx(sub) + find2maxx(sub) - x;
                int ny = nx - sub;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) System.out.println("WRONG");
                int j = nx + ny;
                if(!vs[j]) {
                    vs[j] = true;
                    q[++ri] = j;
                }
            }
        }
    }
    
    public void run() {
        m = nextInt();
        n = nextInt();
        vs = new boolean[m+n-1];
        int res = 0;
        q = new int[m + n + 10];
        for(int i=0;i<=m+n-2;++i) if(!vs[i]) {
            ++res;
            bfs(i);
        }
        System.out.println(res);
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
        new BaiC().run();
    }
}