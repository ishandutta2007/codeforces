#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 3600, inf = 1000111222;

int n, pos, k;
vector<int> m;

int solve() {
    k = min(k, pos - 1);
    int ans = -inf;
    for (int pr = 0; pr <= k; ++pr) {
        int sf = k - pr;
        vector<int> v = m;
        for (int i = 0; i < sf; ++i) {
            v.pop_back();
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < pr; ++i) {
            v.pop_back();
        }
        int left = pos - 1 - k;
        int mn = inf;
        for (int takep = 0; takep <= left; ++takep) {
            int a = v[takep];
            int b = v[v.size() - (left - takep) - 1];
            int c = max(a, b);
            mn = min(mn, c);
        }
        ans = max(ans, mn);
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        m.clear();
        cin >> n >> pos >> k;
        for (int i = 0; i <n; ++i) {
            int a;
            cin >> a;
            m.PB(a);
        }
        cout << solve() << "\n";
        //return 0;
    }

    return 0;
}