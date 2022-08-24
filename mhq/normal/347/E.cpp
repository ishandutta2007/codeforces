#include <bits/stdc++.h>

using namespace std;
const int maxN = (int)1e6 + 10;
int a, b;
int f[maxN];
int ans[maxN];
int to[maxN];
vector < int > v;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cin >> a >> b;
    for (int i = b + 1; i <= a; i++) f[i - b] = i - 1;
    for (int i = 0; i < v.size(); i++) {
        if ((a - a % v[i]) >= b) f[a - b] = min(f[a - b], a - a % v[i]);
        int st = v[i] * ((b + v[i] - 1) / v[i]);
        if (st > a) continue;
        st += v[i] - 1;
        if (st > a) continue;
        for (int j = st; j <= a; j += v[i]) f[j - b] = min(f[j - b], j - (v[i] - 1));
    }
    ans[0] = 0;
    int t = 2 * (int)1e9;
    for (int i = a; i >= b + 1; i--) {
        t = min(t, f[i - b]);
        to[i - b] = t;
    }
    int k = 0;
    while (a > b) {
        k++;
        a = to[a - b];
    }
    cout << k;
	return 0;
}