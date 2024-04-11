import java.util.*;
import java.io.*;
public class B1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        long[] a = new long[n];
        for(int i=0;i<n;++i)
            a[i] = sc.nextLong();
        long res = 0;
        for(int i=1;i<n;++i) {
            if(a[i] <= a[i-1]) {
                long z = a[i-1] - a[i];
                long sl = z / d;
                if(d * sl <= z) ++sl;
                res += sl;
                a[i] += d * sl;
            }
        }
        System.out.println(res);
    }
}