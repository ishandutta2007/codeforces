#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, P[mn], q, L[mn], R[mn];
const int lgmn=22;

int lvret[mn];
vector <int> LL[mn];

int lv(int u)
{
    if (lvret[u]>-1) return lvret[u];
    if (u==1) return lvret[u]=0;
    return lvret[u]=lv(P[u])+1;
}

//buildLCA
int anc[lgmn][mn];
void initLCA()
{
    for (int l=0; l<lgmn; l++) for (int i=0; i<mn; i++) anc[l][i]=-1;
    for (int i=2; i<=n; i++) anc[0][i]=P[i];

    for (int l=1; l<lgmn; l++) 
        for (int i=1; i<=n; i++) if (anc[l-1][i]!=-1) 
            anc[l][i]=anc[l-1][anc[l-1][i]];
}

int LCA(int u, int v)
{
    if (u==-1) return v;
    if (v==-1) return u;
    // cerr<<u<<' '<<v<<"\n";
    if (lv(u)>lv(v)) return LCA(v, u);
    if (lv(u)<lv(v))
    {
        int l=log2(lv(v)-lv(u));
        while (l>-1)
        {
            if (anc[l][v]>0) if (lv(anc[l][v])>=lv(u))v=anc[l][v];
            l--;
        }
    }

    // cerr<<"lca: "<<u<<" "<<lv(u)<<" "<<v<<" "<<lv(v)<<"\n";

    if (u==v) return u;

    int l=log2(lv(v));
    while (l>-1)
    {
        if (anc[l][u]!=anc[l][v]) u=anc[l][u], v=anc[l][v];
        l--;
    }

    return P[u];
}

class lcaSegTree{
private:
    int ST[mn*4];
    void UPD(int id, int l, int r, int u, int g)
    {
        if (u<l || u>r) return;
        if (l==r)
        {
            ST[id]=g;
            return;
        }

        int mid=(l+r)/2;
        UPD(id*2, l, mid, u, g);
        UPD(id*2+1, mid+1, r, u, g);
        ST[id]=LCA(ST[id*2], ST[id*2+1]);
    }

    int GET(int id, int l, int r, int u, int v)
    {
        if (u>r || v<l) return -1;
        if (u<=l && r<=v) return ST[id];

        int mid=(l+r)/2;
        int r1=GET(id*2, l, mid, u, v);
        int r2=GET(id*2+1, mid+1, r, u, v);
        if (r1==-1) return r2;
        else if (r2==-1) return r1;
        else return LCA(r1, r2); 
    }
public:
    lcaSegTree()
    {
        for (int i=0; i<mn*4; i++) ST[i]=-1;
    }

    void update(int u, int g)
    {
        UPD(1, 1, n, u, g);
    }

    int get(int l, int r)
    {
        return GET(1, 1, n, l, r);
    }
} ST1;

class maxSegTree{
private:
    pii ST[mn*4];
    void UPD(int id, int l, int r, int u, int g)
    {
        if (u<l || u>r) return;
        if (l==r)
        {
            ST[id]={g, u};
            return;
        }

        int mid=(l+r)/2;
        UPD(id*2, l, mid, u, g);
        UPD(id*2+1, mid+1, r, u, g);
        ST[id]=max(ST[id*2], ST[id*2+1]);
    }

    pii GET(int id, int l, int r, int u, int v)
    {
        if (u>r || v<l) return {-inf, -inf};
        if (u<=l && r<=v) return ST[id];

        int mid=(l+r)/2;
        pii r1=GET(id*2, l, mid, u, v);
        pii r2=GET(id*2+1, mid+1, r, u, v);
        return max(r1, r2);
    }
public:
    maxSegTree()
    {
        for (int i=0; i<mn*4; i++) ST[i]={-inf, -inf};
    }

    void update(int u, int g)
    {
        UPD(1, 1, n, u, g);
    }

    pii get(int l, int r)
    {
        return GET(1, 1, n, l, r);
    }
}ST2;

class minSegTree{
private:
    pii ST[mn*4];
    void UPD(int id, int l, int r, int u, int g)
    {
        if (u<l || u>r) return;
        if (l==r)
        {
            ST[id]={g, u};
            return;
        }

        int mid=(l+r)/2;
        UPD(id*2, l, mid, u, g);
        UPD(id*2+1, mid+1, r, u, g);
        ST[id]=min(ST[id*2], ST[id*2+1]);
    }

    pii GET(int id, int l, int r, int u, int v)
    {
        if (u>r || v<l) return {inf, inf};
        if (u<=l && r<=v) return ST[id];

        int mid=(l+r)/2;
        pii r1=GET(id*2, l, mid, u, v);
        pii r2=GET(id*2+1, mid+1, r, u, v);
        return min(r1, r2);
    }
public:
    minSegTree()
    {
        for (int i=0; i<mn*4; i++) ST[i]={inf, inf};
    }

    void update(int u, int g)
    {
        UPD(1, 1, n, u, g);
    }

    pii get(int l, int r)
    {
        return GET(1, 1, n, l, r);
    }
}ST3;

int pos[mn];
int cnt=0;
void DFS(int u)
{
    pos[u]=++cnt;
    for (int v: LL[u]) DFS(v);

}

int getAns(int l, int r, int u)
{
    if (u==l) return ST1.get(u+1, r);
    if (u==r) return ST1.get(l, u-1);
    return LCA(ST1.get(l, u-1), ST1.get(u+1, r));
}

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    P[1]=-1;
    for (int i=2; i<=n; i++) 
    {
        cin>>P[i];
        LL[P[i]].push_back(i);
    }
    for (int i=1; i<=q; i++) cin>>L[i]>>R[i];

    for (int i=0; i<mn; i++) lvret[i]=-1;
    initLCA();
    
    DFS(1);
    for (int i=1; i<=n; i++) ST1.update(i, i);
    for (int i=1; i<=n; i++) ST2.update(i, pos[i]), ST3.update(i,pos[i]);

    for (int i=1; i<=q; i++)
    {
        pii u=ST2.get(L[i], R[i]);
        pii v=ST3.get(L[i], R[i]);

        int tu=getAns(L[i], R[i], u.YY);
        int tv=getAns(L[i], R[i], v.YY);

        if (lv(tu)>lv(tv)) cout<<u.YY<<" "<<lv(tu)<<"\n";
        else cout<<v.YY<<' '<<lv(tv)<<"\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/