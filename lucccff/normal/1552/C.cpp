#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a[220],b[220],c[220],d[220];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k;
        memset(c,0,sizeof(c));
        for(j=0;j<k;j++) {
            cin>>a[j]>>b[j];
            if (a[j]>b[j]) {
                a[j]+=b[j];
                b[j]=a[j]-b[j];
                a[j]-=b[j];
            }
            c[a[j]]=1;
            c[b[j]]=1;
        }
        l=0;
        for(j=1;j<=2*n;j++) if (c[j]==0) d[l++]=j;
        for(j=0;j<l/2;j++) {
            a[j+k]=d[j];
            b[j+k]=d[j+l/2];
        }
        m=0;
        for(j=0;j<n;j++) {
            for(l=j+1;l<n;l++) {
                if (a[j]<a[l]&&b[j]<b[l]&&(a[l]<b[j]||b[l]<a[j])) m++;
                if (a[j]>a[l]&&b[j]>b[l]&&(a[l]>b[j]||b[l]>a[j])) m++;
            }
        }
        cout<<m<<endl;
    }
    return 0;
}