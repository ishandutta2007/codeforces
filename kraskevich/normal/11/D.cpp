#include <iostream>
using namespace std;

typedef long long i64;

const int maxN = 19;
i64 f[1 << maxN][maxN];
bool g[maxN][maxN];
int cnt[1 << maxN];
int fbit[1 << maxN];

int bit(int mask, int n)
{
    return ((mask & (1 << n)) ? 1 : 0);
}

int count(int mask)
{
    int res = 0;
    for(int i = 0; i < maxN; ++i)
            res += bit(mask, i);
    return res;
}

int first(int mask)
{
    for(int i = 0; i < maxN; ++i)
            if(bit(mask, i))
                         return i;
}

void init()
{
     for(int i = 0; i < maxN; ++i)
             for(int j = 0; j < maxN; ++j)
                     g[i][j] = false;
     for(int i = 0; i < (1 << maxN); ++i)
             for(int j = 0; j < maxN; ++j)
                     f[i][j] = 0;
     for(int i = 0; i < maxN; ++i)
             f[1 << i][i] = 1;
     for(int i = 0; i < (1 << maxN); ++i)
     {
             cnt[i] = count(i);
             fbit[i] = first(i);
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    init();
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i)
    {
            int a, b;
            cin >> a >> b;
             --a, --b;
             g[a][b] = g[b][a] = true;
    }
    
    for(int mask = 1; mask < (1 << n); ++mask)
            if(cnt[mask] >= 2)
                for(int i = 0; i < n; ++i)
                        if(bit(mask, i) == 1 && i != fbit[mask])
                            for(int j = 0; j < n; ++j)
                                    if(g[i][j])
                                               f[mask][i] += f[mask  ^ (1 << i)][j];
    
    i64 ans = 0;
    for(int mask = 1; mask < (1 << n); ++mask)
            if(cnt[mask] >= 3)
                for(int i = 0; i < n; ++i)
                        if(g[fbit[mask]][i])
                                     ans += f[mask][i];
    
    cout << ans / 2;
    
    cin >> n;
    
    return 0;
}