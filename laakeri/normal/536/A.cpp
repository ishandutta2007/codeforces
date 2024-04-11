#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll a,b;

ll v(ll x){
    return x*a+b*(x*(x-1ll))/2ll;
}

ll sum(ll l, ll r){
    if (l==1) return v(r);
    return v(r)-v(l-1);
}

ll test(int l, int r, ll m){
    if (r<l) return 0;
    if (m>(r-l+1ll)) m=(r-l+1ll);
    return max(a+(r-1ll)*b, sum(l, r)/m+(sum(l, r)%m>0));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>a>>b>>n;
    for (int i=0;i<n;i++){
        ll l,t,m;
        cin>>l>>t>>m;
        ll aa=l-1;
        ll bb=1e6;
        while (aa<=bb){
            ll mid=(aa+bb)/2;
            if (test(l, mid, m)<=t){
                aa=mid+1;
            }
            else{
                bb=mid-1;
            }
        }
        if (bb>=l) cout<<bb<<'\n';
        else cout<<-1<<'\n';
    }
}