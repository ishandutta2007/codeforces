#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,arr[nmax];
long long pref[nmax];
long long compr[nmax],n_=0;
pair<long long/*coef*/,long long/*free*/> tree[4*nmax];
set<int> seen;
void prec()
{
for(int i=1;i<=n;i++)
    seen.insert(arr[i]);
for(auto k:seen)
{
    n_++;
    compr[n_]=k;
}

}
long long eval(pair<long long/*coef*/,long long/*free*/> l,long long x)
{
    return x*l.first+l.second;
}
long long query(int node,int l,int r,int x)
{
    if(l==r)return eval(tree[node],x);
    int av=(l+r)/2;
    long long ret=eval(tree[node],x);
    if(x<=compr[av])ret=max(ret,query(node*2,l,av,x));
    else ret=max(ret,query(node*2+1,av+1,r,x));
    return ret;
}
void update(int node,int l,int r,pair<long long/*coef*/,long long/*free*/>now)
{
    long long node_l=eval(now,compr[l]),node_r=eval(now,compr[r]);
    long long tree_l=eval(tree[node],compr[l]),tree_r=eval(tree[node],compr[r]);
    if(node_l>=tree_l&&tree_r<=node_r)
    {
    tree[node]=now;
    return;
    }

    if(node_l<=tree_l&&tree_r>=node_r)return;
    int av=(l+r)/2;

    long long node_av=eval(now,compr[av]),tree_av=eval(tree[node],compr[av]);

    if(tree_l>=node_l&&tree_av>=node_av){update(node*2+1,av+1,r,now);return;}
    if(tree_l>=node_l&&tree_av<=node_av){update(node*2,l,av,tree[node]);tree[node]=now;return;}

    if(tree_l<=node_l&&tree_av<=node_av){update(node*2+1,av+1,r,tree[node]);tree[node]=now;return;}
    if(tree_l<=node_l&&tree_av>=node_av){update(node*2,l,av,now);return;}

    assert(0==1);
}
long long bigger()
{
    for(int i=0;i<4*nmax;i++)
        tree[i]={0,-1e18};
    long long ans=0;
    for(int i=n;i>=1;i--)
    {
        long long val=pref[i]-1LL*i*arr[i]+query(1,1,n_,arr[i]);
        ans=max(ans,val);
        update(1,1,n_,{i,-pref[i]});
    }
    return ans;
}
long long smaller()
{
    for(int i=0;i<4*nmax;i++)
        tree[i]={0,-1e18};
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long val=pref[i-1]-1LL*i*arr[i]+query(1,1,n_,arr[i]);
        ans=max(ans,val);
        update(1,1,n_,{i,-pref[i-1]});
    }
    return ans;
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    scanf("%i",&arr[i]);
    pref[i]=arr[i]+pref[i-1];
}
long long ans=0;
for(int i=1;i<=n;i++)
    ans=ans+1LL*i*arr[i];

prec();
long long add=max(bigger(),smaller());
printf("%lld\n",ans+add);
return 0;
}