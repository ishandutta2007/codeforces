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
int t, n, k, ca, cb;
string s, stay = ":018", a, b, c;

string rev (string s) {
    reverse(all(s));
    for (int i = 0; i < 5; i++) {
        if (stay.find(s[i])!=-1) continue;
        else if (s[i]=='5') s[i]='2';
        else if (s[i]=='2') s[i]='5';
        else return "";
    }
    return s;
}

bool valid (int i, int j) {
    a = to_string(i);
    b = to_string(j);
    while (a.length()<2) a = "0" + a;
    while (b.length()<2) b = "0" + b;
    c = rev(a + ":" + b);
    if (c=="") return false;
    if (stoi(c.substr(0, 2))<n && stoi(c.substr(3, 5))<k) return true;
    else return false;
}

void solve() {
    cin >> n >> k;
    cin >> s;
    ca = stoi(s.substr(0, 2));
    cb = stoi(s.substr(3, 5));
    while (! valid(ca, cb)) {
        cb++;
        if (cb==k) {
            ca++;
            cb=0;
        }
        if (ca==n) ca=0;
    }
    a = to_string(ca);
    b = to_string(cb);
    while (a.length()<2) a = "0" + a;
    while (b.length()<2) b = "0" + b;
    cout << a << ':' << b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}