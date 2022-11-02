#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> co;

ll v;
const ll inf=1e16;
int n;
ll t[1010101];
ll sf[1010101];

ll a,b;

void go(ll p){
    sf[n]=0;
    for (int i=n-1;i>=0;i--){
        sf[i]=sf[i+1];
        if (t[i]%p==0){

        }
        else if (t[i]%p==1){
            sf[i]+=b;
        }
        else if(t[i]%p==(p-1)){
            sf[i]+=b;
        }
        else{
            sf[i]=inf;
        }
    }
    v=min(v, sf[0]);
    ll pv=0;
    ll v1=0;
    for (int i=0;i<n;i++){
        if (t[i]%p==0){

        }
        else if (t[i]%p==1){
            pv+=b;
        }
        else if(t[i]%p==(p-1)){
            pv+=b;
        }
        else{
            pv=inf;
        }
        v1=min(v1+a, pv);
        v=min(v, v1+sf[i+1]);
    }
}

set<ll> tt;

void test(ll k){
    for (ll i=2;i*i<=k;i++){
        if (k%i==0){
            tt.insert(i);
            k/=i;
        }
        while (k%i==0){
            k/=i;
        }
    }
    if (k>1) tt.insert(k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>a>>b;
    v=(n-1)*a;
    for (int i=0;i<n;i++){
        cin>>t[i];
    }
    tt.insert(2);
    test(t[0]);
    test(t[0]+1);
    test(t[0]-1);
    test(t[n-1]);
    test(t[n-1]-1);
    test(t[n-1]+1);
    for (ll aa:tt){
        go(aa);
    }
    cout<<v<<endl;
}