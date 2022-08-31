#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
pair < int, int > a[505];
int wins[505];
deque < pair < int, int > > b;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> k;
    int curmax = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        if (curmax < a[i].first) curmax = a[i].first;
        a[i].second = i;
        b.push_back(a[i]);
    }
    if (k > 505) {
        cout << curmax;
        return 0;
    }
    while(1) {
       auto x = b.front();
        b.pop_front();
        auto y = b.front();
        b.pop_front();
        if (x.first < y.first) {
            wins[y.second]++;
            if (wins[y.second] >= k) {
                cout << y.first;
                return 0;
            }
            b.push_front(y);
            b.push_back(x);
        }
        else {
            wins[x.second]++;
            if (wins[x.second] >= k) {
                cout << x.first;
                return 0;
            }
            b.push_front(x);
            b.push_back(y);
        }
    }
    return 0;
}