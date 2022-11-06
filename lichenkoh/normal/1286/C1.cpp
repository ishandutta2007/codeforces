#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<vvi> vvvi;
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());

multiset<string> ask(int l, int r) {
  cout<<"? "<<l<<" "<<r<<endl<<flush;
  cout.flush();
  multiset<string> h;
  int len=r-l+1;
  int t=(len*(len+1))/2;
  for (int i=0;i<t;i++) {
    string s; cin>>s;
    sort(s.begin(),s.end());
    h.insert(s);
  }
  return h;
}

int main() 
{
  int n; cin>>n;
  multiset<string> all=ask(1,n);
  if (n==1) {
    cout<<"! "<<*(all.begin())<<endl<<flush; cout.flush();
    return 0;
  }
  multiset<string> twoToN=ask(2,n);
  for (auto &w:twoToN) {
    assert(all.find(w)!=all.end());
    all.erase(all.find(w));
  }
  vector<multiset<char> > len2s(n+1);
  for (auto &w:all) {
    multiset<char> cs;
    for (auto &c:w) {
      cs.insert(c);
    }
    len2s[w.length()]=cs;
  }
  string ans; ans.resize(n);
  for (int t=n;t>=2;t--) {
    multiset<char> big=len2s[t],small=len2s[t-1];
    for (auto &c:small) {
      assert(big.find(c)!=big.end());
      big.erase(big.find(c));
    }
    assert(big.size());
    ans[t-1]=*(big.begin());

  }
  {
    multiset<char> big=len2s[n];
    for (int i=1;i<n;i++) {
      char c=ans[i];
      assert(big.find(c)!=big.end());
      big.erase(big.find(c));
    }
    assert(big.size());
    ans[0]=*(big.begin());
  }
  cout<<"! "<<ans<<endl<<flush;
  cout.flush();

}