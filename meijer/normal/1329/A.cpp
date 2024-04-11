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
ll n, m, l[MX];
ll SA[MX], ans[MX];

void program() {
    cin>>n>>m;
    RE(i,m) cin>>l[i];
    if(m > n) {
        cout<<-1<<endl;
        return;
    }
    ll tot=0;
    RE(i,m) tot += l[i];
    if(tot < n) {
        cout<<-1<<endl;
        return;
    }
    RE(i,m) SA[i] = i;
    bool pos = 1;
    ll rem = tot-n;
    ll cur = 1;
    RE(i,m) {
        ll canRem = l[SA[i]]-1;
        if(cur > n-l[SA[i]]+1) pos = 0;
        if(canRem > rem) {
            l[SA[i]] -= rem;
            rem = 0;
        } else {
            l[SA[i]] = 1;
            rem -= canRem;
        }
        ans[SA[i]] = cur;
        cur += l[SA[i]];
    }
    if(!pos) {
        cout<<-1<<endl;
        return;
    }
    RE(i,m) cout<<(i==0?"":" ")<<ans[i]; cout<<endl;
}