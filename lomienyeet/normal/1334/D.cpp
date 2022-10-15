#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
long long N,L,R;
long long ps[MAXN];
long long go(long long u){
    if(u>ps[N-1])return 1;
    auto it=lower_bound(ps+1,ps+N,u)-ps;
    int goo=u-ps[it-1];
    if(goo%2==1)return it;
    else return goo/2+it;
}
signed main(){
    long long T;
    cin>>T;
    while(T--){
        cin>>N>>L>>R;
        for(long long i=1;i<=N;i++)ps[i]=ps[i-1]+2*(N-i);
        for(long long i=L;i<=R;i++)cout<<go(i)<<" ";
        cout<<"\n";
    }
}