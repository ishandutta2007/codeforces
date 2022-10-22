#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
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

const ll MX = 1001, MX2=2e5;
ll n, m, t;
bool gr[MX][MX];
bool good[MX][MX];
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
ll goodCount = 0;
ll I[MX2], J[MX2], P[MX2], SA[MX2], ans[MX2];

bool inside(ll x, ll y) {return x>=0 && x<n && y>=0 && y<m;}
bool isGood(ll i, ll j) {
    RE(d,4) {
        ll ni=i+dx[d], nj=j+dy[d];
        if(!inside(ni, nj)) continue;
        if(gr[i][j] == gr[ni][nj]) return 1;
    }
    return 0;
}

void program() {
    cin>>n>>m>>t;
    RE(i,n) RE(j,m) {
        char c; cin>>c;
        gr[i][j] = (c=='1');
    }
    RE(i,n) RE(j,m) good[i][j] = isGood(i,j);
    RE(i,n) RE(j,m) if(good[i][j]) goodCount++;
    if(goodCount == 0) {
        RE(T,t) {
            ll i, j, p;
            cin>>i>>j>>p; i--; j--;
            cout<<gr[i][j]<<endl;
        }
        return;
    }
    RE(i,t) cin>>I[i]>>J[i]>>P[i], I[i]--, J[i]--;
    RE(i,t) SA[i] = i;
    sort(SA, SA+t, [](ll i, ll j) {
        return P[i]<P[j];
    });
    queue<ii> q[2];
    bool cur=0;
    RE(i,n) RE(j,m) if(good[i][j]) q[cur].push({i,j});
    ll curP=1;
    ll curSA=0;
    while(!q[cur].empty()) {
        while(!q[cur].empty()) {
            ii p = q[cur].front(); q[cur].pop();
            RE(d,4) {
                ll nx=p.fi+dx[d], ny=p.se+dy[d];
                if(!inside(nx, ny)) continue;
                if(good[nx][ny] == 0) {
                    good[nx][ny] = 1;
                    q[!cur].push({nx,ny});
                    if(!cur) gr[nx][ny] = !gr[nx][ny];
                }
            }
        }
        while(curSA != t && P[SA[curSA]] <= curP) {
            ll T = SA[curSA];
            bool curAns = gr[I[T]][J[T]];
            if(good[I[T]][J[T]] && (curP%2)) curAns = !curAns;
            ans[SA[curSA]] = curAns;
            curSA++;
        }
        cur = !cur;
        curP++;
    }
    while(curSA != t) {
        ll T = SA[curSA];
        bool curAns = gr[I[T]][J[T]];
        if(good[I[T]][J[T]] && (P[SA[curSA]]%2)) curAns = !curAns;
        ans[SA[curSA]] = curAns;
        curSA++;
    }
    RE(i,t) cout<<ans[i]<<endl;
}