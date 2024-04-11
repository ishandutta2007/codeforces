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
#define int unsigned
#define mn 200005
#define inf 2222222222
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, m, A[mn];

int findAns(vector <int> V)
{
    int ret=inf;
    for (int i=0; i<V.size(); i++) for (int j=i+1; j<V.size(); j++) if (V[i]+V[j]<ret)
    {
        int tmp=1;
        while (tmp<=V[i])
        {
            if (V[i]/tmp%10 != 0 && V[j]/tmp%10!=0) 
            {
                ret=V[i]+V[j];
                break;
            }
            tmp*=10;
        }
    }
    return ret;
}

class segmentTree{
private:
    pii ST[mn*4];
    int N;

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
        if (v<l || u>r) return {inf, 0};
        if (u<=l && r<=v) return ST[id];

        int mid=(l+r)/2;
        pii ret1=GET(id*2, l, mid, u, v);
        pii ret2=GET(id*2+1, mid+1, r, u, v);

        return min(ret1, ret2);
    }
public:
    segmentTree()
    {
        for (int i=0; i<mn*4; i++) ST[i]={inf, 0};
    }

    void update(int u, int g)
    {
        UPD(1, 1, N, u, g);
    }

    pii get(int u, int v)
    {
        return GET(1, 1, N, u, v);
    }

    void renew()
    {
        N=n;
        for (int i=1; i<=n; i++) update(i, A[i]);
    }

    vector <int> get11(int l, int r)
    {
        vector <int> ret={};
        vector <int> pos={};
        int sz=min(10u, r-l+1);
        for (int i=0; i<sz; i++)
        {
            pii temp=get(l, r);
            ret.push_back(temp.XX);
            pos.push_back(temp.YY);
            update(temp.YY, inf);
        }
        for (int i=0; i<sz; i++)
        {
            update(pos[i], ret[i]);
        }

        return ret;
    }
};

segmentTree st1;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>A[i];
    st1.renew();

    int c, u, v;
    while (m--)
    {
        cin>>c>>u>>v;
        if (c==1)
        {
            st1.update(u, v);
            A[u]=v;
        }
        else
        {
            vector <int> vans=st1.get11(u, v);
            int ans=findAns(vans);
            if (ans==inf) cout<<"-1\n";
            else cout<<ans<<"\n";
        }       
    }

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/