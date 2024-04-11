#include <bits/stdc++.h>

using namespace std;

#define FOR(i, p, n) for (int i = (int)(p); i < (int)(n); ++i)
#define FORD(i, p, n) for (int i = (int)(p); i >= (int)(n); --i)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define RE scanf
#define WR printf
#define SKP scanf("%*c")

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

// 1 3 2
// 2 1
// 1 2
// 1 1 2

int total = 0;
int n;

char ask(int i, int j) {
    total++;
    if(total > (3 * ((n + 1) / 2)) - 2) exit(1);
    cout << "? " << i << " " << j << endl;
    char res;
    cin >> res;
    return res;
}

void solve() {
    total = 0;
    cin >> n;
    if(n == 1) {
        cout << "! 1 1" << endl;
        return;
    }
    int mn, mx;
    if(ask(1, 2) == '<') mn = 1, mx = 2;
    else mn = 2, mx = 1;
    for(int i = 3;i < n;i += 2) {
        int cur_mn, cur_mx;
        if(ask(i, i + 1) == '<') cur_mn = i, cur_mx = i + 1;
        else cur_mn = i + 1, cur_mx = i;
        if(ask(cur_mn, mn) == '<') mn = cur_mn;
        if(ask(cur_mx, mx) == '>') mx = cur_mx;
    }
    if(n % 2) {
        if(ask(n, mn) == '<') mn = n;
        if(ask(n, mx) == '>') mx = n;
    }
    cout << "! " << mn << " " << mx << endl;
}

int main() {

    int T;
    cin >> T;

    while(T--) solve();

    return 0;
}