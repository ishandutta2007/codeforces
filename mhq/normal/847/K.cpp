#include <bits/stdc++.h>

using namespace std;

const int maxN = (int)1e5 + 10;

string name1[maxN], name2[maxN];

map<pair<string, string> , int> mp;

int main() {
    ios_base::sync_with_stdio(0);
    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;
    for (int i = 1; i <= n; ++i) {
        cin >> name1[i] >> name2[i];
        int cur_cost = a;
        if (i >= 2 && name2[i - 1] == name1[i]) cur_cost = b;
        string s1 = name1[i], s2 = name2[i];
        if (s1 > s2) swap(s1, s2);
        mp[make_pair(s1, s2)] += cur_cost;
    }
    vector<int> c;
    for (auto & tmp : mp) {
        c.push_back(tmp.second);
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] > f && k > 0) {
            --k;
            c[i] = f;
        }
    }
    int answer = 0;
    for (int i = 0; i < c.size(); ++i) {
        answer += c[i];
    }
    cout << answer << endl;
    return 0;
}