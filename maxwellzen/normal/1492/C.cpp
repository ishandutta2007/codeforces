#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int n, m;
string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s >> t;
    vi mins(m), maxs(m);
    int prev = 0;
    for (int i = 0; i < m; i++) {
        while (s[prev]!=t[i]) prev++;
        mins[i]=prev;
        prev++;
    }
    prev = n-1;
    for (int i = m-1; i >= 0; i--) {
        while (s[prev] != t[i]) prev--;
        maxs[i]=prev;
        prev--;
    }
    int ans = INT_MIN;
    for (int i = 1; i < m; i++) {
        ans = max(ans, maxs[i]-mins[i-1]);
    }
    cout << ans << '\n';
}