#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long inv(long long a){
    long long m=MOD;
    if(a == 1)return 1;
    return inv(m%a)*(m-m/a)%m;
}

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    long long a[200010],c[200010];
    pair <int,int> b[200010];
    cin>>n>>k;
    for(i=0;i<n;i++) {
        cin>>l;
        a[l]=i;
    }
    a[n]=-1;
    for(i=0;i<n;i++) {
        b[i]=make_pair(a[i],a[i+1]);
    }
    sort(b,b+n);
    t=0;
    for(i=0;i<n-1;i++) {
        if (b[i].second<b[i+1].second) c[i]=0;
        else c[i]=1;
        t+=c[i];
    }
    m=k-t-1;
    if (m<0) {
        cout<<0;
    }
    else {
        l=1;
        for(i=n+1;i<=m+n;i++) {
            l=l*i%MOD;
        }
        j=1;
        for(i=1;i<=m;i++) {
            j=j*i%MOD;
        }
        l=l*inv(j)%MOD;
        cout<<l;
    }

    return 0;
}