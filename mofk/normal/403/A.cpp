#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <int, int> ii;

int N, p;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> N >> p;
        vector <ii> ans;
        ff(i, 0, N - 1) ff(j, 1, 2) ans.pb(ii(i, (i + j) % N));
        ff(i, 0, N - 1) ff(j, i + 1, N - 1) if (ans.size() < N + N + p && j - i > 2 && (i + N - j) > 2) {
            ans.pb(ii(i, j));
        }
        ff(i, 0, (int)ans.size() - 1) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
    return 0;
}