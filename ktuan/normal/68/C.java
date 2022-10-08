import java.util.*;
import java.io.*;

public class BaiC {
    
    int n;
    int[][] a, low, high;
    boolean[][] b;
    int[][] c;
    int[][] edges;
    int[] e;
    
    int[] best = null;
    
    void duyet(int pos, int cost) {
        if(pos == edges.length) {
            for(int i=1;i+1<n;++i) if(e[i] != 0) return;
            
            if(best == null || best[0] > -e[0] || (best[0] == -e[0] && best[1] < cost)) {
                best = new int[]{-e[0], cost};
            }
            return;
        }
        
        int u = edges[pos][0];
        int v = edges[pos][1];
        
        if(best != null && best[0] < -e[0]) return;
        
        boolean tiep = true;
        for(int i=1;i+1<n;++i) if(e[i] < 0) tiep = false;
        for(int i=1;i<u;++i) if(e[i] != 0) tiep = false;
        if(!tiep) return;
        
        for(int x=low[u][v];x<=high[u][v];++x) {
            c[u][v] = x;
            e[u] -= x;
            e[v] += x;
            duyet(pos+1, cost + (x == 0 ? 0 : (a[u][v] + x * x)));
            e[u] += x;
            e[v] -= x;
        }
    }
    
    void run() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][n];
        low = new int[n][n];
        high = new int[n][n];
        b = new boolean[n][n];
        
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j) {
                int u, v, l, h, z;
                
                u = sc.nextInt();
                v = sc.nextInt();
                l = sc.nextInt();
                h = sc.nextInt();
                z = sc.nextInt(); 
                // u = i+1; v = j+1; l = 0; h = 5; z = 5;
                a[u-1][v-1] = z;
                low[u-1][v-1] = l;
                high[u-1][v-1] = h;
            }
        
        edges = new int[n*(n-1)/2][];
        int ne = 0 ;
        
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j) {
                edges[ne++] = new int[]{i,j};
            }
        e = new int[n];
        c = new int[n][n];
        duyet(0, 0);
        if(best == null) System.out.println("-1 -1");
        else System.out.println(best[0] + " " + best[1]);
    }
    public static void main(String[] args) {
        // long tbegin = System.currentTimeMillis();
        new BaiC().run();
        // System.out.println(System.currentTimeMillis() - tbegin);
    }
}