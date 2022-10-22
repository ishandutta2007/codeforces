#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

const int MAXN = 55;

int n;
ll a[MAXN];
ll b[MAXN];
ll value[MAXN], sum_value;
ll dp[MAXN][MAXN];

bool check(ll W, bool pr = false) {
    sum_value = 0;
    for(int i = 1;i <= n;i++) {
        value[i] = 1000ll * a[i] - 1ll * b[i] * W;
        sum_value += value[i];
    }

    if(sum_value <= 0) {
        return true;
    }

    if(pr) {
        for(int i = 1;i <= n;i++) {
            cout << a[i] << " ";
        }
        cout << "\n";

        for(int i = 1;i <= n;i++) {
            cout << value[i] << " ";
        }
        cout << "\n";
        cout << "total = " << sum_value << "\n";
    }

    for(int i = 0;i < MAXN;i++) {
        for(int j = 0;j < MAXN;j++) {
            dp[i][j] = -inf64;
        }
    }

    int f = 1;
    while(f < n && a[f] == a[f + 1]) f++;

    vec< ll > hlp;
    for(int i = 1;i <= f;i++) hlp.push_back(value[i]);
    sort(ALL(hlp));
    reverse(ALL(hlp));

    {
        ll tmp = 0;
        for(int i = 0;i <= f;i++) {
            dp[f][i] = tmp;
            if(i < f) tmp += hlp[i];
        }
    }

    for(int i = f + 1;i <= n;i++) {
        int j = i;
        while(j <= n && a[i] == a[j]) j++;
        j--;

        hlp.clear();
        for(int q = i;q <= j;q++) {
            hlp.push_back(value[q]);
        }

        sort(ALL(hlp));
        reverse(ALL(hlp));

        auto relax = [](ll &x, ll y) {
            if(x < y) x = y;
        };

        for(int d = 0;d < MAXN;d++) {
            ll tmp = 0;
            for(int ad = 0;ad <= (int)hlp.size();ad++) {
                int depth = d - ((int)hlp.size() - ad);
                depth = max(depth, 0);
                depth += ad;
                relax(dp[j][depth], dp[i - 1][d] + tmp);
                if(ad < (int)hlp.size()) tmp += hlp[ad];
            }
        }

        i = j;
    }

    return dp[n][0] >= sum_value;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }

    for(int i = 1;i <= n;i++) {
        for(int j = i + 1;j <= n;j++) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }

    ll bl = -1;
    ll br = 1ll * inf * 10000ll;
    ll bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    cout << br << "\n";

    return 0;
}