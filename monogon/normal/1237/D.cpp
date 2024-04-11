
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5;
int n;
ll a[3 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll m = 2e9, M = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[2 * n + i] = a[n + i] = a[i];
        m = min(m, a[i]);
        M = max(M, a[i]);
    }
    if(m * 2 >= M) {
        for(int i = 0; i < n; i++) {
            cout << -1 << " ";
        }
        cout << endl;
        return 0;
    }
    int i = 0, j = 0;
    deque<int> q;
    while(i < n) {
        if(q.front() < i) {
            q.pop_front();
        }
        while(q.empty() || a[j] * 2 >= a[q.front()]) {
            while(q.size() && a[q.back()] < a[j]) {
                q.pop_back();
            }
            q.push_back(j);
            j++;
        }
        cout << (j - i) << " ";
        i++;
    }
    cout << endl;
}