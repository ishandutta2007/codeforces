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

    string s;
    cin >> s;

    for(int i = 0;i + 25 < (int)s.size();i++) {
        vec< int > cnt(26);
        for(int j = i;j < i + 26;j++) {
            if(s[j] != '?') cnt[s[j] - 'A']++;
        }
        int ok = 1;
        for(int j = 0;j < 26;j++) {
            if(cnt[j] > 1) ok = 0;
        }
        if(ok) {
            for(int cur = 0, j = i;j < i + 26;j++) {
                if(s[j] == '?') {
                    while(cur < 26 && cnt[cur] == 1) cur++;
                    s[j] = cur++ + 'A';
                }
            }
            for(int j = i + 26;j < (int)s.size();j++) if(s[j] == '?') s[j] = 'A';
            for(int j = i - 1;j >= 0;j--) if(s[j] == '?') s[j] = 'A';
            cout << s << '\n';
            return true;
        }
    }

    cout << "-1\n";

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