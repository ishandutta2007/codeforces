#include <iostream>
using namespace std;

#define ll long long
ll f[250 * 1000];

ll prf(ll a[], int n)
{
           ll s = a[0];
           ll ans = s;
           for(int i = 1; i < n; ++i)
           {
                   s += a[i];
                   ans = max(ans, s);
           }
           return ans;
}

ll sff(ll a[], int n)
{
           ll s = a[n - 1];
           ll ans = s;
           for(int i = n - 2; i >= 0; --i)
           {
                   s += a[i];
                   ans = max(ans, s);
           }
           return ans;
}

ll bst(ll a[], int n)
{
           ll s = a[0];
           ll ans = s;
           s = max(s, 0ll);
           for(int i = 1; i < n; ++i)
           {
                   s += a[i];
                   ans = max(ans, s);
                   if(s < 0)
                        s = 0;
           }
           return ans;
}

ll al(ll a[], int n)
{
          ll s = 0;
          for(int i = 0; i < n; ++i)
                   s += a[i];
          return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    
    cin >> n >> m;
    
    ll all[n], pref[n], suff[n], best[n];
    for(int i = 0; i < n; ++i)
    {
            int l;
            cin >> l;
            ll a[l];
            for(int j = 0; j < l; ++j)  
                    cin >> a[j];
            
            pref[i] = prf(a, l);
            suff[i] = sff(a, l);
            best[i] = bst(a, l);
            all[i] = al(a, l);
    }
    
    int ind[m];
    
    for(int i = 0; i < m; ++i)
    {
            cin >> ind[i];
            --ind[i];
    }
        
    ll ans = best[ind[0]];
    f[0] = max(0ll, suff[ind[0]]);
    for(int i = 1; i < m; ++i)
    {
            int cur = ind[i];
            ans = max(ans, f[i - 1] + pref[cur]);
            ans = max(ans, best[cur]);
            f[i] = max(suff[cur], f[i - 1] + all[cur]);
            ans = max(ans, f[i]);
            f[i]= max(f[i], 0ll);
    }
    
    cout << ans;
    
    cin >> n;
    
    return 0;
}