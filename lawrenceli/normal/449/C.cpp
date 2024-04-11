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

int n;
bool used[MAXN];
vector<int> rem;
vector<pii> ans;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i=3; i<=n; i++)
        if (!used[i]) {
            vector<int> v;
            for (int j=i; j<=n; j+=i)
                if (!used[j])
                    used[j] = 1, v.push_back(j);
            if (v.size()&1) {
                if (v.size() == 1 && v[0]%2 == 0) rem.push_back(v[0]);
                else if (v.size()>2) rem.push_back(v[1]), v.erase(v.begin()+1);
            }
            for (int k=0; k+1<v.size(); k+=2)
                ans.push_back(pii(v[k], v[k+1]));
        }
    for (int i=2; i<=n; i++)
        if (!used[i] && i%2==0)
            rem.push_back(i);

    for (int i=0; i+1<rem.size(); i+=2)
        ans.push_back(pii(rem[i], rem[i+1]));

    cout << ans.size() << '\n';
    rep(i, ans.size())
        cout << ans[i].fi << ' ' << ans[i].se << '\n';
    return 0;
}