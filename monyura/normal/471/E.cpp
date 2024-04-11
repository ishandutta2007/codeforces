#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>
#include <cassert>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;


struct event
{
    int t;
    int x;
    pii other;
    int ind;
    event(){}
    event(int t0, int x0, pii other0, int ind0 = -1)
    {
        t = t0;
        x = x0;
        other = other0;
        ind = ind0;
    }
    bool operator<(const event &b) const
    {
        if (x != b.x)
            return x < b.x;
        return t < b.t;
    }
};

int Fen[400400];
void addFen(int pos, int val, int sz)
{
    pos+=2;
    for (int i = pos; i<sz; i+= i&-i)
        Fen[i] += val;
}

int getFen(int pos)
{
    pos+=2;
    int res = 0;
    for (int i = pos; i>0; i -= i&-i)
        res += Fen[i];
    return res;
}

ll getRes(const vector<pii> &S, const vector<pii> &F)
{
    vector<event> E;
    vector<int> all;
    int n = (int)S.size();
    ll sumlen = 0;
    rep(i,0,n)
    {
        int x0,y0,x1,y1;
        x0 = S[i].first;
        y0 = S[i].second;
        x1 = F[i].first;
        y1 = F[i].second;
        sumlen += abs(x1-x0)+abs(y1-y0);
        all.push_back(y0);
        all.push_back(y1+1);
        if (x0==x1)
        {
            E.push_back(event(0, x0, pii(y0,y1+1)));
        }
        else
        {
            E.push_back(event(1, x1,   pii(y0, 1), i));
            E.push_back(event(1, x0-1, pii(y0, -1), i));
        }
    }
    sort(all(all));
    int fenSize = (int)all.size() + 2;
    rep(i,0,fenSize)
        Fen[i] = 0;
    sort(all(E));
    rep(i,0,E.size())
    {
        E[i].other.first = (int)(lower_bound(all(all), E[i].other.first) - all.begin());
        if (E[i].t == 0)
            E[i].other.second = (int)(lower_bound(all(all), E[i].other.second) - all.begin());
    }
    static vector<int> Res;
    Res.assign(n, 0);
    rep(i,0,(int)E.size())
    {
        if (E[i].t == 0)
        {
            addFen(E[i].other.first, 1, fenSize);
            addFen(E[i].other.second, -1, fenSize);
        }
        else
        {
            Res[E[i].ind] += E[i].other.second * getFen(E[i].other.first);
        }
    }
    ll per = 0;
    rep(i,0,n)
        per += Res[i];
    return sumlen + n - per - 1;
}

struct node
{
    int t;
    int y;
    int x0, x1;
    int ind;
    node(int t0, int y0, int _x0, int _x1, int ind0)
    {
        t = t0;
        y = y0;
        x0 = _x0;
        x1 = _x1;
        ind = ind0;
    }
    bool operator<(const node &b) const
    {
        if (y != b.y)
            return y < b.y;
        return t < b.t;
    }
};

struct setElem
{
    int x0, x1;
    int gInd;
    setElem(){}
    setElem(int _x0, int _x1, int gInd0)
    {
        x0 = _x0;
        x1 = _x1;
        gInd = gInd0;
    }
    bool operator<(const setElem &b) const
    {
        return x0 < b.x0;
    }
};

struct vert
{
    vector<int> inc;
    int id;
    bool was = 0;
} g[300200];

vector<int> verts;
void dfs(int k)
{
    g[k].was = 1;
    verts.push_back(g[k].id);
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        if (!g[to].was)
            dfs(to);
    }
}

void run()
{
    int n;
    cin>>n;
    vector<pii> A,B;
    vector<node> vec;
    rep(i,0,n)
    {
        int x0,y0,x1,y1;
        scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
        A.push_back(pii(x0,y0));
        B.push_back(pii(x1,y1));
        if (x0 == x1)
        {
            vec.push_back(node(0, y0, x0, x1, i));
            vec.push_back(node(2, y1, x0, x1, i));
        }
        else
            vec.push_back(node(1, y0, x0, x1, i));
    }
    sort(all(vec));
    int lastVertId = 0;
    set<setElem> stOtr;
    set<int> stX;
    rep(i,0,vec.size())
    {
        if (vec[i].t == 0 || vec[i].t == 2)
        {
            int currV;
            if (vec[i].t == 0)
            {
                currV = lastVertId++;
                g[currV].id = vec[i].ind;
            }
            else
                stX.erase(vec[i].x0);
            
            auto iter = stOtr.upper_bound(setElem(vec[i].x0, 0, 0));
            if (iter != stOtr.begin())
                --iter;
            if (iter != stOtr.end() && iter->x0 <= vec[i].x0 && vec[i].x0 <= iter->x1)
            {
                auto nxt = stX.upper_bound(vec[i].x0);
                auto prv = stX.lower_bound(vec[i].x0);
                if (prv != stX.begin())
                    --prv;
                int x0 = iter->x0;
                int x1 = iter->x1;
                int v = iter->gInd;
                stOtr.erase(*iter);
                if (prv != stX.end() && x0 <= *prv  && *prv < vec[i].x0)
                    stOtr.insert(setElem(x0, *prv, v));
                if (nxt != stX.end() && vec[i].x0 < *nxt && *nxt <= x1)
                    stOtr.insert(setElem(*nxt, x1, v));
            }
            
            if (vec[i].t == 0)
            {
                stX.insert(vec[i].x0);
                stOtr.insert(setElem(vec[i].x0, vec[i].x0, currV));
            }
        }
        else if (vec[i].t == 1)
        {
int currV = lastVertId++;
                g[currV].id = vec[i].ind;
            auto iter2 = stX.lower_bound(vec[i].x0);
            if (iter2 != stX.end() && *iter2 <= vec[i].x1)
            {
                vector<setElem> toDel;
                auto st = stOtr.lower_bound(setElem(vec[i].x0, 0, 0));
                if (st != stOtr.begin())
                    --st;
                int mn = 2e9;
                int mx = -2e9;
                auto fin = stOtr.upper_bound(setElem(vec[i].x1, 0, 0));
                for (auto it = st; it != fin; ++it)
                {
                    if (it->x1 < vec[i].x0 || it->x0 > vec[i].x1)
                        continue;
                    int to = it->gInd;
                    g[currV].inc.push_back(to);
                    g[to].inc.push_back(currV);
                    mn = min(mn, it->x0);
                    mx = max(mx, it->x1);
                    toDel.push_back(*it);
                }
                rep(i,0,toDel.size())
                stOtr.erase(toDel[i]);
                if (mn <= mx)
                    stOtr.insert(setElem(mn, mx, currV));
            }
        }
    }
    ll res = 0;
    vector<pii> L, R;
    rep(i,0,lastVertId)
    if (!g[i].was)
    {
        verts.clear();
        dfs(i);
        L.clear();
        R.clear();
        rep(j,0,verts.size())
        {
            L.push_back(A[verts[j]]);
            R.push_back(B[verts[j]]);
        }
        ll here = getRes(L,R);
        //cout<<"!"<<here<<endl;
        res = max(res, here);
    }
    cout<<res<<endl;
}

//#define prob "fields"


int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}