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
int t, n, cnt, cnt1, cnt2, half;
string s, a, b;
vector<bool> same;

void solve() {
    cin >> n >> s;
    cnt=0;
    half = n/2;
    same.clear();
    same.rsz(n, false);
    F0R(i, n) if(s[i]=='1') same[i]=true;
    F0R(i, n) if (same[i]) cnt++;
    if (! (cnt%2==0 && same[0] && same[n-1])) {
        cout << "NO\n";
        return;
    }
    a=b=s;
    cnt /= 2;
    cnt1=0;
    cnt2=0;
    F0R(i, n) {
        if (same[i]) {
            if (cnt1<cnt) a[i]=b[i]='(';
            else a[i]=b[i]=')';
            cnt1++;
        } else {
            if (cnt2%2==0) {
                a[i]='(';
                b[i]=')';
            } else {
                a[i]=')';
                b[i]='(';
            }
            cnt2++;
        }
    }
    cout << "YES\n" << a << '\n' << b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}