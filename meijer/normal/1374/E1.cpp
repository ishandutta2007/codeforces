#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
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
#define INF 1e18
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
ll n, k, t[MX], a[MX], b[MX];
ll SA[MX], sm[MX][4], cnt[4];

void program() {
    cin>>n>>k;
    RE(i,n) cin>>t[i]>>a[i]>>b[i];
    RE(i,n) SA[i]=i;
    sort(SA,SA+n, [](int i, int j) {
        return t[i]<t[j];
    });
    RE(i,4) sm[0][i] = 0;
    RE(i,n) {
      ll bm=a[SA[i]]+b[SA[i]]*2;
      cnt[bm]++;
      sm[cnt[bm]][bm] = sm[cnt[bm]-1][bm] + t[SA[i]];
    }
    ll ans=INF;
    REI(both,0,min(cnt[3],k)) {
      if(k-both > min(cnt[1], cnt[2]))
        continue;
      ans = min(ans, sm[both][3]+sm[k-both][1]+sm[k-both][2]);
    }
    if(ans==INF) ans=-1;
    cout<<ans<<endl;
}