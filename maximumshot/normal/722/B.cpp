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
    cin >> n;

    string s;
    getline(cin, s);

    vec< int > p(n);
    for(int i = 0;i < n;i++) {
        cin >> p[i];
    }

    getline(cin, s);

    int ok = 1;

    for(int i = 0;i < n;i++) {
        getline(cin, s);
        //cout << s << '\n';
        int cnt = 0;
        for(char c : s) {
            cnt += (c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
                    c == 'u' || c == 'y');
        }
        ok &= cnt == p[i];
    }

    cout << (ok?"YES" : "NO") << "\n";

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