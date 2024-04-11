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

int t, n;
string s, ans;
vi loc;
set<pair<int, char>> comp;
 
void solve() {
    cin >> s;
    n=s.length();
    ans="";
    while (! s.empty()) {
        n = s.length();
        loc.clear();
        loc.rsz(26, -1);
        F0R(i, n) loc[s[i]-'a']=i;
        int next = 0;
        F0R(i, n) {
            if (s[i]>s[next]) next=i;
            if (i==loc[s[i]-'a']) break;
        }
        ans += s[next];
        string news = "";
        FOR(i, next+1, n) if (s[i] != s[next]) news += s[i];
        s = news;
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}