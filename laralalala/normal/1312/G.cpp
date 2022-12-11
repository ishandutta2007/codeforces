#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;


struct node{
    int id,pos,l;
    bool imp;
    node *edge[26];
    node() : imp(0),id(0),l(0) { for(int i=0;i<26;i++) edge[i]=0; }
}*root;

#define MAXN 1000005

node *arr[MAXN];
ll p[MAXN],cont,ls[MAXN][2],res[MAXN],n;
ll st[4*MAXN],lazy[4*MAXN];

void push(int p,int l,int r)
{
    if(!lazy[p])
        return ;
    if(l==r)
    {
        lazy[p]=0;
        return ;
    }

    st[p<<1]=min(st[p<<1],lazy[p]);
    st[(p<<1)+1]=min(st[(p<<1)+1],lazy[p]);
    lazy[p<<1]=min(lazy[p<<1],lazy[p]);
    lazy[(p<<1)+1]=min(lazy[(p<<1)+1],lazy[p]);
    lazy[p]=0;
}

void update(int p,int l,int r,int L,int R,ll v)
{
    push(p,l,r);
    if(L<=l && r<=R)
    {
        st[p]=min(st[p],v);
        lazy[p]=min(lazy[p],v);
        return ;
    }
    if(l>R || L>r)
        return ;
    int mid=(l+r)>>1;

    update(p<<1,l,mid,L,R,v);
    update((p<<1)+1,mid+1,r,L,R,v);

    st[p]=min(st[p<<1],st[(p<<1)+1]);
}

ll query(int p,int l,int r,int pos)
{
    push(p,l,r);
    if(l==pos && pos==r)
        return st[p];
    else if(l>pos  ||r <pos)
        return 0;
    int mid=(l+r)>>1;

    return min(query(p<<1,l,mid,pos),query((p<<1)+1,mid+1,r,pos));
}

void dfs(node *u)
{
    if(u->imp)
        cont++;
    u->pos=cont;
    ls[u->id][0]=cont;

    for(int i=0;i<26;i++)
        if(u->edge[i])
            dfs(u->edge[i]);
    ls[u->id][1]=cont;
}

void dfs1(node *u)
{
    if(u->imp)
    {
        res[u->id]=min(res[u->id],query(1,0,MAXN-1,u->pos)+u->pos);
//        db(query(1,0,MAXN-1,u->pos))
//        db(u->pos)
    }
//    cout << u->id << ' ' << res[u->id] << ' ' << u->pos << ' ' << res[u->id]-(u->pos)+(u->imp) << ls[u->id][0] << ls[u->id][1]<< '\n';
    update(1,0,MAXN-1,ls[u->id][0],ls[u->id][1],res[u->id]-(u->pos)+(u->imp));

    for(int i=0;i<26;i++)
        if(u->edge[i])
        {
            res[u->edge[i]->id]=min(res[u->id]+1,res[u->edge[i]->id]);
            dfs1(u->edge[i]);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    root=new node();
    arr[0]=root;

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin >> p[i] >> c;
        int v=c-'a';
        if(!arr[p[i]]->edge[v])
        {
            arr[p[i]]->edge[v]=new node();
            arr[p[i]]->edge[v]->id=i+1;
//            arr[p[i]->edge[v]->l]=(arr[p[i]]->l)+1;
            arr[i+1]=arr[p[i]]->edge[v];
        }
    }

    int k,x;
    cin >> k;
    vector<int> xs;
    for(int i=0;i<k;i++)
    {
        cin >> x;
        xs.push_back(x);
        arr[x]->imp=1;
    }

    dfs(root);

    for(int i=0;i<=n+1;i++)
        res[i]=1e9;
    res[0]=0;
    dfs1(root);

    for(auto y : xs)
        cout << res[y] << ' ';
    cout << '\n';

    return 0;
}