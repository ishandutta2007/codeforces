#include <bits/stdc++.h>
#define pii pair<int, string>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
string ans[1 << 8] = {"!x&x", "!(x|y|z)", "!x&!y&z", "!x&!y", "!x&!z&y", "!x&!z", "!(!y&!z|x|y&z)", "!(x|y&z)", "!x&y&z", "!(!y&z|!z&y|x)", "!x&z", "!(!z&y|x)", "!x&y", "!(!y&z|x)", "!x&(y|z)", "!x", "!y&!z&x", "!y&!z", "!(!x&!z|x&z|y)", "!(x&z|y)", "!(!x&!y|x&y|z)", "!(x&y|z)", "!(!x&!y|x&y|z)|!x&!y&z", "!((x|y)&z|x&y)", "!x&y&z|!y&!z&x", "!x&y&z|!y&!z", "!x&z|!y&!z&x", "!x&z|!y&!z", "!x&y|!y&!z&x", "!x&y|!y&!z", "!x&(y|z)|!y&!z&x", "!x|!y&!z", "!y&x&z", "!(!x&z|!z&x|y)", "!y&z", "!(!z&x|y)", "!x&!z&y|!y&x&z", "!x&!z|!y&x&z", "!x&!z&y|!y&z", "!x&!z|!y&z", "!x&y&z|!y&x&z", "!(!x&z|!z&x|y)|!x&y&z", "!(x&y)&z", "!(!z&x|y)|!x&z", "!x&y|!y&x&z", "!(!y&z|x)|!y&x&z", "!x&y|!y&z", "!x|!y&z", "!y&x", "!(!x&z|y)", "!y&(x|z)", "!y", "!x&!z&y|!y&x", "!x&!z|!y&x", "!x&!z&y|!y&(x|z)", "!x&!z|!y", "!x&y&z|!y&x", "!(!x&z|y)|!x&y&z", "!x&z|!y&x", "!x&z|!y", "!x&y|!y&x", "!(!x&!y&z|x&y)", "!x&(y|z)|!y&x", "!x|!y", "!z&x&y", "!(!x&y|!y&x|z)", "!x&!y&z|!z&x&y", "!x&!y|!z&x&y", "!z&y", "!(!y&x|z)", "!x&!y&z|!z&y", "!x&!y|!z&y", "!x&y&z|!z&x&y", "!(!x&y|!y&x|z)|!x&y&z", "!x&z|!z&x&y", "!(!z&y|x)|!z&x&y", "!(x&z)&y", "!(!y&x|z)|!x&y", "!x&z|!z&y", "!x|!z&y", "!z&x", "!(!x&y|z)", "!x&!y&z|!z&x", "!x&!y|!z&x", "!z&(x|y)", "!z", "!x&!y&z|!z&(x|y)", "!x&!y|!z", "!x&y&z|!z&x", "!(!x&y|z)|!x&y&z", "!x&z|!z&x", "!(!x&!z&y|x&z)", "!x&y|!z&x", "!x&y|!z", "!x&(y|z)|!z&x", "!x|!z", "!y&x&z|!z&x&y", "!(!x&y|!y&x|z)|!y&x&z", "!y&z|!z&x&y", "!(!z&x|y)|!z&x&y", "!y&x&z|!z&y", "!(!y&x|z)|!y&x&z", "!y&z|!z&y", "!(!y&!z&x|y&z)", "!x&y&z|!y&x&z|!z&x&y", "!(!x&y|!y&x|z)|!x&y&z|!y&x&z", "!(x&y)&z|!z&x&y", "!(!z&x|y)|!x&z|!z&x&y", "!(x&z)&y|!y&x&z", "!(!y&x|z)|!x&y|!y&x&z", "!(x&y)&z|!z&y", "!x|!y&z|!z&y", "!(y&z)&x", "!(!x&y|z)|!y&x", "!y&z|!z&x", "!y|!z&x", "!y&x|!z&y", "!y&x|!z", "!y&(x|z)|!z&y", "!y|!z", "!(y&z)&x|!x&y&z", "!(!x&y|z)|!x&y&z|!y&x", "!(x&y)&z|!z&x", "!x&z|!y|!z&x", "!(x&z)&y|!y&x", "!x&y|!y&x|!z", "!x&y|!y&z|!z&x", "!(x&y&z)", "x&y&z", "!(x|y|z)|x&y&z", "!x&!y&z|x&y&z", "!x&!y|x&y&z", "!x&!z&y|x&y&z", "!x&!z|x&y&z", "!(!y&!z|x|y&z)|x&y&z", "!(x|y&z)|x&y&z", "y&z", "!(x|y|z)|y&z", "!x&z|y&z", "!x&!y|y&z", "!x&y|y&z", "!x&!z|y&z", "!x&(y|z)|y&z", "!x|y&z", "!y&!z&x|x&y&z", "!y&!z|x&y&z", "!(!x&!z|x&z|y)|x&y&z", "!(x&z|y)|x&y&z", "!(!x&!y|x&y|z)|x&y&z", "!(x&y|z)|x&y&z", "!(!x&!y|x&y|z)|!x&!y&z|x&y&z", "!((x|y)&z|x&y)|x&y&z", "!y&!z&x|y&z", "!y&!z|y&z", "!x&z|!y&!z&x|y&z", "!(x&z|y)|y&z", "!x&y|!y&!z&x|y&z", "!(x&y|z)|y&z", "!x&(y|z)|!y&!z&x|y&z", "!x|!y&!z|y&z", "x&z", "!(x|y|z)|x&z", "!y&z|x&z", "!x&!y|x&z", "!x&!z&y|x&z", "!x&!z|x&z", "!x&!z&y|!y&z|x&z", "!(x|y&z)|x&z", "(x|y)&z", "!(x|y|z)|(x|y)&z", "z", "!x&!y|z", "!x&y|x&z", "!(!y&z|x)|x&z", "!x&y|z", "!x|z", "!y&x|x&z", "!y&!z|x&z", "!y&(x|z)|x&z", "!y|x&z", "!x&!z&y|!y&x|x&z", "!(x&y|z)|x&z", "!x&!z&y|!y&(x|z)|x&z", "!x&!z|!y|x&z", "!y&x|y&z", "!(!x&z|y)|y&z", "!y&x|z", "!y|z", "!x&y|!y&x|x&z", "!x&!z|!y&x|y&z", "!x&y|!y&x|z", "!x|!y|z", "x&y", "!(x|y|z)|x&y", "!x&!y&z|x&y", "!x&!y|x&y", "!z&y|x&y", "!x&!z|x&y", "!x&!y&z|!z&y|x&y", "!(x|y&z)|x&y", "(x|z)&y", "!(x|y|z)|(x|z)&y", "!x&z|x&y", "!(!z&y|x)|x&y", "y", "!x&!z|y", "!x&z|y", "!x|y", "!z&x|x&y", "!y&!z|x&y", "!x&!y&z|!z&x|x&y", "!(x&z|y)|x&y", "!z&(x|y)|x&y", "!z|x&y", "!x&!y&z|!z&(x|y)|x&y", "!x&!y|!z|x&y", "!z&x|y&z", "!(!x&y|z)|y&z", "!x&z|!z&x|x&y", "!x&!y|!z&x|y&z", "!z&x|y", "!z|y", "!x&z|!z&x|y", "!x|!z|y", "(y|z)&x", "!(x|y|z)|(y|z)&x", "!y&z|x&y", "!(!z&x|y)|x&y", "!z&y|x&z", "!(!y&x|z)|x&z", "!y&z|!z&y|x&y", "!x&!y|!z&y|x&z", "(x|y)&z|x&y", "!(x|y|z)|(x|y)&z|x&y", "x&y|z", "!x&!y|x&y|z", "x&z|y", "!x&!z|x&z|y", "y|z", "!x|y|z", "x", "!y&!z|x", "!y&z|x", "!y|x", "!z&y|x", "!z|x", "!y&z|!z&y|x", "!y|!z|x", "x|y&z", "!y&!z|x|y&z", "x|z", "!y|x|z", "x|y", "!z|x|y", "x|y|z", "!x|x"};
void solve() {
    string bin;
    cin >> bin;
    int mask = 0;
    for(int i = 7; i >= 0; i--) mask = mask << 1 | (bin[i] - '0');
    cout << ans[mask] << endl;
    return;
}
int main() {
    int t;
    for(cin >> t; t--; solve());
    return 0;
}