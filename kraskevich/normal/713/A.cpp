#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 18;

int to_pat(string s) {
    while (s.length() < N)
        s = std::string("0") + s;
    int res = 0;
    for (int i = 0; i < N; i++)
        if ((s[i] - '0') % 2)
            res |= 1 << i;
    return res;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<int> cnt(1 << (N + 1));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t, s;
        cin >> t >> s;
        int x = to_pat(s);
        if (t == "+")
            cnt[x]++;
        else if (t == "-")
            cnt[x]--;
        else
            cout << cnt[x] << "\n";
    }
}