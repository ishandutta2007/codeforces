#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9

const int MX=2e3, MOD=1e9 + 7;
int h, w;
int r[MX], c[MX];
bitset<MX> used[MX];
bitset<MX> col[MX];
bool pos = 1;

void setCol(int x, int y, bool ncol) {
    if(used[x][y])
        if(col[x][y] != ncol)
            pos=0;
    used[x][y] = 1;
    col[x][y] = ncol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>w;
    RE(i,w) used[i].reset();
    RE(i,h) cin>>r[i];
    RE(i,w) cin>>c[i];
    RE(i,h) {
        RE(j,r[i])
            setCol(j, i, 1);
        setCol(r[i], i, 0);
    }
    RE(i,w) {
        RE(j,c[i])
            setCol(i, j, 1);
        setCol(i, c[i], 0);
    }
    if(!pos) {cout<<0<<endl; return 0;}
    int cnt=0;
    RE(i,w) RE(j,h) {
        if(!used[i][j]) cnt++;
    }
    ll ans=1;
    RE(i,cnt) {
        ans *= 2;
        ans %= MOD;
    }
    cout<<ans<<endl;
}