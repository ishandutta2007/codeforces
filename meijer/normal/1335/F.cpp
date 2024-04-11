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

const int MX = 1e6+10;
int testCases;
int n, m, N;
map<char, int> d;
bool white[MX];
int nxt[MX], ed[MX][2];

int P(int i, int j) {
    return i+j*n;
}
int LOG2(int x) {
    if(x <= 1) return 0;
    return 1+LOG2(x/2);
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>m;
        d['U'] = P(-1, 0);
        d['R'] = P(0, 1);
        d['D'] = P(1, 0);
        d['L'] = P(0, -1);
        RE(i,n) RE(j,m) {
            char c; cin>>c;
            white[P(i,j)] = (c=='1');
        }
        RE(i,n) RE(j,m) {
            char c; cin>>c;
            nxt[P(i,j)] = P(i,j) + d[c];
        }
        N = n*m;
        RE(i,N) ed[i][0] = nxt[i];
        int lg = LOG2(N)+2;
        RE(j,lg) RE(i,N) ed[i][!(j%2)] = ed[ed[i][j%2]][j%2];
        set<int> all, black;
        RE(i,N) {
            all.insert(ed[i][0]);
            if(!white[i]) black.insert(ed[i][0]);
        }
        cout<<all.sz<<" "<<black.sz<<endl;
    }
}