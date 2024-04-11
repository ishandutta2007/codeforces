#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

const int mn=1e5+4;
string a[mn];
int al[mn];
set<char> gin[256], gout[256]; bool seen[256];
int n;
string ans;
void fail() {
  printf("NO\n"); exit(0);
}
void dfs(char c) {
  if (seen[c]) fail();
  seen[c]=true;
  ans+=c;
  if (gout[c].size()>=2) fail();
  if (gout[c].size()==1) dfs(*(gout[c].begin()));
}
bool occ[256];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n;
  for (int x=0;x<n;x++) {
    cin>>a[x];
    al[x]=a[x].length();
    for (auto &c:a[x]) {
      occ[c]=true;
    }
    for (int p=1;p<al[x];p++) {
      char c1=a[x][p-1];
      char c2=a[x][p];
      gout[c1].insert(c2);
      gin[c2].insert(c1);
    }
  }
  //printf("1\n");
  for (int c='a';c<='z';c++) {
    if (gin[c].size()>=2||gout[c].size()>=2) fail();
  }
  //printf("2\n");
  for (int c='a';c<='z';c++) {
   //printf("%c %d %d\n",c,gin[c].size(),occ[c]);
    if (gin[c].size()==0&&occ[c]) {
      dfs(c);
    }
  }
  //printf("3\n");
  //cout<<ans<<endl;
  if (ans.size()>=50) fail();
  //printf("4\n");
  for (int x=0;x<n;x++) {
    if(string::npos==ans.find(a[x])) fail();
  }
  cout<<ans<<endl;
}