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

bool solve() {

    int n, c;
    scanf("%d %d", &n, &c);

    vec< vec< int > > a(n);

    for(int l, i = 0;i < n;i++) {
        scanf("%d", &l);
        a[i].resize(l);
        for(int j = 0;j < l;j++) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }

    vec< pii > seg;

    for(int i = 0;i + 1 < n;i++) {
        int lcp = 0;
        while(lcp < (int)a[i].size() && lcp < (int)a[i + 1].size() && a[i][lcp] == a[i + 1][lcp]) lcp++;
        if(lcp == (int)a[i].size()) {
            seg.push_back({0, c - 1});
            //cout << i << " : [0 .. " << c - 1 << "]\n";
            continue;
        }
        if(lcp == (int)a[i + 1].size()) {
            printf("-1\n");
            return true;
        }
        int c1, c2;
        c1 = a[i][lcp];
        c2 = a[i + 1][lcp];
        if(c1 < c2) {
            //cout << i << " : [0 .. " << c - 1 - c2 << "] v [" << c - c1 << " .. " << c - 1 << "]\n";
            seg.push_back({0, c - 1 - c2});
            seg.push_back({c - c1, c - 1});
        }else {
            //cout << i << " : [" << c - c1 << " .. " << c - c2 - 1 << "]\n";
            seg.push_back({c - c1, c - 1 - c2});
        }
    }

    vec< int > sum(c);

    for(auto cur : seg) {
        int l, r;
        tie(l, r) = cur;
        if(l <= r) {
            sum[l]++;
            if(r + 1 < c) sum[r + 1]--;
        }
    }

    /*for(int pr = 0, i = 0;i < c;i++) {
        pr += sum[i];
        cout << pr << " ";
    }
    cout << "\n";*/

    for(int pr = 0, i = 0;i < c;i++) {
        pr += sum[i];
        if(pr == n - 1) {
            printf("%d\n", i);
            return true;
        }
    }

    printf("-1\n");

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