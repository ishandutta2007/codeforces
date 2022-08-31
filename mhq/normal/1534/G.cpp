#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int,int>> all;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        all.emplace_back(x, y);
    }
    sort(all.begin(), all.end(), [&](pair<int,int>& a, pair<int,int>& b) {
        return a.first + a.second < b.first + b.second;
    });
    int lst = 0;

    priority_queue<int,vector<int>,greater<>> positive;
    priority_queue<int> nonpositive;
    int offset_positive = 0;
    ll sum_start = 0;
    for (auto& it : all) {
        int cur = it.first + it.second;
        offset_positive += cur - lst;
        lst = cur;
        int he = it.first;
        sum_start += he;
        //push he x2 times
        nonpositive.push(he);
        positive.push(he - offset_positive);
        if (positive.top() + offset_positive < nonpositive.top()) {
            int x1 = positive.top();
            int x2 = nonpositive.top();
            positive.pop();
            nonpositive.pop();
            nonpositive.push(x1 + offset_positive);
            positive.push(x2 - offset_positive);
        }
        assert(positive.top() + offset_positive >= nonpositive.top());
    }
    int start = -nonpositive.size();
    int cur = 0;
    vector<int> pts;
    while (!nonpositive.empty()) {
        pts.emplace_back(nonpositive.top());
        nonpositive.pop();
    }
    reverse(pts.begin(), pts.end());
    for (auto& it : pts) {
        sum_start += 1LL * (it - cur) * start;
        cur = it;
        start++;
    }
    cout << sum_start << endl;
    return 0;
}