#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

long long w;

long long mex(long long a,long long b,long long c) {
    if (min(a,min(b,c))!=0) return 0;
    else if (a!=1&&b!=1&&c!=1) return 1;
    else if (a!=2&&b!=2&&c!=2) return 2;
    else return 3;  
}

long long f(long long k) {
    if (k<=2000) return k;
    else return (k%w+1500/w*w);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x,y,z,s,ans;
    long long a[2010][3],b[300010];
    cin>>t;
    while(t--) {
        cin>>n>>x>>y>>z;
        memset(a,0,sizeof(a));
        for(i=1;i<=2000;i++) {
            k=a[max(0ll,i-x)][0];
            l=a[max(0ll,i-y)][1];
            m=a[max(0ll,i-z)][2];
            a[i][0]=mex(k,l,m);
            a[i][1]=mex(k,10,m);
            a[i][2]=mex(k,l,10);
        }
        s=0;
        w=(max(x,max(y,z))+min(x,min(y,z)))*(x+y+z-max(x,max(y,z)))*(x+y+z-min(x,min(y,z)));
        for(i=0;i<n;i++) {
            cin>>k;
            b[i]=k;
            s^=a[f(k)][0];
        }
        ans=0;
        for(i=0;i<n;i++) {
            s^=a[f(b[i])][0];
            if ((s^a[f(max(b[i]-x,0ll))][0])==0) ans++;
            if ((s^a[f(max(b[i]-y,0ll))][1])==0) ans++;
            if ((s^a[f(max(b[i]-z,0ll))][2])==0) ans++;
            s^=a[f(b[i])][0];
        }
        cout<<ans<<endl;
    }
    return 0;
}