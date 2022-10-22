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

    int n;
    string s;
    cin >> n >> s;

    vec< int > res;

    for(int i = 0;i < n;i++) {
        if(s[i] == 'W') continue;
        int j = i;
        while(j < n && s[j] == 'B') j++; j--;
        res.push_back(j - i + 1);
        i = j;
    }

    cout << (int)res.size() << '\n';
    for(int x : res) cout << x << ' ';
    cout << '\n';

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