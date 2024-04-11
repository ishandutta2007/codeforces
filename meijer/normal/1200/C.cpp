#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

ll n, m, q;
ll gcd;
ll nArea, mArea;

ll GCD(ll a, ll b) {return b==0?a:GCD(b,a%b);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>q;
    gcd = GCD(n, m);
    nArea = n/gcd;
    mArea = m/gcd;
    REP(i,0,q) {
        bool pos;
        ll sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey; sy--; ey--;
        if(sx>ex) swap(sy, ey), swap(sx, ex);
        if(sx == 1 && ex == 1) {
            pos = (sy/nArea) == (ey/nArea);
        } else if(sx == 2 && ex == 2) {
            pos = (sy/mArea) == (ey/mArea);
        } else {
            pos = (sy/nArea) == (ey/mArea);
        }
        cout<<(pos?"YES":"NO")<<endl;
    }
}