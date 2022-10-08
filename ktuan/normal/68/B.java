import java.util.*;
import java.io.*;

public class BaiB {
    
    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] a = new double[n];
        double k = sc.nextDouble();
        for(int i=0;i<n;++i)
            a[i] = sc.nextDouble();
        double L = 0, R = 1010;
        for(int kk=0;kk<100;++kk) {
            double M = (L + R) / 2;
            double need = 0, have = 0;
            for(int i=0;i<n;++i) {
                if(a[i] > M) have += a[i] - M;
                else need += M - a[i];
            }
            if(have - have * k / 100 >= need) L = M;
            else R = M;
        }
        System.out.printf("%.7f\n", L);
        
    }
    public static void main(String[] args) {
        new BaiB().run();
    }
}