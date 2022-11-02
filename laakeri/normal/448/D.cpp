#include <iostream>

using namespace std;

typedef long long ll;

ll n,m,k;

ll u(ll x){
    ll r=0;
    ll k=0;
    for (ll i=n;i>0;i--){
        while (i*(k+1)<x&&k+1<=m){
            k++;
        }
        r+=k;
    }
    return r;
}

int main(){
    cin>>n>>m>>k;
    ll h=n*m;
    ll l=1;
    while (h>=l){
        ll m=(h+l)/2;
        //cout <<"m "<<m<<" "<<u(m)<<endl;
        if (u(m)<k){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    cout<<h<<endl;
}