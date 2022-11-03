#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;ll n,m;
inline ll judge(ll x1, ll y1, ll x2, ll y2){
    ll x = x2 - x1 + 1, y = y2 - y1 + 1;
    ll res = x * y / 2;
    if(x * y % 2 == 1 && (x1 + y1) % 2 == 0) res++;
    return res;
}

inline ll check(ll x1, ll y1, ll x2,ll y2,ll x3,ll y3,ll x4,ll y4){
    if(x2 < x3 || x1 > x4 || y2 < y3 || y1 > y4) return 0;
    ll X1 = max(x1, x3), X2 = min(x2, x4), Y1 = max(y1, y3), Y2 = min(y2, y4);
    return (X2 - X1 + 1) * (Y2 - Y1 + 1) - judge(X1, Y1, X2, Y2);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    while(t--){
        cin>>n>>m;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll ans = judge(1, 1, n, m);
        ans += (x2 - x1 + 1) * (y2 - y1 + 1) - judge(x1, y1, x2, y2);
        ans -= check(x1, y1, x2, y2, x3, y3, x4, y4) + judge(x3, y3, x4, y4);
        cout<<ans<<' '<<n*m-ans<<endl;
    }
    return 0;
}