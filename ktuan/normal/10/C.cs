using System;

public class Solution {

    static int n;
    static int[] c;
    static int[] f;
    
    static int calc(int x) {
        if(x < 10) return x;
        else {
            int s = 0 ;
            while(x > 0) {
                s += x % 10;
                x /= 10;
            }
            return calc(s);
        }
    }
    
    public static void Main() {
        n = int.Parse(Console.ReadLine());
        c = new int[10];
        f = new int[1000];
        for(int i=1;i<1000;++i) f[i] = calc(i);
        for(int i=1;i<=n;++i) {
            int z = 0;
            if(i < 1000) z = f[i];
            else {
                int s = 0;
                int x = i;
                while(x > 0) {
                    s += x % 10;
                    x /= 10;
                }
                z = f[s];
            }
            ++c[z];
        }
        long res = 0;
        for(int i=1;i<10;++i) 
            for(int j=1;j<10;++j) {
                res += (long)c[i] * c[j] * c[f[i*j]];
            }
        for(int i=1;i<=n;++i) {
            for(int j=1;i*j<=n;++j)
                --res;
        }
        Console.WriteLine(res);
    }
}