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

    int d = 0;
    int len = 0;
    int cnt = 0;

    for(int i = 0;i < n;i++) {
        if(s[i] == '(') d++;
        else if(s[i] == ')') d--;
        else if(s[i] != '_') {
            int j = i;
            while(j < n && (s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z')) j++; j--;
            if(d == 0) len = max(len, j - i + 1);
            else cnt++;
            i = j;
        }
    }

    cout << len << ' ' << cnt << '\n';  

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