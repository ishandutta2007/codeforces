#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

vec< vec< int > > res;

inline void add(vec< int > add) {
    res.push_back(add);
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    while(n > 4) {
        add({n - 1, n, 1});
        add({n, n - 2, n - 1});
        for(int i = 1;i < n - 2;i++) {
            add({n - 1, i, n, i + 1});
        }
        n -= 2;
    }

    if(n == 3) {
        add({1, 2, 3});
        add({1, 2, 3});
    }else { // n == 4
        add({1, 2, 4});
        add({2, 3, 4});
        add({1, 3, 4});
        add({1, 2, 3});
    }

    printf("%d\n", (int)res.size());

    for(auto i : res) {
        printf("%d ", (int)i.size());
        for(int x : i) {
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}