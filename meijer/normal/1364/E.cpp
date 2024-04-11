#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;

int n;
int p[MX];
bitset<MX> found;

int randomNumber(int x) {
    int y = x;
    while(y == x) y = rng()%n;
    return y;
}
int ask(int i, int j) {
    cout<<"? "<<i+1<<" "<<j+1<<endl;
    cout.flush();
    int ret; cin>>ret;
    return ret;
}
int getNumber(int x) { // takes 20 queries
    int bm = (1<<12)-1;
    RE(i,20)
        bm &= ask(x,randomNumber(x));
    return bm;
}

void program() {
    cin>>n;
    found.reset();

    vii a;
    RE(i,8) {
        if(i >= n) break;
        int u = rng()%n;
        while(found[u]) u = rng()%n;
        found[u] = 1;
        p[u] = getNumber(u);
        a.push_back({u, p[u]});
    }

    int x, y;
    RE(i,8) RE(j,8) {
        if(i == j) continue;
        if((a[i].se & a[j].se) == 0) {
            x = i; y = j;
        }
    }

    RE(i,n) {
        if(found[i]) continue;
        p[i] = 0;
        p[i] |= (~a[x].se)&ask(a[x].fi,i);
        p[i] |= (~a[y].se)&ask(a[y].fi,i);
    }

    cout<<"! ";
    RE(_pi,n) cout<<(_pi==0?"":" ")<<p[_pi]; cout<<endl;
}