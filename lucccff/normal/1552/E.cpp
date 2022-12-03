#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,y;
    long long a[10010],b[110][110],c[110],d[110][2],e[110];
    cin>>n>>k;
    memset(c,0,sizeof(c));
    memset(e,0,sizeof(e));
    for(i=0;i<n*k;i++) {
        cin>>a[i];
        b[a[i]][c[a[i]]++]=i;
    }
    for(i=1;i<=n;i+=k-1) {
        for(j=1;j<k&&j+i-1<=n;j++) {
            m=n*k;
            for(l=i;l<i+k-1&&l<=n;l++) {
                if (m>b[l][j]&&e[l]==0) {
                    m=b[l][j];
                    y=l;
                }
            }
            e[y]=1;
            d[y][0]=b[y][j-1]+1;
            d[y][1]=b[y][j]+1;
        }
    }
    for(i=1;i<=n;i++) {
        cout<<d[i][0]<<' '<<d[i][1]<<endl;
    }
    return 0;
}