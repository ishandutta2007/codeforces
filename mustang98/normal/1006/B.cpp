#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2111, inf = 1000111222;

vector<int> v;

int n, k;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.PB(a);
    }
    multiset<int> s;
    vector<int> v1 = v;
    sort(v1.begin(), v1.end());
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        int cur = v1[v1.size() - i - 1];
        ans += cur;
        s.insert(cur);
    }
    cout << ans << endl;
    int cnt = 0;
    vector<int> ansv;
    for (int i = 0; i < v.size(); ++i) {
        cnt++;
        if (s.count(v[i])) {
            //cout << cnt << ' ';
            ansv.PB(cnt);
            cnt = 0;
            s.erase(s.find(v[i]));
        }
    }
    ansv.back() += cnt;
    for (int a : ansv) {
        cout << a << ' ';
    }
    return 0;
}