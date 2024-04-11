#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 300100;

int n, ans[MAXN];
pii arr[MAXN];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i].fi;
        arr[i].se = i;
    }

    sort(arr, arr + n);

    int cur = 0;

    for (int i=0; i<n; i++) {
        cur = max(cur + 1, arr[i].fi);
        ans[arr[i].se] = cur;
    }

    for (int i=0; i<n; i++) cout << ans[i] << ' ';

    return 0;
}