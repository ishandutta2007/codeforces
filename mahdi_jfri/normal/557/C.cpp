#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const int maxl = 1e5;
const ll inf = ~(1 << 31);
ll _min = inf, sum[maxn] , l[maxn] , t[maxn] , s[maxn] , a , ts[maxn];
vector<int> d[210];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> l[i] , t[l[i]]++;;
    for(int i = 0; i < n; i++)
        cin >> a , s[l[i]] += a , d[a].pb(l[i]);
    for(int i = 1; i <= 200; i++)
        sort(d[i].begin() , d[i].end());
    for(int i = 0; i <= 1e5; i++)
        sum[i] = sum[i - 1] + s[i] , ts[i] = ts[i - 1] + t[i];
    for(int i = 1; i <= 1e5; i++)
    {
        if(!t[i])
            continue;
        ll res = 0;
        ll m = n - (ts[maxl] - ts[i]);
        res = sum[maxl] - sum[i];
      //  cout << sum[maxl] << " " << sum[i] << endl;
   /*     if(t[i] == 1)
        {
            res = sum[maxl];
            res -= s[i];
        }
        else*/
        for(int j = 1; t[i] <= m / 2 && m != t[i] && j <= 200; j++)
        {
            int k = lower_bound(d[j].begin() , d[j].end() , i)-d[j].begin();
            res += k * j;
            m -= k;
            if(t[i] > m / 2)
            {
                bool x = 0;
                while(t[i] > m / 2)
                    m++ , res -= j , x = 1;
                if(x)
                    m-- , res += j;
            }
        }
   //     cout << res << " " << i << endl;
        _min = min(_min , res);
    }
    cout << _min;
}