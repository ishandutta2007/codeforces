#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[1010],b[1010],mx=0,c[1010];

void init(int n) {
    for(int i=1;i<=n;i++) {
        a[i]=i;
        b[i]=1;
    }
}

int find(int x) {
    if (a[x]==x) return a[x];
    else return a[x]=find(a[x]);
}

int un(int x,int y) {
    x=find(x);
    y=find(y);
    if (x==y) return 1;
    if (b[x]<b[y]) swap(x,y);
    b[x]+=b[y];
    a[y]=x;
    return 0;
}

map <int,int> q;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,x=0,y;
    cin>>n>>m;
    init(n);
    for(i=0;i<m;i++) {
        cin>>k>>l;
        x+=un(k,l);
        k=0;
        q.clear();
        for(j=1;j<=n;j++) {
            if (!q.count(find(j))) {
                q[find(j)]=1;
                c[k++]=b[find(j)];
            }
        }
        sort(c,c+k);
        mx=0;
        for(j=k-1;j>=max(0,k-1-x);j--) {
            mx+=c[j];
        }
        cout<<mx-1<<endl;
    }
    return 0;
}