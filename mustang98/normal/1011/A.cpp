#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 55, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    vector<char> ans;
    ans.PB(s[0]);
    for (int i = 1; i < n; ++i) {
        if (s[i] - ans.back() >= 2) {
            ans.PB(s[i]);
        }
    }
    if (ans.size() < k) {
        cout << -1;
        return 0;
    }
    int ansv = 0;
    for (int i = 0; i < k; ++i) {
        ansv += ans[i] - 'a' + 1;
    }
    cout << ansv;

    return 0;
}