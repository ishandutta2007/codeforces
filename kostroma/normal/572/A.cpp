#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int k, m, n1, n2;
    cin >> n1 >> n2 >> k >> m;
    vi a(n1);
    for (int i = 0; i < a.size(); ++i) cin >> a[i];
    vi b(n2);
    for (int i = 0; i < b.size(); ++i) cin >> b[i];
    if (a[k - 1] < b[n2 - m]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}