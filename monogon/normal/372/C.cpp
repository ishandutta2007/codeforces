
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

const int N = 150'005, M = 305;
int n, m, d, a[M];
ll b[M], t[M], happy[N], happy2[N];
int l = 0, r = -1;
deque<ll> Q;

void left() {
    if(!Q.empty() && Q.front() == l) Q.pop_front();
    l++;
}
void right() {
    r++;
    while(!Q.empty() && happy[Q.back()] <= happy[r]) Q.pop_back();
    Q.push_back(r);
}
ll getmax() {
    assert(!Q.empty());
    return happy[Q.front()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    rep(i, 0, m) {
        cin >> a[i] >> b[i] >> t[i];
        a[i]--;
        int k = min((ll) n, (t[i] - t[i - 1]) * d);
        l = 0, r = -1;
        Q.clear();
        rep(j, 0, n) {
            while(l < max(0, j - k)) left();
            while(r < min(n - 1, j + k)) right();
            happy2[j] = getmax();
        }
        rep(j, 0, n) {
            happy[j] = happy2[j] + b[i] - abs(a[i] - j);
        }
    }
    cout << *max_element(happy, happy + n) << '\n';
}