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

int k, n, q, p;
string s;
vi dp;
char c;

void pull(int i) {
    if (s[n-1-i]=='?') dp[i]=dp[2*i]+dp[2*i+1];
    else if (s[n-1-i]=='0') dp[i]=dp[2*i+1];
    else dp[i]=dp[2*i];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    cin >> s;
    n=pow(2, k);
    dp.rsz(2*n, 1);
    for (int i = n-1; i > 0; i--) {
        pull(i);
    }
    cin >> q;
    F0R(i, q) {
        cin >> p >> c;
        s[p-1]=c;
        for (int j = n-p; j>0; j /= 2) pull(j);
        cout << dp[1] << '\n';
    }
}