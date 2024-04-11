#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <vector>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100100;

int n, m;
pii arr[2*MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    for (int i=0; i<n; i++) {
        cin >> arr[n+i].fi;
        arr[n+i].se = i;
    }
    cin >> m;

    sort(arr, arr + 2*n);

    int ans = 1;

    for (int i=0; i<2*n; ) {
        int j = i, div2 = 0, cnt = 1;
        vector<int> v;

        for (; j<2*n && arr[j].fi == arr[i].fi; j++) {
            v.push_back(cnt++);
            if (arr[j] == arr[j+1])
                div2 ++;
        }

        int cur = 0;
        while (div2 > 0) {
            if (v[cur] & 1) cur++;
            else v[cur] = v[cur] >> 1, div2--;
        }

        for (int j=0; j<v.size(); j++)
            ans = (ll(ans) * v[j]) % m;

        i = j;
    }

    cout << ans << '\n';
    return 0;
}