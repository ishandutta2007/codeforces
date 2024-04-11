#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxn = 505;

int T;
string s;
string t;
bool st[Maxn];
ii ways[Maxn];

ii Add(const ii &a)
{
    return ii(a.first + 1, a.second);
}

ii Merge(const ii &a, const ii &b)
{
    if (a.first != b.first) return a.first < b.first? a: b;
    return ii(a.first, (a.second + b.second) % mod);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        cin >> s;
        cin >> t;
        for (int i = 0; i < s.length(); i++)
            st[i] = i + t.length() <= s.length() && s.substr(i, t.length()) == t;
        fill(ways, ways + s.length() + 1, ii(1000000000, 0));
        ways[0] = ii(0, 1);
        for (int i = 0; i < s.length(); i++)
            if (st[i]) {
                for (int j = i; j < i + t.length(); j++) if (st[j])
                    ways[j + t.length()] = Merge(ways[j + t.length()], Add(ways[i]));
            } else ways[i + 1] = Merge(ways[i + 1], ways[i]);
        auto res = ways[int(s.length())];
        printf("%d %d\n", res.first, res.second);
    }
    return 0;
}