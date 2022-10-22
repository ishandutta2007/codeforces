#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    string s;
    cin >> s;

    map< char, int > cnt;

    for(auto c : s) cnt[c]++;

    int res = inf;

    res = min(res, cnt['B']);
    res = min(res, cnt['u'] / 2);
    res = min(res, cnt['l']);
    res = min(res, cnt['b']);
    res = min(res, cnt['a'] / 2);
    res = min(res, cnt['s']);
    res = min(res, cnt['r']);

    cout << res << "\n";

    return 0;
}