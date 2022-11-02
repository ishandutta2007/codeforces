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


string s;
vector<int> cnt(256, 0);
int n;

bool good(int x)
{
    int tot = 0;
    for (int i = 0; i < 256; i++)
    {
        int cur = cnt[i] / x;
        if (cnt[i] % x)
            cur++;
        tot += cur;
    }
    return tot <= n;
}

void rec(int x)
{
    int tot = 0;
    for (int i = 0; i < 256; i++)
    {
        int cur = cnt[i] / x;
        if (cnt[i] % x)
            cur++;
        for (int j = 0; j < cur; j++)
            cout << char(i);
        tot += cur;
    }
    for (int i = 0; i < n - tot; i++)
        cout << 'a';
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> s;
    cin >> n;
    for (int i = 0; i < s.length(); i++)
        cnt[s[i]]++;
    int diff = 0;
    for (int i = 0; i < 256; i++)
        if (cnt[i])
            diff++;
    if (diff > n)
    {
        cout << -1;
        return 0;
    }
    int l = 1;
    while (!good(l))
        l++;
    cout << l << endl;
    rec(l);

    return 0;
}