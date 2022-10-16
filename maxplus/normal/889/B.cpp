#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
#include <vector>
#define all(a) begin(a), end(a)

using namespace std;

constexpr int N = 1e5;

vector<string> s;
char nxt['z' + 1], prv['z' + 1], u['z' + 1];

void out() {
    cout << "NO\n";
    exit(0);
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, f = 1;
    cin >> n;
    s.resize(n);
    for (auto &str: s)
        cin >> str,
        f &= str.size() == unordered_set<char>(all(str)).size();
    if (!f)
        out();
    sort(all(s));
    s.resize(n = unique(all(s)) - s.begin());
    for (auto str: s)
        for (auto ch = str.begin() + (u[str[0]] = 1); ch != str.end(); ++ch) {
            if (!nxt[*prev(ch)])
                nxt[*prev(ch)] = *ch;
            else if (nxt[*prev(ch)] != *ch)
                out();
            if (!prv[*ch])
                prv[*ch] = *prev(ch);
            else if (prv[*ch] != *prev(ch))
                out();
            u[*ch] = 1;
        }
    string res;
    for (char c = 'a'; c <= 'z'; ++c) if (!prv[c] && u[c])
        for (char cc = c; cc; cc = nxt[cc])
            res += cc;
    if (res.size() != accumulate(all(u), 0))
        out();
    cout << res;
    return 0;
}