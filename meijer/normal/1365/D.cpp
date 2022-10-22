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

const int MX = 5e5;
int testCases;
int n, m;
char gr[1000][1000];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool inside(int x, int y) {return x>=0 && x<n && y>=0 && y<m;}
int g(int x, int y) {return x+n*y;}

int p[MX], r[MX], sets;
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
    cin>>testCases;
    while(testCases--) {
        cin>>n>>m;
        RE(i,n) RE(j,m) cin>>gr[i][j];
        bool pos = 1;
        RE(x,n) RE(y,m) {
            if(gr[x][y] != 'B') continue;
            if(x==n-1&&y==m-1) pos=0;
            RE(d,4) {
                int nx=x+dx[d], ny=y+dy[d];
                if(!inside(nx, ny)) continue;
                if(gr[nx][ny] == 'G') pos=0;
                if(gr[nx][ny] == 'B') continue;
                gr[nx][ny] = '#';
            }
        }
        buildDSU(n*m+1);
        RE(x,n) RE(y,m) {
            if(gr[x][y] == '#') continue;
            RE(d,4) {
                int nx=x+dx[d], ny=y+dy[d];
                if(!inside(nx, ny)) continue;
                if(gr[nx][ny] == '#') continue;
                unionSet(g(x,y),g(nx,ny));
            }
        }
        RE(x,n) RE(y,m) {
            if(gr[x][y] != 'G') continue;
            if(!isSameSet(g(x,y),g(n-1,m-1))) pos=0;
        }
        cout<<(pos ? "Yes" : "No")<<endl;
    }
}