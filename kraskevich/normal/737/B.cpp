#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, cnt, len, foo;
    cin >> n >> cnt >> len >> foo;
    string s;
    cin >> s;
    int tot_cnt = 0;
    vector<int> splits;
    splits.push_back(-1);
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            splits.push_back(i);
    splits.push_back(n);
    vector<int> cands;
    for (int i = 1; i < splits.size(); i++) {
        tot_cnt += (splits[i] - splits[i - 1] - 1) / len;
        for (int j = splits[i - 1] + len; j < splits[i]; j += len)
            cands.push_back(j);
    }
    cout << tot_cnt - cnt + 1 << endl;
    for (int i = 0; i < tot_cnt - cnt + 1; i++)
        cout << cands[i] + 1 << " ";
    cout << endl;
}