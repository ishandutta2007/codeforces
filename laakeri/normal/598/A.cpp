#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tcs;
    cin>>tcs;
    for (int tc=0;tc<tcs;tc++){
        ll n;
        cin>>n;
        ll v=n*(n+1ll)/2ll;
        for (ll i=0;(1ll<<i)<=n;i++){
            v-=2ll*(1<<i);
        }
        cout<<v<<'\n';
    }
}