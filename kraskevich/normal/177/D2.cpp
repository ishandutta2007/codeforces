#include <iostream>
using namespace std;

#define ll long long

ll sum[100 * 1000];

ll get(int l, int r)
{
           return sum[r] - (l ? sum[l - 1] : 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m, c;
    
    cin >> n >> m >> c;
    
    ll a[n], b[m];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    for(int i = 0; i < m; ++i)
            cin >> b[i];
    
    for(int i = 0; i < m; ++i)
    {
            sum[i] = b[i];
            if(i)
                 sum[i] += sum[i - 1];
    }
    
    for(int i = 0; i < n; ++i)
    {
            int l, r;
            if(n - i >= m)
                 l = 0;
            else
                l = m - (n - i);
            r = min(i, m - 1);
            
            cout << (get(l, r) + a[i]) % c << " "; 
    }
    
    cin >> n;
    
    return 0;
}