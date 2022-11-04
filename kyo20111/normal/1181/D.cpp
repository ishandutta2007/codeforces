#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,ans[505050],cn[505050];
ll cnt,tree[2020202];
pair<ll,int> o[505050];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
void up(int node,int l,int r,int id){
    if(id<l || r<id) return;
    if(l==r){
        tree[node] = 1;
        return;
    }
    up(node*2,l,(l+r)/2,id);
    up(node*2+1,(l+r)/2+1,r,id);
    tree[node] = tree[node*2]+tree[node*2+1];
}
int f(int node,int l,int r,ll val){
    if(l==r) return l;
    if(tree[node*2] >= val) return f(node*2,l,(l+r)/2,val);
    return f(node*2+1,(l+r)/2+1,r,val-tree[node*2]);
}
int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        int a; scanf("%d",&a);
        cn[a]++;
    }
    for(int i=1;i<=m;i++) pq.push({cn[i],i});
    for(int i=1;i<=q;i++) scanf("%lld",&o[i].first);
    for(int i=1;i<=q;i++) o[i].second = i;
    for(int i=1;i<=q;i++) o[i].first -= n;
    sort(o+1,o+1+q);

    int fl=pq.top().first;
    while(!pq.empty() && pq.top().first == fl){
        up(1,1,m,pq.top().second);
        pq.pop();
    }

    for(int i=1;i<=q;i++){
        while(!pq.empty() && o[i].first > cnt + (pq.top().first - fl) * tree[1]){
            cnt += (pq.top().first - fl) * tree[1];
            fl = pq.top().first;
            while(!pq.empty() && pq.top().first == fl){
                up(1,1,m,pq.top().second);
                pq.pop();
            }
        }

        ans[o[i].second] = f(1,1,m,(o[i].first-cnt-1)%tree[1]+1);
    }

    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
}