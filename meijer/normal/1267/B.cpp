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
 
const ll MX=3e5, MOD=1e9+7;

int n, m;
string s;
int cnt[MX];
char type[MX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>s; n = s.size();
  char last=' ';
  int sz=0;
  RE(i,n) {
    if(last != s[i]) {
      if(last != ' ') {
        type[m] = last;
        cnt[m++] = sz;
      }
      last = s[i];
      sz = 0;
    }
    sz++;
  }
  type[m] = last;
  cnt[m++] = sz;
  bool pos = 1;
  if(cnt[m/2]==1) pos = 0;
  if(m % 2) {
    RE(i,m/2) {
      if(type[i] != type[m-i-1]) pos = 0;
      if(cnt[i] + cnt[m-i-1] < 3) pos = 0;
    }
  } else pos = 0;
  if(pos) {
    cout<<cnt[m/2]+1<<endl;
  } else {
    cout<<0<<endl;
  }
}