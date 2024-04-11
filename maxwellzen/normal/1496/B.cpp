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
int t, n, k, temp;
vi a;
set<int> b;

void solve() {
    cin >> n >> k;
    b.clear();
    F0R(i, n) {
        cin >> temp;
        b.insert(temp);
    }
    bool check = true;
    for (int i = 0; i < b.size(); i++) {
        if (b.find(i)==b.end()) {
            check=false;
            break;
        }
    }
    if (check) {
        cout << b.size()+k << '\n';
        return;
    }
    bool cont = true;
    for (int i = 0; i < k; i++) {
        if (! cont) break;
        cont = false;
        int maxi = *b.crbegin();
        int mex = 0;
        while (b.find(mex)!=b.end()) mex++;
        int add = (maxi+mex+1)/2;
        if (add==mex || add>maxi) cont=true;
        b.insert(add);
    }
    cout << b.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}