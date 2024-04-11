#include <iostream>

using namespace std;

typedef long long ll;

ll mod=1000000007;

int main(){
    ll a, b;
    cin>>a>>b;
    ll s=0;
    ll l=b+1ll;
    for (ll i=1;i<=a;i++){
        s+=l;
        l+=b;
        l%=mod;
        s%=mod;
    }
    ll v=0;
    for (ll i=1;i<b;i++){
        v=v+i*s;
        v%=mod;
    }
    cout<<v<<endl;
}