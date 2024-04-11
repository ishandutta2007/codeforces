#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    vec< pair< pii, int > > a(n);

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &a[i].first.first, &a[i].first.second);
        a[i].second = i + 1;
    }

    sort(ALL(a), [](pair< pii, int > pp1, pair< pii, int > pp2){
        pii p1 = pp1.first;
        pii p2 = pp2.first;
        return p1.second < p2.second || p1.second == p2.second && p1.first > p2.first;
    });

    int j = -1;

    for(int i = 0;i < n;i++) {
        if(j != -1 && a[j].first.first >= a[i].first.first) {
            printf("%d %d\n", a[j].second, a[i].second);
            return 0;
        }
        if(j == -1 || a[j].first.first < a[i].first.first) {
            j = i;
        }
    }

    printf("-1 -1\n");

    return 0;
}