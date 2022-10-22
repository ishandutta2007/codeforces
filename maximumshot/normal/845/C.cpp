#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    vec< pii > a(n);

    vec< int > crd;

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
        for(int j = -1;j <= 1;j++) {
            crd.push_back(a[i].first + j);
            crd.push_back(a[i].second + j);
        }
    }

    sort(ALL(crd));
    crd.resize(unique(ALL(crd)) - crd.begin());

    vec< int > cnt((int)crd.size());

    for(int i = 0;i < n;i++) {
        int l = a[i].first;
        int r = a[i].second;
        l = lower_bound(ALL(crd), l) - crd.begin();
        r = lower_bound(ALL(crd), r) - crd.begin();
        cnt[l]++;
        cnt[r + 1]--;
    }

    for(int i = 0;i < (int)crd.size();i++) {
        if(i) cnt[i] += cnt[i - 1];
        if(cnt[i] > 2) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
}