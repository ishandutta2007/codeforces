#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
    
typedef long long LL;
    
int a[100010],b[100010],c[100010];
    
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,p,s,f;
    cin>>n>>p;
    k=1;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++) {
        k=max(k,a[i]-i);
    }
    s=1;
    for(i=0;i<n;i++) {
        b[max(0,a[i]-k)]++;
    }
    t=n;
    f=n;
    for(i=n-1;i>=0;i--) {
        s=max(s-1,t);
        if (s>=p) f=i;
        t-=b[i];
    }
    for(i=n-1;i>=0;i--) {
        if (b[i]>=p) break;
    }
    m=0;
    if (i>=0) {
        cout<<0<<endl;
    }
    else {
        l=0;
        for(i=0;i<f;i++) {
            l+=b[i];
            if (l<p) c[m++]=i+k;
            else break;
        }
        cout<<m<<endl;
        for(i=0;i<m;i++) {
            cout<<c[i]<<' ';
        }
    }
    return 0;
}