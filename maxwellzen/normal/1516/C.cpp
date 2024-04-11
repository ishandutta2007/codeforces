#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second
int n;
vi a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.rsz(n);
    F0R(i, n) cin >> a[i];
    int sum = 0;
    F0R(i, n) sum += a[i];
    if (sum%2!=0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<bool> dp(sum/2 + 1, false);
    dp[0]=true;
    F0R(i, n) {
        for (int j = dp.size()-1; j >= a[i]; j--) {
            dp[j] = dp[j] || dp[j-a[i]];
        }
    }
    if (!dp[sum/2]) {
        cout << 0 << '\n';
        return 0;
    }
    while (sum%2==0) {
        F0R(i, n) if (a[i]%2!=0) {
            cout << 1 << '\n' << i+1 << '\n';
            return 0;
        }
        sum /= 2;
        F0R(i, n) a[i] >>= 1;
    }
    cout << 0 << '\n';
}