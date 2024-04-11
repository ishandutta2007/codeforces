#include <iostream>

using namespace std;

typedef long long ll;

ll mod=1000000009;

ll pot(ll a, ll p){
    if (p==0) return 1;
    if (p==2) return (a*a)%mod;
    if (p%2==0) return pot(pot(a, p/2), 2);
    return (a*pot(a, p-1))%mod;
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll d=n-m;
    ll a=k-1;
    ll v=min(m, a*d);
    m-=a*d;
    if (m<0) m=0;
    v+=k*pot(2, m/k+1);
    v%=mod;
    v+=mod*k-k*2;
    v+=m%k;
    v%=mod;
    cout<<v<<endl;
}