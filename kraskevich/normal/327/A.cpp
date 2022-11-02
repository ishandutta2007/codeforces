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

using namespace std;

#define PII pair<int, int>
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define div __div__
#define hash __hash__
#define prev __prev__
#define left __left__
#define right __right__
#define link __link__
#define next __next__

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VII;



int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    VI a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++)
        {
            VI b = a;
            for (int i = l; i <= r; i++)
                b[i] = 1 - b[i];
            int s = 0;
            for (int i = 0; i < n; i++)
                s += b[i];
            res = max(res, s);
        }
    cout << res;

    return 0;
}