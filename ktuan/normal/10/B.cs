using System;

public class Solution {

    static int n, k;
    static int[] len;
    static bool[,] free;
    static int[,] next;

    public static void Main() {
        String[] tmp = Console.ReadLine().Split(' ');
        n = int.Parse(tmp[0]);
        k = int.Parse(tmp[1]);
        tmp = Console.ReadLine().Split(' ');
        len = new int[n];
        for(int i=0;i<n;++i)
            len[i] = int.Parse(tmp[i]);
        free = new bool[k,k];
        next = new int[k,k];
        for(int i=0;i<k;++i) {
            for(int j=0;j<k;++j) {
                next[i,j] = k - j;
                free[i,j] = true;
            }
        }
        for(int i=0;i<n;++i) {
            int dmin = -1, cmin = -1;
            int cur = 1000000000;
            for(int d=0;d<k;++d)
                for(int c=0;c<k;++c) if(next[d,c] >= len[i]) {
                    int z = 0;
                    z += Math.Abs(d - k / 2) * len[i];
                    int dau = Math.Abs(c - k / 2);
                    int cuoi = Math.Abs(c + len[i] - 1 - k / 2);
                    if(c <= k/2 && c + len[i] - 1 >= k/2) {
                        z += dau * (dau + 1) / 2 + cuoi * (cuoi + 1) / 2;
                        if(z < cur) {
                            cur = z;
                            dmin = d;
                            cmin = c;
                        }
                    }
                    else if(c + len[i] - 1 < k / 2) {
                        z += dau * (dau + 1) / 2 - cuoi * (cuoi - 1) / 2;
                        if(z < cur) {
                            cur = z;
                            dmin = d;
                            cmin = c;
                        }
                    }
                    else {
                        z += cuoi * (cuoi + 1) / 2 - dau * (dau - 1) / 2;
                        if(z < cur) {
                            cur = z;
                            dmin = d;
                            cmin = c;
                        }
                    }
                }
            if(dmin == -1) Console.WriteLine(-1);
            else {
                Console.WriteLine( (dmin + 1) + " " + (cmin + 1) + " " + (cmin + len[i]));
                for(int c=cmin;c<cmin+len[i];++c) free[dmin,c] = false;
                for(int c=k-1;c>=0;--c) {
                    if(!free[dmin,c]) next[dmin,c] = 0;
                    else {
                        next[dmin,c] = 1 + (c + 1 < k ? next[dmin,c+1] : 0);
                    }
                }
            }
        }   
    }
}