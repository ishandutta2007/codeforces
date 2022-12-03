#include <bits/stdc++.h>
using namespace std;

int a[100010],h[100010],ans,leaf[100010];
vector <int> e[100010];

int dfs(int k,int l) {
    int f=0,j=0;
    h[k]=l;
    for(int i=0;i<a[k];i++) {
        if (h[e[k][i]]==-1) {
            if (!dfs(e[k][i],l+1)) {
                j++;
            }
            f=1;
        }
    }
    if (j>1) ans-=j-1;
    leaf[k]=f;
    return f;
}

int main(){
    long long i,j,k,l,m,n,x,y;
    cin>>n;
    memset(a,0,sizeof(a));
    memset(h,-1,sizeof(h));
    ans=n-1;
    for(i=1;i<n;i++) {
        cin>>k>>l;
        a[k]++;
        a[l]++;
        e[k].push_back(l);
        e[l].push_back(k);
    }
    for(i=1;i<=n;i++) {
        if (a[i]>1) break;
    }
    dfs(i,0);
    x=y=0;
    for(i=1;i<=n;i++) {
        if (!leaf[i]) if (h[i]&1) x=1;
        else y=1;
    }
    if (x&y) cout<<3<<' ';
    else cout<<1<<' ';
    cout<<ans;

    return 0;
}