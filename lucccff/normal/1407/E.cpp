#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    srand(time(0));
    long long i,j,k,l,m,n,x,y,z,t=1;
    long long a[500010],b[500010],c[500010];
    vector <int> e[500010],f[500010];
    cin>>n>>m;
    for(i=0;i<m;i++) {
        cin>>k>>l>>x;
        if (x==0) e[l].push_back(k);
        else f[l].push_back(k);
    }
    x=0;
    y=1;
    a[x]=n;
    memset(b,-1,sizeof(b));
    memset(c,0,sizeof(c));
    c[n]=1;
    b[n]=1;
    k=0;
    if (n==1) {
        cout<<0<<endl<<0;
        return 0;
    }
    while(x<y&&t) {
        k++;
        z=y;
        for(i=x;i<y;i++) {
            for(j=0;j<e[a[i]].size();j++) {
                l=e[a[i]][j];
                if (b[l]==-1) {
                    b[l]=1;
                }
                else if (b[l]==0&&c[l]==0) {
                    a[z++]=l;
                    c[l]=1;
                    if (l==1) t=0;
                }
            }
        }
        for(i=x;i<y;i++) {
            for(j=0;j<f[a[i]].size();j++) {
                l=f[a[i]][j];
                if (b[l]==-1) {
                    b[l]=0;
                }
                else if (b[l]==1&&c[l]==0) {
                    a[z++]=l;
                    c[l]=1;
                    if (l==1) t=0;
                }
            }
        }
        x=y;
        y=z;
    }
    for(i=1;i<=n;i++) {
        if (b[i]==-1) b[i]=rand()&1;
    }
    if (t==0) cout<<k<<endl;
    else cout<<-1<<endl;
    for(i=1;i<=n;i++) {
        cout<<b[i];
    }
    return 0;
}