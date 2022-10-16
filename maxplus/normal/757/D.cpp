#include <algorithm>
#include <iostream>
#include <map>
#define all(a) a.begin(), a.end()

using namespace std;

constexpr int mn = 20, mod = 1e9 + 7, N = 75;

int n = N, ans;
string s = "101001001110010100011000011111110110111001011101010011000111110101100111011";
map<int, int> msk[N + 1];

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
//        msk[i].reserve(msk[i - 1].size() * 30);
        for (int j = i - 1, ln = 0; j >= 0 && (s[j] == '0' || (i - j - 1) < 5 &&
                (ln += 1 << (i - j - 1)) <= mn); --j) {
            if (ln) {
                if (j)
                    for (auto m: msk[j])
                        (msk[i][m.first | (1 << ln)] += m.second) %= mod;
                (++msk[i][1 << ln]) %= mod;
            }
        }
        for (auto m = msk[i].begin(); m != msk[i].end(); ) {
            int lft = 0;
            for (int ln = 1; ln < (32 - __builtin_clz(m->first)); ++ln)
                if (!(m->first & (1 << ln)))
                    lft += (32 - __builtin_clz(ln));
            if (lft + i > n)
                m = msk[i].erase(m);
            else
                ++m;
        }
        for (auto m: msk[i])
            if (__builtin_popcount(m.first + 2) == 1)
                (ans += m.second) %= mod;
//        cout << i << ' ' << msk[i].size() << ' ' << ans << '\n';
    }
    cout << ans;
    return 0;
}