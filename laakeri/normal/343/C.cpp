#include <iostream>

using namespace std;

typedef long long ll;

int n,m;
ll h[100001];
ll p[100001];

ll abs(ll a){
    if (a<0ll) return -a;
    return a;
}

int test(ll mv){
    int ii=0;
    for (int i=0;i<n;i++){
        ll c;
        if (p[ii]<h[i]) c=h[i]-p[ii];
        else c=0;
        if (c>mv) return 0;
        while (ii<m&&p[ii]<=h[i]){
            ii++;
        }
        while (ii<m&&min(c, p[ii]-h[i])*2ll+max(c, p[ii]-h[i])<=mv){
            ii++;
        }
        if (ii==m) return 1;
    }
    return 0;
}

int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>h[i];
    for (int i=0;i<m;i++) cin>>p[i];
    ll mi=0;
    ll ma=1e13;
    while (mi<=ma){
        ll m=(mi+ma)/2ll;
        if (test(m)){
            ma=m-1ll;
        }
        else{
            mi=m+1ll;
        }
    }
    cout<<mi<<endl;
}