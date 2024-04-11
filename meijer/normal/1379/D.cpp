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
int n, h, m, k;
int H[MX], M[MX];
int SA[MX];

void program() {
    cin>>n>>h>>m>>k;
    RE(i,n) cin>>H[i]>>M[i];
    RE(i,n) if(M[i] >= m/2) M[i] -= m/2;
    RE(i,n) M[i+n]=M[i]+m/2;
    RE(i,n*2) SA[i]=i;
    sort(SA,SA+n*2, [](int i, int j) {
        return M[i]<M[j];
    });

    int ans=INF, aI=0, aJ=0;
    int j = 0;
    RE(i,n) {
        int t = M[SA[i+n]];
        int bg = t-k;
        while(M[SA[j]] <= bg) j++;
        if(i+n-j < ans) {
            ans = i+n-j;
            aI = i, aJ = j;
        }
    }

    cout<<ans<<" "<<M[SA[aI]]<<endl;
    REP(_pi,aJ,aI+n) cout<<(_pi==aJ?"":" ")<<SA[_pi]%n+1; cout<<endl;
}