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

const int MX = 5e5;
ll t, n, a[MX];

void program() {
    cin>>t;
    while(t--) {
        cin>>n;
        RE(i,n) cin>>a[i];
        ll tot=0;
        ll curMax=0;
        RE(i,n) {
            if(i == 0 || ((a[i-1] < 0) != (a[i] < 0))) {
                tot += curMax;
                curMax = a[i];
            } else {
                curMax = max(curMax, a[i]);
            }
        }
        tot += curMax;
        cout<<tot<<endl;
    }
}