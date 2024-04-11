#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
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

int t, n, k, result, logk;
vi diff;
bool add;

int convert(vi x) {
    int ans = 0;
    F0R(i, logk) ans += x[i]*pow(k, i);
    return ans;
}

vi convert(int x) {
    vi ans(logk, 0);
    F0R(i, logk) {
        ans[i]=x%k;
        x /= k;
    }
    return ans;
}

vi subtract(vi a, vi b) {
    vi ans(logk, 0);
    F0R(i, logk) {
        ans[i]=a[i]-b[i];
        ans[i] %= k;
        while (ans[i]<0) ans[i] += k;
    }
    return ans;
}

vi comb(vi a, vi b) {
    vi ans(logk, 0);
    F0R(i, logk) {
        if (add) ans[i]=a[i]+b[i];
        else ans[i]=a[i]-b[i];
        ans[i] %= k;
        while (ans[i]<0) ans[i] += k;
    }
    return ans;
}
 
void solve() {
    cin >> n >> k;
    logk=0;
    while (pow(k, logk)<=n) logk++;
    diff = convert(0);
    add=true;
    F0R(i, n) {
        vi hold = comb(diff, convert(i));
        int query = convert(hold);
        cout << query << endl;
        cin >> result;
        if (result==1) return;
        diff = subtract(hold, diff);
        add = !add;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}