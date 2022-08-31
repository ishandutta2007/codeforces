#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int cntb[max_n];
int cnte[max_n];
int cnt[max_n];
int cntr[max_n];
int nnp[max_n];
int nnpr[max_n];

int max_np[max_n];
int max_npr[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int seg, n;
    cin >> seg >> n;
    for (int i = 0; i < seg; ++i) {
        int s, f;
        cin >> s >> f;
        --s, --f;
        cntb[s]++;
        cnte[f]++;
    }
    int curcnt = 0;
    for (int i = 0; i < n; ++i) {
        curcnt += cntb[i];
        cnt[i] = curcnt;
        cntr[i] = cnt[i];
        curcnt -= cnte[i];

        nnp[i] = nnpr[i] = inf;
    }
    nnp[n] = nnpr[n] = inf;
    reverse(cntr, cntr + n);

    nnp[0] = -1;
    int curnnp = 1;
    for (int i = 0; i < n; ++i) {
        int* pos = upper_bound(nnp, nnp + n + 1, cnt[i]);
        *pos = cnt[i];
        curnnp = max(curnnp, pos - nnp);
        max_np[i] = curnnp;
    }
    ////////
    nnpr[0] = -1;
    curnnp = 1;
    for (int i = 0; i < n; ++i) {
        int* pos = upper_bound(nnpr, nnpr + n + 1, cntr[i]);
        *pos = cntr[i];
        curnnp = max(curnnp, pos - nnpr);
        max_npr[i] = curnnp;
    }

    int ans = max(max_np[n - 1], max_npr[n - 1]);
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, max_np[i] + max_npr[n - i - 2]);
    }
    cout << ans;
    return 0;
}