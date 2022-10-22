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

const int MX = 1500;
int n, m;
char gr[MX][MX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int getPos(int x, int y) {return x+y*n;}
bool inside(int x, int y) {return x>=0 && x<n && y>=0 && y<m;}

int p[MX*MX], r[MX*MX], sets;
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


void program() {
    cin>>n>>m;
    RE(i,n) RE(j,m) cin>>gr[i][j];
    bool possible = 1;
    int cntH=0, cntV=0;
    RE(i,n) {
        int stage = 0;
        RE(j,m) {
            if(gr[i][j] == '#') {
                if((stage % 2) == 0) stage++;
            } else {
                if(stage % 2) stage++;
            }
        }
        if(stage >= 3) possible = 0;
        if(stage != 0) cntH++;
    }
    RE(j,m) {
        int stage = 0;
        RE(i,n) {
            if(gr[i][j] == '#') {
                if((stage % 2) == 0) stage++;
            } else {
                if(stage % 2) stage++;
            }
        }
        if(stage >= 3) possible = 0;
        if(stage != 0) cntV++;
    }
    if((cntH == n) && (cntV != m)) possible = 0;
    if((cntH != n) && (cntV == m)) possible = 0;
    if(!possible) {
        cout<<-1<<endl;
        return;
    }
    buildDSU(n*m);
    sets = 0;
    RE(i,n) RE(j,m) if(gr[i][j]=='#') sets++;
    RE(i,n) RE(j,m) {
        if(gr[i][j] == '#') {
            RE(d,4) {
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(!inside(nx, ny)) continue;
                if(gr[nx][ny] != '#') continue;
                unionSet(getPos(i, j), getPos(nx, ny));
            }
        }
    }
    cout<<sets<<endl;
}