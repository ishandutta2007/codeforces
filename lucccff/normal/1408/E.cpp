#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int fa[200010],size1[200010];

void init(int n) {
    for(int i=1;i<=n;i++) {
        fa[i]=i;
        size1[i]=1;
    }
}

int find(int x) {
    if (fa[x]!=x) return fa[x]=find(fa[x]);
    else return fa[x];
}

void uni(int x,int y) {
    int xx=find(x),yy=find(y);
    if (xx==yy) return ;
    if (size1[xx]>size1[yy]) {
        fa[yy]=xx;
        size1[xx]+=size1[yy];
    }
    else {
        fa[xx]=yy;
        size1[yy]+=size1[xx];
    }
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,ans=0;
    long long a[100010],b[100010];
    pair <int,pair<int,int>> p[200010];
    cin>>m>>n;
    for(i=1;i<=m;i++) {
        cin>>a[i];
    }
    for(i=1;i<=n;i++) {
        cin>>b[i];
    }
    t=0;
    for(i=1;i<=m;i++) {
        cin>>k;
        for(j=0;j<k;j++) {
            cin>>l;
            p[t++]=make_pair(-a[i]-b[l],make_pair(i,l+m));
            ans+=a[i]+b[l];
        }
    }
    sort(p,p+t);
    init(t);
    
    for(i=0;i<t;i++) {
        k=p[i].second.first;
        l=p[i].second.second;
        if (find(k)!=find(l)) {
            ans+=p[i].first;
            uni(k,l);
        }
    }
    cout<<ans;

    return 0;
}