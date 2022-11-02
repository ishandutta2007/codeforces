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
int n;
vi k;
vector<bool> consider;
set<int> cons;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    k.rsz(n);
    F0R(i, n) cin >> k[i];
    set<array<int, 3>> pairs;
    F0R(i, n) {
        F0R(j, i) {
            pairs.insert({abs(k[i]-k[j]), i, j});
        }
    }
    while (! pairs.empty()) {
        array<int, 3> cur = *--pairs.end();
        pairs.erase(--pairs.end());
        int i=cur[1], j=cur[2];
        if (k[i]>k[j]) {
            i++;
        j++;
            cout << "? " << i << ' ' << j << endl;
            cin >> s;
            if (s=="Yes") {
                cout << "! " << i << ' ' << j << endl;
                return 0;
            }
        } else {
            i++; j++;
            cout << "? " << j << ' ' << i << endl;
            cin >> s;
            if (s=="Yes") {
                cout << "! " << i << ' ' << j << endl;
                return 0;
            }
        }
    }
    cout << "! 0 0" << endl;
    return 0;
}