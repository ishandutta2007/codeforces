#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 3005;

int n, v;
pii ar[MAXN];

int main() {
    cin >> n >> v;
    for (int i=0; i<n; i++)
        cin >> ar[i].first >> ar[i].second;
    sort(ar, ar+n);
    int ans = 0;
    for (int i=1; i<=ar[n-1].first+1; i++) {
        int cnt = v;
        for (int j=0; j<n && cnt; )
            if ((ar[j].first == i || ar[j].first == i-1) && ar[j].second)
                    cnt--, ar[j].second--, ans++;
            else j++;
    }
    cout << ans << '\n';
    return 0;
}