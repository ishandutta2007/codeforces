#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int a,b,ca,cb;
}edg[500005];
int col[500005];
struct Update {
  int time;
  int sizeIndex;
  int parentIndex;
  int parityIndex;
  int oldSize;
  int oldParent;
  int oldParity;
};
int Time=0;
stack<Update>ops;
int parent[500005];
int sz[500005];
int parity[500005];
pair<int, int> getRoot(int v)
{
    if(v==parent[v] || parent[v]==0)
        return make_pair(v,parity[v]);
    pair<int,int>pc=getRoot(parent[v]);
    return make_pair(pc.first,pc.second xor parity[v]);
}

int join(int u, int v) {
  Time++;
  pair<int,int>pu,pv;
  pu = getRoot(u);
  pv = getRoot(v);
  u=pu.first;
  v=pv.first;
  if (u != v) {
    if (sz[u] < sz[v]) {
      ops.push(Update{Time, v, u, u, sz[v], parent[u], parity[u]});
      sz[v] += sz[u];
      parent[u] = v;
      parity[u] ^= (pu.second xor pv.second xor 1);
    } else {
      ops.push(Update{Time, u, v, v, sz[u], parent[v], parity[v]});
      sz[u] += sz[v];
      parent[v] = u;
      parity[v] ^= (pu.second xor pv.second xor 1);
    }
  }
  else
  {
    if(pu.second==pv.second)
        return 1;
  }
  return 0;
}
void undo(int nops = 1) {
  for (int i = 0; i < nops; i++) {
    while (ops.top().time == Time) {
      sz[ops.top().sizeIndex] = ops.top().oldSize;
      parent[ops.top().parentIndex] = ops.top().oldParent;
      parity[ops.top().parityIndex] = ops.top().oldParity;
      ops.pop();
    }
    Time--;
  }
}
bool cmp (ura a, ura b)
{
    if(a.ca>b.ca)
        return true;
    if(a.ca<b.ca)
        return false;
    return a.cb>b.cb;
}
int ok[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,m,i,t,j=0,k=0;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        cin>>col[i];
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        edg[++j]={a,b,col[a],col[b]};
        if(col[a]==col[b])
            ok[col[a]]|=join(a,b);
        if(col[a]>col[b])
        {
            swap(edg[j].a,edg[j].b);
            swap(edg[j].ca,edg[j].cb);
        }
    }
    sort(edg+1,edg+m+1,cmp);
    ops.push(Update{-99, 1, 1, 1, 1, 1, 1});
    int cntt=0;
    for(i=1;i<=m;++i)
    {
        if(edg[i].ca==edg[i].cb)
            continue;
        if(ok[edg[i].ca] || ok[edg[i].cb])
            continue;
        int cnt=0;
        int rzc=0;
        for(j=i;j<=m;++j)
        {
            if(edg[j].ca!=edg[i].ca || edg[j].cb!=edg[i].cb)
                break;
            if(!rzc)
            {
                ++cnt;
                rzc+=join(edg[j].a,edg[j].b);
            }
        }
        i=j-1;
        if(rzc)
            ++cntt;
        undo(cnt);
    }
    long long cnt=0;
    for(i=1;i<=k;++i)
        if(!ok[i])
            ++cnt;
    cout<<cnt*1LL*(cnt-1)/2LL-cntt;
    return 0;
}