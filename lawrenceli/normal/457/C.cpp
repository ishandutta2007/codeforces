#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 100100;
const int INF = 1e9;

int n, a[MAXN], b[MAXN], num, ans = INF, cur;
vector<int> nums[MAXN];
multiset<int> st1, st2;
set<int> grp;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) {
        cin >> a[i] >> b[i];
        if (a[i]) nums[a[i]].push_back(b[i]), grp.insert(a[i]);
        cur += b[i];
    }
    num = n;

    rep(i, MAXN) sort(nums[i].begin(), nums[i].end()), reverse(nums[i].begin(), nums[i].end());

    rep(i, MAXN) {
        ans = min(ans, cur);
        vector<int> verase;
        repi(j, grp) {
            int x = *j;
            cur -= nums[x][i], num--;
            if (!st1.empty() && nums[x][i]<*st1.rbegin()) {
                st1.insert(nums[x][i]);
                int y = *st1.rbegin();
                st1.erase(st1.find(*st1.rbegin()));
                st2.insert(y);
                cur += nums[x][i]-y;
            } else st2.insert(nums[x][i]);
            if (i+1 == sz(nums[x])) verase.push_back(x);
        }
        rep(j, verase.size()) grp.erase(verase[j]);

        while (num+st1.size()<=i+1) {
            if (st2.empty()) {
                cout << ans << '\n';
                return 0;
            }
            cur += *st2.begin();
            st1.insert(*st2.begin());
            st2.erase(st2.begin());
        }
    }

    cout << ans << '\n';
    return 0;
}