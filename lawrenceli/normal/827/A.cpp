#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 100100;
const int maxl = 2000100;

int n, l;
string s[maxn];
vector<int> add[maxl];
vector<pair<int, int> > rem[maxl];
set<pair<int, int> > st;
char ans[maxl];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int len = s[i].length();
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int p; cin >> p;
            p--;
            l = max(l, p + len);
            add[p].push_back(i);
            rem[p + len].push_back(MP(i, p));
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j : add[i]) st.insert(MP(j, i));
        for (auto j : rem[i]) st.erase(j);

        if (st.empty()) ans[i] = 'a';
        else {
            auto j = *st.begin();
            ans[i] = s[j.A][i - j.B];
        }
    }

    ans[l] = 0;
    printf("%s\n", ans);
}