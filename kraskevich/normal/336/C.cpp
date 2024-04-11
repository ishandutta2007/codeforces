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

#define double long double

const int N = 100 * 1000 + 10;
int a[N];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for (int b = 30; b >= 1; --b)
    {
        vector<int> t;
        for (int i = 0; i < n; i++)
            if (a[i] & (1 << b))
                t.push_back(a[i]);
        if (!t.size())
            continue;
        int x = t[0];
        for (auto v: t)
            x = (x & v);
        if (x % (1 << b) == 0)
        {
            cout << t.size() << endl;
            for (int i = 0; i < t.size(); i++)
                cout << t[i] << " ";
            return 0;
        }
    }
    vector<int> bt;
    for (int b = 30; b >= 0; --b)
    {
        vector<int> t;
        for (int i = 0; i < n; i++)
            if (a[i] & (1 << b))
                t.push_back(a[i]);
        if (!t.size())
            continue;
        if (t.size() > bt.size())
            bt = t;
    }
    cout << bt.size() << endl;
    for (int i = 0; i < bt.size(); i++)
        cout << bt[i] << " ";


    return 0;
}