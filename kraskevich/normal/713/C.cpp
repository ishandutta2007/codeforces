#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

using pll = pair<ll, ll>;

const ll INF = (ll)1e18;
const int N = 3333;

ll a[N];
ll dp[N][N];
ll med[N][N];
ll cost[N][N];
int n;

void add(multiset<ll>& s, ll& sum, ll x) {
    s.insert(x);
    sum += x;
}

void del(multiset<ll>& s, ll& sum, ll x) {
    s.erase(s.find(x));
    sum -= x;
}

void init() {
    for (int l = 0; l < n; l++) {
        multiset<ll> low;
        multiset<ll> high;
        ll slow = 0;
        ll shigh = 0;
        for (int r = l; r < n; r++) {
            if (!high.empty() && a[r] > *high.begin())
                add(high, shigh, a[r]);
            else
                add(low, slow, a[r]);
            while ((int)low.size() - (int)high.size() >= 2) {
                add(high, shigh, *low.rbegin());
                del(low, slow, *low.rbegin());
            }
            while (low.size() < high.size()) {
                add(low, slow, *high.begin());
                del(high, shigh, *high.begin());
            }
            ll cnt_low = low.size();
            ll cnt_high = high.size();
            ll curm = *low.rbegin();
            med[l][r] = curm;
            cost[l][r] = curm * cnt_low - slow + shigh - cnt_high * curm;
        }
    }
}
       
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    init();
    for (int i = 0; i < n; i++)
        fill(dp[i], dp[i] + n, INF);
    for (int i = 0; i < n; i++)
        dp[0][i] = cost[0][i];
    for (int l = 0; l < n; l++) {
        vector<pll> old;
        for (int j = 0; j <= l; j++)
            old.push_back(pll(med[j][l], dp[j][l]));
        sort(old.begin(), old.end());
        for (int i = 1; i < (int)old.size(); i++)
            old[i].second = min(old[i].second, old[i - 1].second);
        for (int r = l + 1; r < n; r++) {
            ll curm = med[l + 1][r];
            auto it = upper_bound(old.begin(), old.end(), pll(curm, -1));
            if (it == old.begin())
                continue;
            it--;
            dp[l + 1][r] = min(dp[l + 1][r], it->second + cost[l + 1][r]);
        }
    }
    ll res = INF;
    for (int l = 0; l < n; l++)
        res = min(res, dp[l][n - 1]);
    cout << res << endl;
}