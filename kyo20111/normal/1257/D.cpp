#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M ((l+r)>>1)
int t,n,m,a[200200],p[200200],s[200200],pw[200200],tree[800200];
void build(int node,int l,int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    build(node*2, l, M);
    build(node*2+1, M+1, r);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}
int f(int node,int l,int r,int nl,int nr){
    if(r<nl || nr<l) return 0;
    if(nl<=l && r<=nr) return tree[node];
    return max(f(node*2, l, M, nl, nr), f(node*2+1, M+1, r, nl, nr));
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        build(1,1,n);
        scanf("%d",&m);
        for(int i=1;i<=m;i++) scanf("%d %d",p+i,s+i);
        for(int i=1;i<=m;i++) pw[s[i]] = max(pw[s[i]], p[i]);
        for(int i=n;i>=1;i--) pw[i] = max(pw[i], pw[i+1]);

        if(pw[1] < tree[1]){
            printf("-1\n");
            for(int i=1;i<=n;i++) pw[i]=0;
            continue;
        }

        int ans = 0, u = 1;
        while(u <= n){
            int l=u,r=n;
            while(l<=r){
                int mid = f(1,1,n,u,M);
                if(mid <= pw[M-u+1]) l = M+1;
                else r = M-1;
            }
            u = l;
            ans++;
        }

        printf("%d\n",ans);
        for(int i=1;i<=n;i++) pw[i] = 0;
    }
}