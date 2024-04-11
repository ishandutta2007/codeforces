
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3505;
int t, n, m, k;
int a[N], b[N];

int l, r;
deque<int> q;

void left() {
    if(q.front() == l)
        q.pop_front();
    l++;
}
void right() {
    r++;
    while(q.size() && b[q.back()] >= b[r])
        q.pop_back();
    q.push_back(r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        k = min(k, m - 1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++) {
            b[i] = max(a[i], a[i + n - m]);
        }
        // sliding window of m - k on b.
        l = 0, r = -1;
        int best = 0;
        q.clear();
        for(int i = 0; i < m - k; i++) {
            right();
        }
        for(int i = m - k; i < m; i++) {
            best = max(best, b[q.front()]);
            right();
            left();
        }
        best = max(best, b[q.front()]);
        cout << best << endl;
    }
}