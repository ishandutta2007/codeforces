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
int n, m, gr[1000][1000];

int mx(int x) {return n-x-1;}
int my(int y) {return m-y-1;}

bool inside(int x, int y) {return x>=0 && x<n && y>=0 && y<m;}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>m;
        RE(i,n) RE(j,m) cin>>gr[i][j];
        int len = n+m-1;
        int p = len/2;
        int ans=0;
        RE(i,p) {
            int x=i, y=0;
            int c[2];
            c[0]=c[1]=0;
            RE(j,len+1) {
                if(inside(x, y)) {
                    c[gr[x][y]]++;
                    c[gr[mx(x)][my(y)]]++;
                }
                x--;
                y++;
            }
            ans += min(c[0], c[1]);
        }
        cout<<ans<<endl;
    }
}