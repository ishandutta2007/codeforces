#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[1010][1010],n,b[1010][1010],c[1010][1010];

int low_bit(int x) {
    return x&-x;
}

void add(int t, int x, int k) {
    while(x<=n) {
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
    int i,j,k,l,m,t,k1,p;
    cin>>n>>m>>k1;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            cin>>b[i][j];
        }
    }
    for(j=1;j<=m;j++) {
        i=n;
        k=0;
        l=n+1;
        while(i>0) {
            p=0;
            add(j,i+1,-1);
            while(i>0&&b[i][j]==2) {
                k++;
                add(j,i,-1);
                i--;
                p=1;
            }
            add(j,i+1,k+1);
            k=0;
            c[l][j]=i;
            l=i;
            i--;
        }
    }
    for(i=1;i<=k1;i++) {
        cin>>k;
        l=1;
        while(l<=n) {
            l=l+getsum(k,l);
            if (l>n) break;
            t=b[l][k];
            b[l][k]=2;
            p=l+1+getsum(k,l+1);
            add(k,c[l][k]+1,p-l);
            add(k,l+1,-p+l);
            c[p][k]=c[l][k];
            if (t==1) k++;
            else k--;
        }
        cout<<k<<' ';
    }
    return 0;
}