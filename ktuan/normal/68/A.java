import java.util.*;
import java.io.*;

public class BaiA {
    
    int[] p;
    int a, b;
    int c;
    int x, x2;
    boolean[] mark;
    
    void duyet(int i) {
        if(i == 4) {
            if(x2 == x) ++c;
            return;
        }
        for(int j=0;j<4;++j) if(!mark[j]) {
            mark[j] = true;
            int xx = x;
            x %= p[j];
            duyet(i+1);
            x = xx;
            mark[j] = false;
        }
    }
    
    void run() {
        Scanner sc = new Scanner(System.in);
        p = new int[4];
        for(int i=0;i<4;++i)
            p[i] = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();
        int r = 0;
        for(int i=a;i<=b;++i) {
            c = 0;
            mark = new boolean[4];
            x = x2 = i;
            duyet(0);
            if(c >= 7) ++r;
        }
        System.out.println(r);
    }
    
    public static void main(String[] args) {
        new BaiA().run();
    }
}