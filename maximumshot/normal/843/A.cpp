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

    vec< int > a(n + 1);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    vec< int > b = a;

    sort(b.begin() + 1, b.end());

    vec< vec< int > > res;

    map< int, int > mp;

    for(int i = 1;i <= n;i++) {
        mp[b[i]] = i;
    }

    vec< char > used(n + 1);

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        vec< int > add;
        int j = i;
        while(a[j] != b[j] && !used[j]) {
            add.push_back(j);
            used[j] = 1;
            j = mp[a[j]];
        }
        if(add.empty()) add.push_back(i), used[i] = 1;
        res.push_back(add);
    }

    printf("%d\n", (int)res.size());

    for(int i = 0;i < (int)res.size();i++) {
        printf("%d ", (int)res[i].size());
        sort(ALL(res[i]));
        for(int x : res[i]) {
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}