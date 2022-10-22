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

    vec< int > u(300);

    int n;
    scanf("%d", &n);

    char s[100100];

    scanf("%s", &s);

    int res = inf;

    for(int i = 0;i < n;i++) {
        u[s[i]] = 1;
    }

    int all = count(ALL(u), 1);

    u.assign(300, 0);

    for(int cur = 0, j = 0, i = 0;i < n;i++) {
        if(!u[s[i]]) u[s[i]] = 1, cur++;
        else u[s[i]]++;
        while(j < i && u[s[j]] > 1) u[s[j++]]--;
         if(cur == all) res = min(res, i - j + 1);
    }

    printf("%d\n", res);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}