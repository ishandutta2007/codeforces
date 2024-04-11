#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

int query(int a, vector<int> b) {
    printf("1 %d %d ", b.size(), a + 1);
    for (int i : b) {
        printf("%d ", i + 1);
    }
    printf("\n");
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    if (ans == -1) {
        exit(228);
    }
    return ans;
}

int query(int a, pair<int, int> b) {
    printf("1 %d %d ", b.S - b.F + 1, a + 1);
    for (int i = b.F; i <= b.S; ++i) {
        printf("%d ", i + 1);
    }
    printf("\n");
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    if (ans == -1) {
        exit(228);
    }
    return ans;
}

void printa(int a) {
    printf("-1 %d\n", a);
    fflush(stdout);
}

void solve() {
    int n;
    scanf("%d", &n);
    int l = 1, r = n;
    int dst = query(0, MP(1, n - 1));
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (query(0, MP(l, mid - 1)) == dst) {
            r = mid;
        } else {
            l = mid;
        }
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (i != l) {
            v.PB(i);
        }
    }
    int ans = query(l, v);
    printa(ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}