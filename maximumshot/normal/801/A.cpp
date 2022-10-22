#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int get(string s) {
    int res = 0;
    for(int i = 0;i + 1 < (int)s.size();i++) {
        if(s[i] == 'V' && s[i + 1] == 'K') {
            res++;
        }
    }
    return res;
}

int main() {

    string s;

    cin >> s;

    int res = get(s);

    for(int i = 0;i < (int)s.size();i++) {
        s[i] = s[i] == 'V' ? 'K' : 'V';
        res = max(res, get(s));
        s[i] = s[i] == 'V' ? 'K' : 'V';
    }

    cout << res << "\n";

    return 0;
}