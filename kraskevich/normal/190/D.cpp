#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long i64;
#define pii pair<int, int>
#define F first
#define S second

int a[1000 * 1000];
pii b[1000 * 1000];
int f[1000 * 1000];
const int inf = 1000 * 1000;
int n, k;

void init()
{
     for(int i = 0; i < 1000 * 1000; ++i)
             f[i] = inf;
}

bool cmp(pii p, pii q)
{
     return p.F < q.F || (p.F == q.F && p.S < q.S);
}

int main()
{
    init();
    
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
            cin >> a[i];
            b[i].F = a[i];
            b[i].S = i;
    }
    
    sort(b, b + n, cmp);
      
    int l = 0;
    for(int i = 0; i < n; ++i)
    {
            if(i == n - 1 || b[i].F != b[i + 1].F)
            {
                 int r = i;
                 if(r - l + 1 < k)
                 {
                               l = i + 1;
                               continue;
                 }
                 for(int j = l; j + k - 1 <= r; ++j)
                         f[b[j].S] = min(f[b[j].S], b[j + k - 1].S);
                 l = i + 1;
            }
    }
    for(int i = n - 2; i >= 0; --i)
            f[i] = min(f[i], f[i + 1]);
    
    i64 ans = 0;
    for(int i = 0; i < n; ++i)
    {
            if(f[i] == inf)
                    continue;
            ans += i64(n - f[i]);
    }
    
    cout << ans << endl;
    
    cin >> n;
    
    return 0;
}