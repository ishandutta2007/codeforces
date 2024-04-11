#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <iterator>
#include <cstdio>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;

int main()
{
    ll d1, d2, d3;
    ll ans = 1LL * inf * inf;
    scanf ( "%I64d%I64d%I64d", &d1, &d2, &d3 );
    ans = min( d1 + d2 + d3, ans );
    ans = min( d1 + d1 + d3 + d3, ans );
    ans = min( d2 + d2 + d3 + d3, ans );
    ans = min( d1 + d1 + d2 + d2, ans );
    printf ( "%I64d", ans );
    return 0;
}