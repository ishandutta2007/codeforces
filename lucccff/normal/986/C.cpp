#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[5000010],b[5000010],c[5000010];
int f[5000010],s[5000010];

void init(int n) {
    for(int i=0;i<(1<<n);i++) {
        f[i]=i;
        s[i]=1;
    }
}

int find(int x) {
    if (x==f[x]) return x;
    else return f[x]=find(f[x]);
}

void un(int x,int y) {
    x=find(x);
    y=find(y);
    if (s[x]<s[y]) swap(x,y);
    f[y]=x;
    s[x]+=s[y];
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    cin>>n>>m;
    init(n);
    for(i=0;i<m;i++) {
        cin>>k;
        a[k]=1;
    }
    for(i=0;i<(1<<n);i++) b[i]=-1;
    for(i=0;i<(1<<n);i++) {
        if (a[i]) b[i]=i;
        for(j=0;j<n;j++) {
            if (i&(1<<j)) {
                if (b[i-(1<<j)]>=0) {
                    if (b[i]>=0) {
                        b[i]=min(b[i],b[i-(1<<j)]);
                    }
                    else {
                        b[i]=b[i-(1<<j)];
                    }
                }
            }
        }
        /*if (a[(1<<n)-1-i]) {
            b[i]=1;
            un(i,(1<<n)-1-i);
        }
        for(j=0;j<n;j++) {
            if (i&(1<<j)) {
                if (b[i-(1<<j)]) {
                    b[i]=1;
                    un(i,i-(1<<j));
                }
            }
        }*/
    }
    for(i=0;i<(1<<n);i++) {
        if (a[i]) {
            if (b[(1<<n)-1-i]>=0) {
                un(i,b[(1<<n)-1-i]);
                c[(1<<n)-1-i]=1;
            }
        }
    }
    for(i=(1<<n)-1;i>=0;i--) {
        if (c[i]) for(j=0;j<n;j++) {
            if (i&(1<<j)) {
                c[i-(1<<j)]=1;
            }
        }
    }
    for(i=0;i<(1<<n);i++) {
        if (c[i]&&b[i]>=0) for(j=0;j<n;j++) {
            if (i&(1<<j)) {
                if (b[i-(1<<j)]>=0&&b[i-(1<<j)]!=b[i]) {
                    un(b[i],b[i-(1<<j)]);
                }
            }
        }
    }
    m=0;
    for(i=0;i<(1<<n);i++) {
        if (a[i]) b[m++]=find(i);
    }
    sort(b,b+m);
    int ans=0;
    for(i=0;i<m;i++) {
        j=i+1;
        while(j<m&&b[j]==b[j-1]) j++;
        i=j-1;
        ans++;
    }
    cout<<ans;
    return 0;
}