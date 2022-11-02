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
#include <sstream>
#include <unordered_set>

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
#define F first
#define S second
//-----TEMPLATE ENDS HERE------//
//--ACTUAL SOLUTION IS BELOW---//


const int N = 300 * 1000 + 10;

int a[N], pos[N];
int val[N], f[N];
int n, q;

void add(int i, int by)
{
    for (; i < N; i = (i | (i + 1)))
        f[i] += by;
}

void put(int i, int x)
{
    if (val[i] == x)
        return;
    add(i, x - val[i]);
    val[i] = x;
}

int sum(int i)
{
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        res += f[i];
    return res;
}

int sum(int l, int r)
{
    return sum(r) - sum(l - 1);
}

void ins(int i)
{
    if (i < 0 || i >= n)
        return;
    if (i < n - 1 && pos[i] > pos[i + 1])
        put(i, 1);
    else
        put(i, 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    fill(f, f + N, 0);
    fill(val, val + N, 0);
    for (int i = 0; i < n; i++)
        ins(i);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int type, l, r;
        cin >> type >> l >> r;
        --l;
        --r;
        if (type == 1)
        {
            cout << sum(l, r - 1) + 1 << "\n";
        }
        else
        {
            swap(pos[a[l]], pos[a[r]]);
            swap(a[l], a[r]);
            ins(a[l]);
            ins(a[r]);
            ins(a[l] - 1);
            ins(a[l] + 1);
            ins(a[r] - 1);
            ins(a[r] + 1);
        }
    }

    return 0;
}