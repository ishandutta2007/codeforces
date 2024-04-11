#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,q,x,f=0;
    long long a[100010],b[100010],c[100010],p[100010];
    long long st[100010],g[100010];
    long long e[100010][20],d[100010][20];
    cin>>n>>q;
    c[0]=0;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        c[i]=c[i-1]+a[i];
    }
    e[0][0]=0;
    d[0][0]=0;
    for(i=1;i<=n;i++) {
        cin>>b[i];
        a[i]=b[i]-a[i];
        c[i]=c[i-1]+a[i];
        e[i][0]=c[i];
        d[i][0]=c[i];
    }
    for(j=1,x=1;(x<<1)<=n+1;x<<=1,j++) {
        for(i=0;i<=n;i++) {
            if (i+x<=n) {
                e[i][j]=max(e[i][j-1],e[i+x][j-1]);
                d[i][j]=min(d[i][j-1],d[i+x][j-1]);
            }
            else {
                e[i][j]=e[i][j-1];
                d[i][j]=d[i][j-1];
            }
        }
    }
    for(i=0;i<q;i++) {
        cin>>k>>l;
        m=0;
        x=1;
        while(x<=l-k+2) {
            m++;
            x<<=1;
        }
        m--;
        x>>=1;
        if (c[k-1]>min(d[k-1][m],d[l-x+1][m])||c[k-1]!=c[l]) {
            cout<<-1<<endl;
        }
        else {
            cout<<max(e[k-1][m],e[l-x+1][m])-c[k-1]<<endl;
        }
    }
    return 0;
}