#include <bits/stdc++.h>

using namespace std;

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
int t, n, k;

void solve() {
    cin >> n >> k;
    while (k>3) {
        k--;
        n--;
        cout << "1 ";
    }
    int a, b, c;
    if (n%4==0) {
        a=n/4;
        b=n/4;
        c=n/2;
    } else if (n%2==0) {
        a=2;
        b=(n-2)/2;
        c=(n-2)/2;
    } else {
        a=1;
        b=n/2;
        c=n/2;
    }
    cout << a << ' ' << b << ' ' << c << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}