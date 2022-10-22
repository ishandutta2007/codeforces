#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 105;

int n, m;
int cnt[N];

bool check(int d) {
    if(!d) return true;
    int hlp = 0;
    for(int i = 0;i < N;i++) {
        hlp += cnt[i] / d;
    }
    return hlp >= n;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;

    for(int x, i = 0;i < m;i++) {
        cin >> x;
        cnt[x]++;
    }

    int bl = 0;
    int br = m + 1;
    int bm;

    while(br - bl > 1) {
        int bm = (bl + br) >> 1;
        if(check(bm)) {
            bl = bm;
        }else {
            br = bm;
        }
    }

    cout << bl << "\n";

    return 0;
}