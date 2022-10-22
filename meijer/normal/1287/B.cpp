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
 
const int MX=2000, MOD=1e9+7;
int n, k;
string s[MX];
int TR[MX*30][3], sz=1;
string T;

int charToI(char c) {
  if(c == 'S') return 0;
  if(c == 'E') return 1;
  if(c == 'T') return 2;
}
void addTrie(int i=0, int p=0) {
  if(TR[p][T[i]] == -1) {
    TR[p][T[i]] = sz;
    RE(j,3) TR[sz][j] = (i == k-2 ? 0 : -1);
    sz++;
  }
  if(i == k-1) {
    TR[p][T[i]]++;
  } else {
    addTrie(i+1, TR[p][T[i]]);
  }
}
int getTrie(int i=0, int p=0) {
  if(p == -1) return 0;
  if(i == k-1) {
    return TR[p][T[i]];
  } else {
    return getTrie(i+1, TR[p][T[i]]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>k;
  RE(i,n) cin>>s[i];
  RE(i,n) RE(j,k) s[i][j] = charToI(s[i][j]);
  if(k != 1) RE(j,3) TR[0][j] = -1;
  ll ans=0;
  T.resize(k);
  RE(i,n) {
    REP(j,i+1,n) {
      RE(l,k) {
        if(s[i][l] == s[j][l]) T[l] = s[i][l];
        string m; m.resize(2); m[0] = s[i][l]; m[1] = s[j][l];
        sort(m.begin(), m.end());
        if(m[0] == 1 && m[1] == 2) T[l] = 0;
        if(m[0] == 0 && m[1] == 2) T[l] = 1;
        if(m[0] == 0 && m[1] == 1) T[l] = 2;
      }
      ans += getTrie();
    }
    T = s[i];
    addTrie();
  }
  cout<<ans<<endl;
}