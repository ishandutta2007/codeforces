#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int nn[300000];

int main(){
    ll n;
    cin>>n;
    map<ll,ll> lol;
    set<ll> lol2;
    ll ma=0;
    ll mi=1e9;
    for (int i=0;i<n;i++){
        ll a;
        cin>>a;
        lol[a]++;
        ma=max(a,ma);
        mi=min(a,mi);
        lol2.insert(a);
    }
    ll d=ma-mi;
    if (d==0){
        cout<<d<<" "<<n*(n-1)/2<<endl;
        return 0;
    }
    ll v=lol[mi]*lol[ma];
    cout<<d<<" "<<v<<endl;
}