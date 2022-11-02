#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

typedef long long ll;

const int maxn = 1005;
const int maxa = 10000;

int n;
ll m, a[maxn];

vector<pair<ll, ll> > fact;
vector<int> anum[maxn];

void init() {
    for (int k = 2; k <= 1000000; k++) {
        int num = 0;
        while (m % k == 0) m /= k, num++;
        if (num) fact.push_back(MP(k, num));
    }
    if (m > 1) fact.push_back(MP(m, 1));
}

int vas;
//vector<int> va[maxa]; int vas;
//vector<int> vcur;
/*
void dfs(int i) {
    if (i == fact.size()) {
        va[vas++] = vcur;
    } else {
        for (int j = 0; j <= fact[i].B; j++) {
            vcur[i] = j;
            dfs(i + 1);
        }
    }
}
*/
int mult[1000];

int conv(vector<int> v) {
    int ret = 0;
    for (int i = 0; i < v.size(); i++) {
        ret *= (fact[i].B + 1);
        ret += v[i];
    }
    return ret;
}

pair<ll, ll> dp[maxn][maxa];
int par[maxn][maxa];

int getnxt(int cur, int i) {
    //vector<int>& v = va[cur];
    int ret = cur;
    for (int j = 0; j < fact.size(); j++) {
        int x = (cur / mult[j + 1]) % (fact[j].B + 1);
        int aft = min(fact[j].B, ll(x) + anum[i][j]);
        ret += (aft - x) * mult[j + 1];
    }
    if (!(0 <= ret && ret < vas)) assert(0);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    if (m == 1) {
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << "1\n" << min_element(a, a + n) - a + 1 << '\n';
        return 0;
    }

    init();
    
    //for (auto i : fact) cout << i.A << ' ' << i.B << endl;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ll x = a[i];
        anum[i].resize(fact.size(), 0);
        for (int j = 0; j < fact.size(); j++) {
            pair<ll, ll> p = fact[j];
            int k = 0;
            while (k < p.B && x % p.A == 0) k++, x /= p.A;
            anum[i][j] = k;
        }
    }

    mult[int(fact.size())] = 1;
    for (int i = int(fact.size()) - 1; i >= 0; i--) {
        mult[i] = mult[i + 1] * (fact[i].B + 1);
    }

    vas = mult[0];
    //vcur.resize(fact.size());
    //dfs(0);
/*
    for (int i = 0; i < vas; i++) {
        for (int j : va[i]) cout << j << ' ';
        cout << '\n';
        cout << conv(va[i]) << endl;
    }
*/
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < vas; j++)
            dp[i][j] = MP(1e9, 0);

    dp[0][0] = MP(0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vas; j++)
            if (dp[i][j].A < 1e9) {
                if (dp[i][j] < dp[i + 1][j])
                    dp[i + 1][j] = dp[i][j], par[i + 1][j] = j;

                int k = getnxt(j, i);
                pair<ll, ll> p = MP(dp[i][j].A + 1, dp[i][j].B + a[i]);
                if (p < dp[i + 1][k])
                    dp[i + 1][k] = p, par[i + 1][k] = j;
            }
    }

    if (dp[n][vas - 1].A == 1e9) cout << "-1\n";
    else {
        vector<int> ans;
        int i = n, j = vas - 1;
        while (i) {
            int k = par[i][j];
            if (k != j) ans.push_back(i);
            i--, j = k;
        }

        cout << ans.size() << '\n';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }
}