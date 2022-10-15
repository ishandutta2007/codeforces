#include <bits/stdc++.h>
using namespace std;


typedef long long LL;
int n;
LL ans;
priority_queue <LL, vector <LL>, greater <LL> > q;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (q.size() && q.top() < x) {
            ans += x - q.top();
            q.pop();
            q.push(x);
        }
        q.push(x);
    }
    cout << ans << endl;
}