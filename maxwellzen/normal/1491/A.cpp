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
int t, n, q, num, k;
vi a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    a.rsz(n);
    F0R(i, n) cin >> a[i];
    num = 0;
    F0R(i, n) if (a[i]==1) num++;
    F0R(i, q) {
        cin >> t >> k;
        if (t==1) {
            k--;
            if (a[k]==1) {
                num--;
                a[k]=0;
            } else {
                num++;
                a[k]=1;
            }
        } else {
            if (num >= k) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    return 0;
}