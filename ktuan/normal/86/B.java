import java.io.*;
import java.util.*;
import java.math.*;

public class BaiB implements Runnable {
    
    int[] dx = new int[] {-1, 0, 1, 0};
    int[] dy = new int[] {0, 1, 0, -1};
    
    int m, n;
    char[][] a;
    int[][] b;
    boolean[] mark = new boolean[10];
    boolean[][] vs;
    boolean[][] vs2;
    
    void go(int i, int j) {
        vs[i][j] = true;
        for(int h=0;h<4;++h) {
            int u = i + dx[h];
            int v = j + dy[h];
            if(0<=u&&u<m&&0<=v&&v<n) {
                if(b[u][v] == b[i][j]) {
                    if(!vs[u][v]) go(u, v);
                }
                else if('0' <= a[u][v] && a[u][v] <= '9') mark[a[u][v]-'0'] = true;
            }
        }
    }
    
    void go2(int i, int j, char c) {
        vs2[i][j] = true;
        a[i][j] = c;
        for(int h=0;h<4;++h) {
            int u = i + dx[h];
            int v = j + dy[h];
            if(0<=u&&u<m&&0<=v&&v<n) {
                if(b[u][v] == b[i][j]) {
                    if(!vs2[u][v]) go2(u, v, c);
                }
            }
        }
    }
    
    public void run() {
        m = nextInt();
        n = nextInt();
        a = new char[m][];
        for(int i=0;i<m;++i)
            a[i] = nextStr().toCharArray();
        b = new int[m][n];
        int cb = 0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j) {
                if(j + 1 < n && a[i][j] == '.' && a[i][j+1] == '.' && b[i][j] == 0 && b[i][j+1] == 0) {
                    b[i][j] = b[i][j+1] = ++cb; 
                }
                if(i + 1 < m && a[i][j] == '.' && a[i+1][j] == '.' && b[i][j] == 0 && b[i+1][j] == 0) {
                    b[i][j] = b[i+1][j] = ++cb;
                }
            }
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(a[i][j] == '.' && b[i][j] == 0) {
                    int z = -1;
                    for(int h=0;h<4;++h) {
                        int u = i + dx[h];
                        int v = j + dy[h];
                        if(0<=u&&u<m&&0<=v&&v<n && b[u][v] > 0) {
                            z = b[u][v];
                            break;
                        }
                    }
                    if(z == -1) {
                        System.out.println("-1");
                        return;
                    }
                    b[i][j] = z;
                }
        
        vs = new boolean[m][n];
        vs2 = new boolean[m][n];
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j) if(a[i][j] == '.' && b[i][j] > 0) {
                Arrays.fill(mark,false);
                go(i, j);
                char c = 0;
                for(int t=0;t<10;++t) if(!mark[t]) c = (char)(t + '0');
                if(c == 0) System.out.println("WRONG");
                else go2(i,j, c);
            }
        for(int i=0;i<m;++i)
            System.out.println(a[i]);
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
        new BaiB().run();
    }
}