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
int n, a[MX], b[MX];
int tot[MX];
int SA[MX];

void program() {
    cin>>n;
    RE1(i,n) cin>>a[i];
    RE1(i,n) cin>>b[i];
    RE(i,n) tot[i] = 0;
    RE1(i,n) SA[a[i]] = i;
    RE1(i,n) {
        tot[(SA[b[i]]-i+n)%n]++;
    }
    int ans=0;
    RE(i,n) ans=max(ans,tot[i]);
    cout<<ans<<endl;
}