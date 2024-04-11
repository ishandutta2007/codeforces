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
int n, x, m;
int l[MX], r[MX];

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>x>>m;
        RE(i,m) cin>>l[i]>>r[i];
        int lb=x, ub=x;
        RE(i,m) {
            if(l[i] >= lb && l[i] <= ub) ub = max(ub, r[i]);
            if(r[i] >= lb && r[i] <= ub) lb = min(lb, l[i]);
            if(l[i] <= lb && r[i] >= ub) ub = r[i], lb = l[i];
        }
        cout<<ub-lb+1<<endl;
    }
}