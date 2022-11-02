#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <string.h>
#include <cctype>
#include <fstream>

using namespace std;


//-----TEMPLATE STARTS HERE------//
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, long long> PIL;
typedef pair<long long, int> PLI;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef long double LD;

#define MP make_pair
#define PB push_back
#define hash __hash__
#define left __left__
#define right __right__
#define link __link__
#define div __div__
#define next __next__
#define y0 y1005000
#define y1 y1005001
//-----TEMPLATE ENDS HERE------//
//--ACTUAL SOLUTION IS BELOW---//


const int N = 100 * 1000 + 10;
set<int> g[N];
int n, m;
int p[N];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].insert(b);
        g[b].insert(a);
    }
    for (int rep = 0; rep < 2000; rep++)
    {
        random_shuffle(p, p + n);
        bool ok = true;
        int tot = 0;
        for (int i = 0; i < n && ok && tot < m; i++)
        {
            int p1 = p[i];
            int p2 = p[(i + 1) % n];
            if (g[p1].count(p2))
                ok = false;
            else
                tot++;
        }
        //cerr << rep << endl;
        if (!ok)
            continue;
        for (int i = 0; i < m; i++)
        {
            //cerr << p[i] << " " << p[(i + 1) % n] << endl;
            cout << p[i] + 1 << " " << p[(i + 1) % n] + 1 << endl;
        }
        return 0;
    }
    cout << -1;

    return 0;
}