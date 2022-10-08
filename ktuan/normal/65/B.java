import java.io.*;
import java.util.*;

public class BaiB {
    
    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;++i)
            a[i] = sc.nextInt();
        int bf = 1000;
        int[] p10 = new int[5];
        p10[0] = 1;
        for(int i=1;i<5;++i) p10[i] = 10 * p10[i-1];
        int[] b = new int[n];
        for(int i=0;i<n;++i) {
            int best = 2012;
            for(int d=0;d<4;++d) {
                int cs = a[i] % p10[d+1] / p10[d];
                int nv = a[i] - cs * p10[d];
                for(int nc=0;nc<10;++nc) {
                    int v = nv + nc * p10[d];
                    if(v >= bf) {
                        if(v < best) best = v;
                    }
                }
            }
            b[i] = best;
            bf = best;
        }
        for(int i=0;i<n;++i) if(b[i] < 1000 || b[i] > 2011) {
            System.out.println("No solution");
            return;
        }
        for(int i=0;i<n;++i) {
            System.out.println(b[i]);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new BaiB().run();
    }
}