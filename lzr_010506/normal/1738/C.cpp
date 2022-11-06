#include <bits/stdc++.h>
using namespace std;
int dp[110][110][2][2];
int main() 
{
    int T;
    scanf("%d", &T);
    while(T --) 
    {
        int n;
        scanf("%d", &n);
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i ++) 
        {
            int x;
            scanf("%d", &x);
            if (x & 1) cnt1 ++;
            else cnt0 ++;
        }
        if(cnt1 == 0) {puts("Alice"); continue;}
        for (int i = 0; i <= cnt0; i ++) 
            for (int j = 0; j <= cnt1; j ++) 
                for (int p = 0; p < 2; p ++) 
                    for (int s = 0; s < 2; s ++) 
                    {
                        if (i == 0 && j == 0) 
                        {
                            dp[i][j][p][s] = (s == 0);
                            continue;
                        }
                        if (p == 0) 
                        {
                            int nw = false;
                            if(i) nw |= dp[i - 1][j][p ^ 1][s];
                            if(j) nw |= dp[i][j - 1][p ^ 1][s ^ 1];
                            dp[i][j][p][s] = nw;
                        } 
                        else 
                        {
                            int nw = false;
                            if(i) nw |= (!dp[i - 1][j][p ^ 1][s]);
                            if(j) nw |= (!dp[i][j - 1][p ^ 1][s]);
                            dp[i][j][p][s] = !nw;
                        }
                    }
                
            
        
        if (dp[cnt0][cnt1][0][0]) puts("Alice");
        else puts("Bob");
    }
}