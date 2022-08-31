#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

ll n, k, s;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k >> s;
    if (k > s) {
        cout << "NO";
        return 0;
    }
    if ((n - 1) * k < s) {
        cout << "NO";
        return 0;
    }
    vector<int> ans;
    ans.PB(1);
    int cur = 1;
    while (s > 0) {
        if (s >= (n - 1)) {
            cur = cur == 1 ? n : 1;
            s -= (n - 1);
        } else {
            cur = cur == 1 ? 1 + s : n - s;
            s = 0;
        }
        ans.PB(cur);
    }
    vector<int> ans1;
    int add = k - ans.size() + 1;
    for (int i = 0; i < ans.size(); ++i) {
        ans1.PB(ans[i]);
        if (i + 1 == ans.size())  continue;
        if (abs(ans[i] - ans[i + 1]) > 1) {
            int delta = ans[i] > ans[i + 1] ? -1 : 1;
            for (int j = ans[i] + delta; (j != ans[i + 1]) && add; j += delta) {
                ans1.PB(j);
                --add;
            }
        }
    }
    cout << "YES" << "\n";
    ans1.erase(ans1.begin());

    for (int a : ans1) {
        cout << a << ' ';
    }

    return 0;
}