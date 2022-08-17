#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int cnt[max_n];
int ans;

void add(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    cnt[a]++;
    if (cnt[a] == 1) {
        --ans;
    }
}

void rem(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    cnt[a]--;
    if (cnt[a] == 0) {
        ++ans;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    ans = n;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        scanf("%d", &t);
        if (t == 3) {
            printf("%d\n", ans);
            continue;
        }
        int a, b;
        scanf("%d%d", &a, &b);
        if (t == 1) {
            add(a, b);
        } else {
            rem(a, b);
        }
    }

    return 0;
}