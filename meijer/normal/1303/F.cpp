#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
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

const int MX = 2e6+10, MX2=301;
int n, m, q;
int x, y, c;
int ans[MX];
int gr[MX2][MX2];
vii bg[MX], ed[MX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool inside(int x, int y) {return x>=0 && x<n && y>=0 && y<m;}
int P(int i, int j) {return i+j*n;}

int p[MX2*MX2], r[MX2*MX2], sets;
void buildDSU(int dsuSize) {
    RE(i,dsuSize) p[i]=i, r[i]=0;
    sets = dsuSize;
}
int getSet(int i) {return i==p[i]?i:p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
        i=p[i], j=p[j];
        sets--;
        if(r[i] > r[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if(r[i] == r[j]) r[j]++;
        }
    }
}
void process(vii& v, int amount) {
    RE(i,n) RE(j,m) gr[i][j] = 0;
    buildDSU(n*m);
    for(ii pr:v) {
        ans[pr.se] += amount;
        int x=pr.fi%n, y=pr.fi/n;
        gr[x][y] = 1;
        RE(d,4) {
            int cx = x+dx[d];
            int cy = y+dy[d];
            if(!inside(cx,cy)) continue;
            if(gr[cx][cy] == 1 && !isSameSet(P(x,y), P(cx, cy))) {
                unionSet(P(x,y), P(cx, cy));
                ans[pr.se] -= amount;
            }
        }
    }
}

void program() {
    scanf("%d%d%d",&n,&m,&q);
    RE(i,n) RE(j,m) gr[i][j] = 0;
    RE(i,q) {
        scanf("%d%d%d",&x,&y,&c); x--; y--;
        if(gr[x][y] == c) continue;
        ed[gr[x][y]].pb({P(x,y), i});
        gr[x][y] = c;
        bg[gr[x][y]].pb({P(x,y), i});
    }
    RE(i,n) RE(j,m) ed[gr[i][j]].pb({P(i,j), q});

    c += 1;
    RE(i,c) reverse(ed[i].begin(), ed[i].end());
    RE(i,c) process(bg[i],  1);
    RE(i,c) process(ed[i], -1);

    ans[0]++;
    RE(i,q) ans[i+1] += ans[i];
    RE(i,q) printf("%d\n", ans[i]);
}