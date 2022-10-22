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
int testCases;
int n, m, p[MX];
bitset<MX> rem;
int a[MX];

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n;
        RE(i,n) cin>>p[i];

        rem.reset();
        RE(i,n-2) {
            if(p[i] < p[i+1] && p[i+1] < p[i+2]) {
                rem[i+1] = 1;
            }
            if(p[i] > p[i+1] && p[i+1] > p[i+2]) {
                rem[i+1] = 1;
            }
        }
        m = 0;
        RE(i,n) if(!rem[i]) a[m++] = p[i];

        cout<<m<<endl;
        RE(_pi,m) cout<<(_pi==0?"":" ")<<a[_pi]; cout<<endl;
    }
}