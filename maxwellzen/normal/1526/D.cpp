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
vi freq, perm;
map<char, int> ctoi;
vector<char> itoc;
ll mx;

void eval() {
    int sum=0;
    vi loc(4);
    F0R(i, 4) {
        loc[perm[i]]=sum;
        sum += freq[perm[i]];
    }
    ll cur = 0;
    F0R(i, n) {
        int index = loc[ctoi[s[i]]];
        cur += index - i;
        F0R(j, 4) if (loc[j] <= index) loc[j]++;
    }
    if (cur>mx) {
        mx=cur;
        ans="";
        F0R(i, 4) F0R(j, freq[perm[i]]) ans += itoc[perm[i]];
    }
}

void dfs(int i) {
    if (i==4) eval();
    else FOR(j, i, 4) {
        swap(perm[i], perm[j]);
        dfs(i+1);
        swap(perm[i], perm[j]);
    }
}

void solve() {
    cin >> s;
    n=s.length();
    freq.clear(); freq.rsz(4, 0);
    F0R(i, n) freq[ctoi[s[i]]]++;
    perm.clear(); perm.rsz(4); F0R(i, 4) perm[i]=i;
    mx=-1;
    dfs(0);
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    itoc = {'A', 'N', 'T', 'O'};
    F0R(i, 4) ctoi[itoc[i]]=i;
    cin >> t;
    while (t--) {
        solve();
    }
}