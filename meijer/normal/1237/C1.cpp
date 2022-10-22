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
#define pb push_back
#define fi first
#define se second
#define X fi.fi
#define Y fi.se
#define Z se

const int MX=50000;
vector<pair<ii, int>> coords;
bitset<MX> used;
int SA[MX], x, y, z, n;

bool isInside(pair<ii, int> a, pair<ii, int> b, pair<ii, int> c) {
    if(min(a.X, b.X) <= c.X && c.X <= max(a.X, b.X) &&
       min(a.Y, b.Y) <= c.Y && c.Y <= max(a.Y, b.Y) &&
       min(a.Z, b.Z) <= c.Z && c.Z <= max(a.Z, b.Z))
        return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>x>>y>>z, coords.pb({{x,y},z});
    used.reset();
    RE(i,n) {
        if(used[i]) continue;
        int k=-1;
        RE(j,n) {
            if(j == i) continue;
            if(used[j]) continue;
            if(k == -1) {k = j; continue;}
            if(isInside(coords[i], coords[k], coords[j]))
                k = j;
        }
        used[i]=1;
        used[k]=1;
        cout<<i+1<<" "<<k+1<<endl;
    }
}