#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s,p,q;
    long long a[300010],b[300010],c[300010],d[300010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m;
        for(j=0;j<n;j++) b[j]=0;
        for(j=0;j<n;j++) {
            cin>>a[j];
            b[(j+1-a[j]+n)%n]++;
        }
        k=0;
        for(j=0;j<n;j++) {
            if ((n-b[j])<=2*m) {
                for(l=0;l<n;l++) {
                    d[l]=0;
                }
                s=0;
                for(l=0;l<n;l++) {
                    if ((l+1-a[l]+n)%n!=j&&d[l]==0) {
                        d[l]=1;
                        p=(a[l]-1+j+n)%n;
                        while(p!=l) {
                            d[p]=1;
                            p=(a[p]-1+j+n)%n;
                            s++;
                        }
                    }
                }
                if (s<=m) c[k++]=j;
            }
        }
        cout<<k<<' ';
        for(j=0;j<k;j++) {
            cout<<c[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}