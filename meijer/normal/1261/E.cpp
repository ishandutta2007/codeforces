#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
 
const ll MX=1009, MOD=1e9+7;
int n, a[MX];
bitset<MX> bs[MX];
bitset<MX> different;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  RE(i,n) cin>>a[i];
  different.reset();
  different[n] = 1;
  RE(i,n) {
    int onesLeft=a[i];
    queue<int> q;
    bool first=1;
    RE(j,n+1) {
      if(onesLeft > 0) {
        if(different[j]) {
          bs[j][i] = 0;
          q.push(j);
          continue;
        }
        if(first && different[j+1]) {
          different[j] = 1;
          bs[j][i] = 1;
          j++;
          onesLeft--;
          first = 0;
        } else {
          bs[j][i] = 1;
          onesLeft--;
          if(onesLeft == 0)
            different[j] = 1;
        }
      } else {
        bs[j][i] = 0;
      }
    }
    while(onesLeft > 0) {
      onesLeft--;
      bs[q.front()][i] = 1;
      q.pop();
    }
  }
  cout<<n+1<<endl;
  RE(i,n+1) {
    RE(j,n) cout<<bs[i][j]; cout<<endl;
  }
}