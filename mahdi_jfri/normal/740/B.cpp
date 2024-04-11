#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
ll sum[maxn] , a[maxn] , ans[maxn] , c , d , res;
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i] , sum[i] = sum[i - 1] + a[i];
    for(int i = 0; i < m; i++)
    {
        cin >> c >> d;
        c--; d--;
        ans[i] = sum[d] - sum[c - 1];
    }
    sort(ans , ans + m);
    for(int i = m - 1; i > -1; i--)
    {
        if(ans[i] > 0)
            res += ans[i];
    }
    cout << res;
}