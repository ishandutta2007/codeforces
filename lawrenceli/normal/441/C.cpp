#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 305;

int n, m, k;
pii ans[MAXN*MAXN];
int cnt, cnt2;

int main() {
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        if (!(i&1))
            for (int j=0; j<m; j++)
                ans[cnt++] = pii(i, j);
        else
            for (int j=m-1; j>=0; j--)
                ans[cnt++] = pii(i, j);
    }
    int len = cnt / k;
    for (int i=0; i<cnt % k; i++) {
        cout << len+1 << ' ';
        for (int j=0; j<len+1; j++) {
            cout << ans[cnt2].first+1 << ' ' << ans[cnt2].second+1 << ' ';
            cnt2++;
        }
        cout << '\n';
    }
    while (cnt2 < cnt) {
        cout << len << ' ';
        for (int j=0; j<len; j++) {
            cout << ans[cnt2].first+1 << ' ' << ans[cnt2].second+1 << ' ';
            cnt2++;
        }
        cout << '\n';
    }
    return 0;
}