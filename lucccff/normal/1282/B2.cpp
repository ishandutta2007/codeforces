#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,p,s;
    long long a[200010],b[200010],c[200010],d[200010],e[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>p>>k;
        for(j=1;j<=n;j++) {
            cin>>a[j];
        }
        l=0;
        a[0]=0;
        sort(a+1,a+n+1);
        for(j=0;j<k;j++) {
            l+=a[j];
            e[j]=l;
            b[j]=0;
            c[j]=-2;
            d[j]=0;
        }
        s=0;
        for(j=k;j<=n;j++) {
            if (d[j%k]==0) b[j%k]+=a[j];
            if (b[j%k]>p&&d[j%k]==0) {
                c[j%k]=(j/k-1)*k;
                b[j%k]-=a[j];
                d[j%k]=1;
            }
        }
        for(j=0;j<k;j++) {
            if (c[j]==-2) {
                c[j]=(n-j)/k*k;
            }
            l=upper_bound(e+1,e+j+1,p-b[j])-e-1;
            c[j]+=l;
        }
        m=0;
        for(j=0;j<k;j++) {
            if (c[j]>m) m=c[j];
        }
        cout<<m<<endl;
    }
    return 0;
}