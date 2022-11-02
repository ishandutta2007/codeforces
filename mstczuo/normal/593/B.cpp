# include <bits/stdc++.h>

using namespace std;

pair<long long,long long> a[100010];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int x1,x2; cin >> x1 >> x2;
    for(int i = 0; i < n; ++i) {
        int k, b; cin >> k >> b;
        long long y1 = 1ll * k * x1 + b;
        long long y2 = 1ll * k * x2 + b;
        a[i] = make_pair(y1, y2);
    }
    sort(a, a + n);
    bool flag = true;
    for(int i = 1; i < n; ++i) {
        if(a[i].second < a[i-1].second) {
            flag = false; break;
        }
    }
    puts(!flag ? "YES" : "NO");
}