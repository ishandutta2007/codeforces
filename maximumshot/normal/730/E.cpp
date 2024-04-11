#include <bits/stdc++.h>

using namespace std;

#define FOR(i, p, n) for (int i = (int)(p); i < (int)(n); ++i)
#define FORD(i, p, n) for (int i = (int)(p); i >= (int)(n); --i)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define RE scanf
#define WR printf
#define SKP scanf("%*c")

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

int const N = 105;

int n;
PII a[N];
int delt[N];

int main() {

    cin >> n;

    for(int x, y, i = 0;i < n;i++) {
        cin >> x >> y;
        delt[i] = y;
        a[i] = {-x, i};
    }

    sort(a, a + n);

    int res = 0;

    for(int i = n - 1;i >= 0;i--) {
        if(delt[a[i].second] < 0) continue;
        int cnt = 0;
        for(int j = 0;j < n;j++) {
            if(i == j) continue;
            if(a[j] < a[i]) cnt++;
        }
        a[i].first -= delt[a[i].second];
        for(int j = 0;j < n;j++) {
            if(i == j) continue;
            if(a[j] < a[i]) cnt--;
        }
        if(cnt < 0) cnt = -cnt;
        res += cnt;
    }

    for(int i = 0;i < n;i++) {
        if(delt[a[i].second] >= 0) continue;
        int cnt = 0;
        for(int j = 0;j < n;j++) {
            if(i == j) continue;
            if(a[j] < a[i]) cnt++;
        }
        a[i].first -= delt[a[i].second];
        for(int j = 0;j < n;j++) {
            if(i == j) continue;
            if(a[j] < a[i]) cnt--;
        }
        if(cnt < 0) cnt = -cnt;
        res += cnt;
    }

    cout << res << "\n";

    return 0;
}