#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define F first
#define S second


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<string> ans(n);
    vector<string> names;
    for (char c = 'A'; c <= 'Z'; c++)
        for (char t = 'a'; t <= 'z'; t++) {
            string cur;
            cur += c;
            cur += t;
            names.push_back(cur);
        }
    int last = 0;
    for (int i = 0; i < k - 1; i++)
        ans[i] = names[last++];
    for (int i = k - 1; i < n; i++) {
        string s;
        cin >> s;
        if (s == "YES")
            ans[i] = names[last++];
        else
            ans[i] = ans[i - k + 1];
    }
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
}