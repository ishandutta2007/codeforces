#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //i agree this is just my code directly from hkoj
    ll N,lptr=0,rptr=0,sum=0;
    cin>>N;
    vector<ll> l(N),r(N);
    for(ll i=0;i<N;i++){
        cin>>l[i]>>r[i];
        sum+=(l[i]*l[i]+r[i]*r[i]);
    }
    lptr=accumulate(l.begin(),l.end(),0LL);
    rptr=accumulate(r.begin(),r.end(),0LL);
    cout<<sum*N-(lptr*lptr+rptr*rptr)<<"\n";
}