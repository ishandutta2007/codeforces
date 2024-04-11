#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <ll, ll> ii;

vector <ii> v;
int N; ll M, zz;
priority_queue <ll> save;


bool check(int pos) {
    priority_queue <ll> q = save;
    ll rem = M, ptr = q.size();
    while (q.size() >= pos) {
        ll u = q.top(); q.pop();
        rem += u;
        if (rem < 0) return 0;
        while (ptr < N && v[ptr].first > rem) q.push(v[ptr].first - v[ptr].second), ++ptr;
    }
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> zz; --N;
    v.assign(N, ii());
    int l = 1, r = 1;
    ff(i, 0, N - 1) { cin >> v[i].first >> v[i].second; ++v[i].second; if (v[i].first > M) ++r, save.push(v[i].first - v[i].second); }
    sort(v.begin(), v.end(), greater <ii>());
    while (l < r) {
        int m = l + r >> 1;
        if (check(m)) r = m; else l = m + 1;
    }
    cout << l << endl;
    return 0;
}