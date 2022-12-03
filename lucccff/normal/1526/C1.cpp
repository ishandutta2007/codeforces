#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i,j,k,l,m,n,a[2010],c[2010];
    pair <long long,int> b[2010];
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }

    k=0;
    l=0;
    c[0]=0;
    for(i=0;i<n;i++) {
        if (a[i]>=0) k+=a[i];
        else b[l++]=make_pair(a[i],i);
        c[i+1]=k;
    }
    sort(b,b+l);
    for(i=l-1;i>=0;i--) {
        k=b[i].second;
        m=b[i].first;
        int f=0;
        for(j=k+1;j<=n;j++) {
            if (c[j]+m<0) {
                f=1;
                break;
            }
        }
        if (!f) {
            l--;
            for(j=k+1;j<=n;j++) {
                c[j]+=m;
            }
        }
    }
    cout<<n-l;
}