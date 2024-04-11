#include <algorithm>
#include <iostream>
#include <string.h>
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

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

const int N = 2 * 1000 * 1000 + 10;
int p[N];

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        p[i] = i + 1;

    int lo = 0;
    for (int k = 2; k <= n; k++, lo++)
    {
        vector<int> was;
        int hi = lo + n;
        for (int l = lo; l < hi; l += k)
            was.push_back(p[l]);
        int cnt = 0;
        for (int l = lo; l < hi; l += k)
            p[min(hi, l + k)] = was[cnt++];
    }

    for (int i = lo; i < lo + n; ++i)
        cout << p[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}