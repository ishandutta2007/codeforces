#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 5005;

int n;
pii ar[MAXN];
int t[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> ar[i].fi >> ar[i].se;
    sort(ar, ar+n);
    for (int i=0; i<n; i++) {
        if (i == 0 || ar[i].se >= t[i-1]) t[i] = ar[i].se;
        else t[i] = ar[i].fi;
    }

    cout << t[n-1] << '\n';
    return 0;
}