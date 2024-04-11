#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<ll> qu;
struct seg
{
     ll s, e;
}Seg[200010];

int main()
{
    ll n, h,sum = 0,cnt=0,ans=0;
    cin >> n >> h;
    for(int i=0; i<n; i++) cin >> Seg[i].s >> Seg[i].e;
    Seg[n].s = 2100000000;
    for(int i=0; i<n; i++)
    {
        if(cnt<i) cnt = i;
        while(sum+Seg[cnt+1].s-Seg[cnt].e<h)
        {
            sum += Seg[cnt+1].s-Seg[cnt].e;
            qu.push(cnt++);
        }
        ans = max(ans,Seg[cnt].e+h-sum-Seg[i].s);
        if(!qu.empty())
        {
            ll x =qu.front();
            qu.pop();
            sum -= Seg[x+1].s-Seg[x].e;
        }
    }
    cout << ans;
}