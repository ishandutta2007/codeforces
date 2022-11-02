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
int t, n, m, k, temp, mx, tofill, cnt;
vector<set<int>> days, friends;
vi ans;

void solve() {
    cin >> n >> m;
    days.clear();
    friends.clear();
    days.rsz(m);
    friends.rsz(n);
    F0R(i, m) {
        cin >> k;
        F0R(j, k) {
            cin >> temp;
            temp--;
            days[i].insert(temp);
            friends[temp].insert(i);
        }
    }
    ans.clear();
    ans.rsz(m, -1);
    tofill=m;
    mx = (m+1)/2;
    bool possible = true;
    F0R(i, n) {
        if (tofill==0) break;
        cnt=0;
        for (int day : friends[i]) {
            if (ans[day]==-1 && days[day].size()==1) {
                ans[day]=i;
                cnt++;
                tofill--;
            }
        }
        if (cnt>mx) {
            possible=false;
            break;
        }
        for (int day : friends[i]) {
            if (cnt==mx) continue;
            if (ans[day]==-1) {
                ans[day]=i;
                cnt++;
                tofill--;
            }
        }
    }
    if (tofill>0) possible=false;
    if (! possible) cout << "NO\n";
    else {
        cout << "YES\n";
        F0R(i, m) cout << ans[i]+1 << ' ';
        cout << '\n';
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