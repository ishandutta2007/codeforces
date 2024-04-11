#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll d[202020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,s;
    cin>>n>>s;
    ll su=0;
    for (int i=0;i<n;i++){
        cin>>d[i];
        su+=d[i];
    }
    for (int i=0;i<n;i++){
        ll l=1;
        ll r=d[i];
        ll osu=su-d[i];
        if (osu<s){
            l=s-osu;
        }
        r=min(r, s-(n-1ll));
        cout<<l-1ll+(d[i]-r)<<" ";
    }
}