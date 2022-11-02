#include <iostream>
#include <vector>
using namespace std;

vector <int> a, b, k, p;
int r;
const long long INF = (long long)1e18;
long long best = -INF;

void upd()
{
    long long ans = 0;
    
    for(int i = 0; i < a.size(); ++i)
        ans += a[i] * k[i];
    
    if(ans > best)
        best = ans;
}

void go(int cur, int all, bool xr)
{ 
    if((all - cur) % 2 == 0)
        upd();
    if(all == cur)
        return;
        
    vector <int> t = a;
    
    for(int i = 0; i < a.size(); ++i)
        a[i] = t[p[i]] + r;
    go(cur + 1, all, false);
    a = t;
    
    if(!xr)
    {
        for(int i = 0; i < a.size(); ++i)
            a[i] = (t[i] ^ b[i]);
        go(cur + 1, all, true);
        a = t;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, all;
    cin >> n >> all >> r;
    
    a.resize(n);
    b.resize(n);
    p.resize(n);
    k.resize(n);
    
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    for(int i = 0; i < n; ++i)
        cin >> k[i];
    for(int i = 0; i < n; ++i)
    {
        cin >> p[i];
        --p[i];
    }
    
    go(0, all, false);
    
    cout << best << endl;
    
    return 0;
}