#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>

using namespace std;

#define PII pair<int, int>
#define PLL pair<long long, long long>
#define PIL pair<int, long long>
#define PLI pair<long long, int>
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define div __dv__
#define hash __hash__
#define prev __prev__
#define left __left__
#define right __right__
#define link __link__
#define next __next__
#define y0 y100500_0
#define y1 y100500_1
#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 111;

int g[N][3][3];

int getg(int n, int m1, int m2)
{
    if (n == 0)
        return 0;
    if (g[n][m1][m2] >= 0)
        return g[n][m1][m2];
    int &res = g[n][m1][m2];
    bool used[n][2];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            used[i][j] = 0;
    if (m1 == 1)
        used[0][0] = 1;
    if (m1 == 2)
        used[0][1] = 1;
    if (m2 == 1)
        used[n - 1][0] = 1;
    if (m2 == 2)
        used[n - 1][1] = 1;
    /*cerr << n << " " << m1 << " " << m2 << endl;
    for (int i = 0; i < n; i++)
        cerr << used[i][0] << used[i][1] << endl;*/
    set<int> was;
    res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
        {
            if (used[i][j])
                continue;
            int upn = i;
            int upm1 = 2 - j;
            int upm2 = m1;
            int lon = n - i - 1;
            int lom1 = 2 - j;
            int lom2 = m2;
            was.insert(getg(upn, upm1, upm2) ^ getg(lon, lom1, lom2));
        }
    while (was.count(res))
        res++;
    //cerr << res << endl;
    return res;
}

bool field[N][2];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    for (int i = 0; i < N; i++)
        for (int m1 = 0; m1 < 3; m1++)
            for (int m2 = 0; m2 < 3; m2++)
                g[i][m1][m2] = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            field[i][j] = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        field[a][b] = 1;
        for (int j = max(0, a - 1); j <= min(a + 1, n - 1); j++)
            field[j][1 - b] = 1;
    }
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cerr << field[i][j];
        }
        cerr << endl;
    }*/
    int res = 0;
    for (int i = 0; i < n;)
    {
        if (field[i][0] == 1 && field[i][1] == 1)
        {
            i++;
            continue;
        }
        int upm = 0;
        if (field[i][0])
            upm = 1;
        if (field[i][1])
            upm = 2;
        int s = i;
        while (i < n && (field[i][0] == 0 || field[i][1] == 0))
            i++;
        i--;
        int size = i - s + 1;
        int lom = 0;
        if (field[i][0])
            lom = 1;
        if (field[i][1])
            lom = 2;
        //cerr << size << " " << upm << " " << lom << endl;
        cerr << getg(size, upm, lom) << endl;
        res ^= getg(size, upm, lom);
        i++;
    }
    if (res)
        cout << "WIN";
    else
        cout << "LOSE";

    return 0;
}