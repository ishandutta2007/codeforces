#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string sh, m;
    cin >> sh;
    cin >> m;
    multiset<char> mset;
    sort(sh.begin(), sh.end());
    sort(m.begin(), m.end());
    for (int i = 0; i < m.size(); ++i) mset.insert(m[i]);

    int tochn =0 ;
    for (int i = n - 1; i >= 0; --i) {
        if (*mset.rbegin() >= sh[i]) {
            auto it = mset.end();
            it--;
            mset.erase(it);
        } else {
            tochn++;
        }
    }
    cout << tochn << endl;

    mset.clear();
    for (int i = 0; i < m.size(); ++i) mset.insert(m[i]);
    int ans = n;
    for (int i = 0; i < n; ++i) {
        auto it = mset.upper_bound(sh[i]);
        if (it == mset.end()) {
            ans = i;
            break;
        }
        else {
            mset.erase(it);
        }
    }
    cout << ans;
    return 0;
}