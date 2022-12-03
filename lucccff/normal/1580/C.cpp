#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[111][111];
int c[200010],b[200010];
int d[200010],g[200010],f[200010];
vector <int> e[200010];

int low_bit(int x) {
    return x&-x;
}

void add(int t, int x, int k) {
    while(x<=t) {
        a[t][x]=a[t][x]+k;
        x=x+low_bit(x);
    }
}

int getsum(int k,int l) {
    int ans=0;
    while(l>=1) {
        ans+=a[k][l];
        l-=low_bit(l);
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,x,y,z;
    cin>>n>>m;
    for(i=1;i<=n;i++) {
        cin>>b[i]>>c[i];
    }
    for(i=1;i<=m;i++) {
        cin>>k>>l;
        g[i]=l;
        e[l].push_back(i);
    }
    for(i=1;i<=n;i++) {
        if (e[i].size()&1) {
            e[i].push_back(m+1);
        }
        if (b[i]+c[i]>110) {
            for(j=0;j<e[i].size();j+=2) {
                for(k=e[i][j];k<e[i][j+1];k+=b[i]+c[i]) {
                    if (k+b[i]<e[i][j+1]) {
                        d[k+b[i]]++;
                    }
                    if (k+b[i]+c[i]<e[i][j+1]) {
                        d[k+b[i]+c[i]]--;
                    }
                }
                if (k-c[i]<e[i][j+1]) d[e[i][j+1]]--;
            }
        }
    }
    for(i=1;i<=m;i++) {
        l=i;
        if (b[g[i]]+c[g[i]]<=110) {
            if (f[g[i]]) {
                x=b[g[i]];
                y=c[g[i]];
                z=x+y;
                add(z,(f[g[i]]+x-1)%z+1,-1);
                if ((f[g[i]]+x-1)%z<(f[g[i]]-1)%z) {
                    add(z,(f[g[i]]-1)%z+1,1);
                }
                else {
                    add(z,1,-1);
                    add(z,(f[g[i]]-1)%z+1,1);
                }
                f[g[i]]=0;
            }
            else {
                f[g[i]]=i;
                x=b[g[i]];
                y=c[g[i]];
                z=x+y;
                add(z,(f[g[i]]+x-1)%z+1,1);
                if ((f[g[i]]+x-1)%z<(f[g[i]]-1)%z) {
                    add(z,(f[g[i]]-1)%z+1,-1);
                }
                else {
                    add(z,1,1);
                    add(z,(f[g[i]]-1)%z+1,-1);
                }
            }
        }
        d[i]+=d[i-1];
        k=d[i];
        for(j=1;j<=110;j++) {
            k+=getsum(j,(i-1)%j+1);
        }
        cout<<k<<endl;
    }
    return 0;
}