#include <bits/stdc++.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {

    int n, m;

    scanf("%d %d", &n, &m);

    int cs, cc;
    cs = cc = 0;

    vec< char > str(n + 1), col(n + 1);

    for(int x, y, i = 0;i < m;i++) {
        scanf("%d %d", &x, &y);
        if(!str[x]) cs++, str[x] = 1;
        if(!col[y]) cc++, col[y] = 1;
        printf("%I64d\n", 1ll * n * n - 1ll * n * (cs + cc) + 1ll * cs * cc);
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}