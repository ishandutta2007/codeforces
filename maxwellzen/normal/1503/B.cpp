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
int n, nsq, a, add;
set<pi> e, o;
pi cur;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    nsq = n*n;
    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            if ((i+j)%2==0) e.insert(mp(i, j));
            else o.insert(mp(i, j));
        }
    }
    while (! (e.empty()&&o.empty())) {
        cin >> a;
        if (e.empty() || (o.size()>0 && a==1)) {
            if (a==2) add=3;
            else add=2;
            cur=*o.begin();
            o.erase(o.begin());
            cout << add << ' ' << cur.F << ' ' << cur.S << endl;
        } else {
            if (a==1) add=3;
            else add=1;
            cur=*e.begin();
            e.erase(e.begin());
            cout << add << ' ' << cur.F << ' ' << cur.S << endl;
        }
    }
}