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
ll n, s[MX], e[MX];

bool win(ll S, ll E) {
  if(E%2) return (S%2)==0;
  if(S > E) return 1;
  if(S > E/2) return S%2;
  if(S > E/4) return 1;
  return win(S, E/4);
}
bool lose(ll S, ll E) {
  if(S*2 > E) return 1;
  return win(S,E/2);
}

bitset<MX> smWin, smLose;
bool dp[MX][2];

void program() {
    cin>>n;
    RE(i,n) cin>>s[i]>>e[i];
    smWin.reset(); smLose.reset();

    bool w=0;
    bool l=1;
    RE(i,n) {
      if(w && l) break;
      if(!w && !l) break;
      if(w) {
        w = !win (s[i], e[i]);
        l = !lose(s[i], e[i]);
      } else {
        w = win (s[i], e[i]);
        l = lose(s[i], e[i]);
      }
    }
    cout<<w<<" "<<l<<endl;
}