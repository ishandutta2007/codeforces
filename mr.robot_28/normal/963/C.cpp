#include<bits/stdc++.h>
using namespace std;
#define int long long
map <int, int> mp, mp1;
int gcd(int a, int b)
{
    if(a == 0 ||  b == 0)
    {
        return a + b;
    }
    if(a > b)
    {
        return gcd(a % b, b);
    }
    return gcd(a, b % a);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> x, y;
    int ch = 0;
    vector <int> c(n);
    vector <int> H(n), W(n);
    for(int i = 0; i < n; i++)
    {
        int w, h;
        cin >> w >> h >> c[i];
        x.push_back(w);
        W[i] = w;
        H[i] = h;
        y.push_back(h);
        ch = gcd(ch, c[i]);
    }
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    sort(y.begin(), y.end());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    if(n != x.size() * y.size())
    {
        cout << 0;
        return 0;
    }
    int ans = 0;
    for(int i = 1; i * i <= ch; i++)
    {
        if(ch % i == 0)
        {
            ans++;
            if(i * i != ch)
            {
                ans++;
            }
        }
    }
    int gc = 0;
    for(int i = 0; i < n; i++)
    {
        if(W[i] == W[0])
        {
            gc = gcd(gc, c[i]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(W[i] == W[0])
        {
            mp[H[i]] = c[i] / gc;
        }
    }
    gc = 0;
    for(int i= 0; i < n; i++)
    {
        if(H[i] == H[0])
        {
            gc = gcd(gc, c[i]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(H[i] == H[0])
        {
            mp1[W[i]] = c[i] / gc;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(mp[H[i]] * mp1[W[i]] != c[i] / ch)
        {
            cout << 0;
            return 0;
        }
    }
    cout << ans;
    return 0;
}