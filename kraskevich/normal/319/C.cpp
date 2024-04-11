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

const int N = 100 * 1000 + 10;

LL dp[N], K[N], B[N];
LL a[N], b[N];
int n;
int st[N];
int sz = 0;

double inter(LL k1, LL b1, LL k2, LL b2)
{
    return (b2 - b1) / (double)(k1 - k2);
}

bool bad(int l, int m, int r)
{
    double xm = inter(K[l], B[l], K[m], B[m]);
    double xr = inter(K[l], B[l], K[r], B[r]);
    return xr <= xm;
}

LL get(int l, int r)
{
    return dp[l] + b[l] * a[r];
}

void add(int i)
{
    while (sz >= 2 && bad(st[sz - 2], st[sz - 1], i))
        sz--;
    st[sz++] = i;
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
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    dp[0] = 0;
    K[0] = b[0];
    B[0] = dp[0];
    add(0);
    int p = 0;
    for (int i = 1; i < n; i++)
    {
        if (p >= sz)
            p = sz - 1;
        while (p < sz - 1 && get(st[p], i) >= get(st[p + 1], i))
            p++;
        dp[i] = get(st[p], i);
        K[i] = b[i];
        B[i] = dp[i];
        add(i);
    }
    cout << dp[n - 1];

    return 0;
}