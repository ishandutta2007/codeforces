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
int n, a[MX], SA[MX], p[MX];
vector<int> swaps;

void doSwap(int x) {
  swaps.pb(x+1);
  int tp[3];
  RE(i,3) tp[i] = p[x+i];
  RE(i,3) p[x+i] = tp[(i+2)%3];
  RE(i,3) SA[p[x+i]] = x+i;
}

void program() {
  cin>>testCases;
  while(testCases--) {
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) SA[i]=i;
    sort(SA,SA+n, [](int i, int j) {
      return a[i]<a[j];
    });
    RE(i,n) p[SA[i]] = i;

    int inv = 0;
    RE(i,n) REP(j,i+1,n)
      if(p[j] < p[i]) inv++;
    if(inv % 2) {
      bool found=0;
      RE(i,n-1) {
        if(a[SA[i]] == a[SA[i+1]]) {
          swap(p[SA[i]], p[SA[i+1]]);
          swap(SA[i], SA[i+1]);
          found = 1;
          break;
        }
      }
      if(!found) {
        cout<<-1<<endl;
        continue;
      }
    }
    
    swaps.clear();
    RE(i,n-2) {
      while(SA[i] != i) {
        int x = SA[i]-2;
        if(x < i) x = i;
        doSwap(x);
      }
    }

    cout<<swaps.sz<<endl;
    RE(_pi,swaps.sz) cout<<(_pi==0?"":" ")<<swaps[_pi]; cout<<endl;
  }
}