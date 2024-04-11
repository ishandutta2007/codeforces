
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define VI vector<int>

using namespace std;

int n;
LL x, y;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    vector<pair<LL, LL>> a(n);
    FOR(i, n) {
        cin >> x >> y;
        a[i] = Mp(x, y - x * x);
    }
    sort(all(a));
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    bool b[n];
    for(int i = 1; i < n; i++) {
        b[i - 1] = (a[i].first == a[i - 1].first);
    }
    b[n - 1] = false;
    stack<pair<LL, LL> > s;
    for(int i = 0; i < n; i++) {
        if(b[i]) continue;
        pair<LL, LL> p1, p2;
        while(s.size() > 1) {
            p2 = s.top(); s.pop();
            p1 = s.top();
            if((a[i].first - p2.first) * (p2.second - p1.second) -
                (a[i].second - p2.second) * (p2.first - p1.first) > 0) {
                s.push(p2);
                break;
            }
        }
        s.push(a[i]);
    }
    cout << (s.size() - 1) << endl;
    // while(!s.empty()) {
    //     pair<LL, LL> p = s.top();
    //     s.pop();
    //     cout << "STACK: " << p.first << " " << (p.second + p.first * p.first) << endl;
    // }
}