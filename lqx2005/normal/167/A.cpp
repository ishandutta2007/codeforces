#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int N = 1e5 + 10;
int n;
db a, d;
db last[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> a >> d;
    for(int i = 1; i <= n; i++) {
        db t, v;
        cin >> t >> v;
        if((v / a) * v / 2 > d) last[i] = t + sqrt(d * a * 2) / a;
        else last[i] = t + v / a + (d - (v / a) * v / 2) / v;
    }
    for(int i = 2; i <= n; i++) last[i] = max(last[i - 1], last[i]);
    cout.precision(20), cout << fixed;
    for(int i = 1; i <= n; i++) cout << last[i] << endl;
    return 0;
}