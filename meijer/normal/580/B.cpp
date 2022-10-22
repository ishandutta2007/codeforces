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
ll n, d, m[MX], s[MX], SA[MX];

void program() {
    cin>>n>>d;
    RE(i,n) cin>>m[i]>>s[i];
    RE(i,n) SA[i]=i;
    sort(SA,SA+n, [](int i, int j) {
        return m[i]<m[j];
    });
    ll ans=0;
    ll cur=0;
    int i=0;
    RE(j,n) {
        cur += s[SA[j]];
        while(m[SA[j]]-m[SA[i]] >= d)
            cur -= s[SA[i++]];
        ans = max(ans, cur);
    }
    cout<<ans<<endl;
}