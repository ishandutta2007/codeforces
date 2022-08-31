#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111;
map<pair<int, ll>, int> dp;

bool get_bit(ll mask, int ind)
{
    return mask & (1 << ind);
}

ll set_bit(ll mask, int ind)
{
    return (mask |= (1 << ind));
}

int f(int n, ll mask)
{
    //cout << n << ' ' << mask << endl;
    if (n == 0) return 0;
    if (dp.count(mp(n, mask))) return dp[mp(n, mask)];
    vector<int> ch_gr;
    for (int i = 1; i <= n; ++i) {
        if (get_bit(mask, i)) continue;
        ch_gr.pb(f(n - i, set_bit(mask, i)));
    }
    if (ch_gr.size() == 0) {
        dp[mp(n, mask)] = 0;
        return 0;
    }
    sort(ch_gr.begin(), ch_gr.end());
    int mex = ch_gr.back() + 1;
    if (ch_gr[0] != 0) mex = 0;
    else {
        for (int i = 1; i < ch_gr.size(); ++i) {
            if (ch_gr[i - 1] + 1 < ch_gr[i]) {
                mex = ch_gr[i - 1] + 1;
                break;
            }
        }
    }
    dp[mp(n, mask)] = mex;
    return mex;
}

int grandi[] = {0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};

int main()
{
    int n;
    //f(2, 0);
    //for (int i = 0; i <= 60; ++i) cout << f(i, 0) << ',';
    cin >> n;
    int a, ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ans ^= grandi[a];
    }
    cout << (ans == 0 ? "YES" : "NO");
    return 0;
}