#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll
const int maxn = 2e5 + 20;
int n , m , k , x , s;
int c[maxn] , d[maxn] , a[maxn] , b[maxn];
ll _min = 4e18;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> x >> s;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    a[0] = x;
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    for(int i = 0; i < k; i++)
        cin >> c[i];
    for(int i = 0; i < k; i++)
        cin >> d[i];
    for(int i = 0; i <= m; i++)
    {
        int xx = a[i];
        if(b[i] > s)
            continue;
        int z = ((upper_bound(d , d + k, s - b[i]))-d);
        if(z == 0)
            _min = min(_min , (ll)xx * n);
        else
            _min = min(_min ,(ll) xx * (n - c[z - 1]));
    }
    cout << _min;
}