/*
    Author: MarX
    School: UH
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef long long int64;
typedef pair<int,int> pii;

const int oo = 1 << 30;
const double EPS = 1e-7;            
const int MAXN = 3 * ((int)1e5) + 10;

int F[MAXN];
int C[MAXN];
int D[MAXN];

int getFather(int a)
{
    return (F[a] == a) ? a : F[a] = getFather(F[a]);
}

vi ady[MAXN];
bool P1[MAXN];
bool P2[MAXN];

bool join(int a, int b)
{
    int fa = getFather(a), fb = getFather(b);
    if (fa == fb)
        return false;
    else
    {
        int nd = max(D[fa],D[fb]);
        nd = max(nd,(D[fa] + 1) / 2 + (D[fb] + 1) / 2 + 1);

        if (C[fa] > C[fb])
        {
            C[fa]++;
            F[fb] = fa;
            D[fa] = nd;
        }
        else
        {
            C[fb]++;
            F[fa] = fb;
            D[fb] = nd;
        }
        return true;
    }
}

pii farthest(int a, bool *P)
{
    pii ans = pii(a,0);
    P[a] = true;
    for (int i = 0; i < ady[a].size(); ++i)
    {
        int nx = ady[a][i];
        if (!P[nx])
        {
            pii f = farthest(nx,P);
            if (f.second + 1 > ans.second)
                ans = pii(f.first,f.second + 1);
        }
    }
    return ans;
}

int getDiameter(int n)
{
    pii f1 = farthest(n,P1);
    pii f2 = farthest(f1.first,P2);
    return f2.second;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n,m,q;
    cin >> n >> m >> q;

    for (int i = 0; i <= n; ++i)
        F[i] = i;

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        join(a,b);
        ady[a].push_back(b);
        ady[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!P1[i])
            D[getFather(i)] = getDiameter(i);
    }

    for (int i = 0; i < q; ++i)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int r;
            cin >> r;
            cout << D[getFather(r)] << endl;
        }
        else
        {
            int a,b;
            cin >> a >> b;
            join(a,b);
        }
    }

    return 0;
}