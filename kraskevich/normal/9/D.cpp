#include <iostream>
using namespace std;

typedef long long i64;
i64 f[100][100];
i64 u[100][100];

i64 getf(int n, int h)
{
    if(n == 0 && h == 0)
         return 1;
    if(h == 0)
         return 0;
    if(n < h)
         return 0;
    if(n < 0 || h < 0)
         return 0;  
    if(u[n][h])
               return f[n][h];
    
    f[n][h] = 0;
    u[n][h] = 1;
    for(int sl = 0; sl <= n; ++sl)
            for(int hl = 0; hl < h; ++hl)
                    for(int sr = 0; sr <= n; ++sr)
                            for(int hr = 0; hr < h; ++hr)  
                                    if(sl + sr + 1 == n && (hl == h - 1 || hr == h - 1))
                                          f[n][h] += getf(sl, hl) * getf(sr, hr); 
   return f[n][h];
}

void init()
{
     for(int i = 0; i < 100; ++i)
             for(int j = 0; j < 100; ++j)
                     f[i][j] = u[i][j] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, h;
    cin >> n >> h;
    
    init();
    
    i64 ans = 0;
    for(int i = h; i <= n; ++i)
            ans += getf(n, i);
    
    cout << ans;
    
    cin >> n;
    
    return 0;
}