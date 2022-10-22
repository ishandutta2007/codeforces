#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n, k;

    cin >> n >> k;

    vec< string > a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    string s;
    cin >> s;

    int c1 = 0, c2 = 0;

    for(int i = 0;i < n;i++) {
        if(a[i].size() < s.size()) c1++;
        else if(a[i].size() == s.size()) c2++;
    }

    cout << c1 + 1 + (c1 / k) * 5 << ' ' << c1 + c2 + ((c1 + c2 - 1) / k) * 5 << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}