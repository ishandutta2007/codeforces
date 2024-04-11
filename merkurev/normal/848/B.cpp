#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

int sz[2];
const int X = (int) 1e5;
const int N = (int) 3e5;

struct Pers
{
    int g, p, t, id;
    Pers() : g(), p(), t(), id() {}
    Pers(int _g, int _p, int _t, int _id) : g(_g), p(_p), t(_t), id(_id) {}

    void read(int _id)
    {
        id = _id;
        scanf("%d%d%d", &g, &p, &t);
        if (p > X || t > X) throw;
        g--;
    }

    void print() const
    {
        printf("%d %d\n", p, t);
    }

    int getGroup() const
    {
        return p - t + X + 10;
    }

    Pers getEnd() const
    {
        if (g == 0)
            return Pers(3, p, sz[1], id);
        return Pers(2, sz[0], p, id);
    }

    bool operator < (const Pers &A) const
    {
        if (g != A.g) return g > A.g;
        
        if (p != A.p)
        {
            if (g == 1 || g == 2) return p > A.p;
            return p < A.p;
        }
        if (g == 1 || g == 2) return t > A.t;
        return t < A.t;
    }
};

set <Pers> S;
map <int, vector <Pers> > persM;
Pers ans[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, w, h;
    scanf("%d%d%d", &n, &w, &h);
    if (n > X || w > X || h > X) throw;
    sz[0] = w;
    sz[1] = h;

    for (int i = 0; i < n; i++)
    {
        Pers P;
        P.read(i);
        if (S.count(P) ) throw;
        S.insert(P);
        int grId = P.getGroup();
        persM[grId].push_back(P);
    }

    for (auto PP : persM)
    {
        vector <Pers> pers = PP.second;
        vector <Pers> pnds;
        
        sort(pers.begin(), pers.end() );
        for (auto P : pers) pnds.push_back(P.getEnd() );
        sort(pnds.begin(), pnds.end() );
       
        for (int j = 0; j < (int) pers.size(); j++)
            ans[pers[j].id] = pnds[j];
    }

    for (int i = 0; i < n; i++)
        ans[i].print();


	return 0;
}