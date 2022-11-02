#include <iostream>
#include <algorithm>
#define F first
#define S second

using namespace std;

typedef long long ll;

pair<ll, ll> asdf[100001];

int main(){
    ll n,r,a;
    cin>>n>>r>>a;
    ll need=n*a;
    for (int i=0;i<n;i++){
        cin>>asdf[i].S>>asdf[i].F;
        need-=asdf[i].S;
    }
    sort(asdf, asdf+n);
    ll v=0;
    for (int i=0;i<n&&need>0;i++){
        ll w=min(need, r-asdf[i].S);
        v+=w*asdf[i].F;
        need-=w;
    }
    cout<<v<<endl;
}