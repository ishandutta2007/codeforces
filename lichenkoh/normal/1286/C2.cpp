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
int queries=0;
multiset<string> ask(int l, int r) {
  cout<<"? "<<l+1<<" "<<r+1<<endl<<flush;
  cout.flush();
  multiset<string> h;
  int len=r-l+1;
  int t=(len*(len+1))/2;
  for (int i=0;i<t;i++) {
    string s; cin>>s;
    sort(s.begin(),s.end());
    h.insert(s);
    queries++;
  }
  return h;
}

string solveWith2Queries(int n) {
  multiset<string> all=ask(0,n-1);
  if (n==1) {
    return *(all.begin());
  }
  multiset<string> twoToN=ask(1,n-1);
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
  return ans;
}

vi solve01(vi front01, vvi back, int n, int l, int startguess, int r, char c) {
  vi ans=front01; ans.resize(n);
  int backlen=r-l+1;
  assert(back.size()==backlen+1);
  int firstsum=back[backlen][0];
  for (int pos=r,windowlen=backlen-1;pos>=startguess;pos--,windowlen--) {
    sort(back[windowlen].begin(),back[windowlen].end());
    for (int guess=0;guess<2;guess++) {
      ans[pos]=guess;
      int windowsum=firstsum-guess;
      vi sliding = {windowsum};
      for (int x=l,y=l+windowlen;y<n;x++,y++) {
        windowsum+=ans[y]-ans[x];
        sliding.PB(windowsum);
      }
      sort(sliding.begin(),sliding.end());

      /*if (c=='a') {
        printf("guess:%d pos:%d windowlen:%d",guess,pos,windowlen);
        for (auto &w:sliding) printf("%d ",w); printf(" sliding\n");
        for (auto &w:back[windowlen]) printf("%d ",w); printf(" back\n");
      }*/

      if (sliding==back[windowlen]) {
        firstsum-=guess;
        break;
      }
    }
  }
  return ans;
}

string solveWith3Queries(int n) {
  int third=((n+2)/3);
  int twothirds=min(n,2*third);

  string front=solveWith2Queries(twothirds);
  if (twothirds==n) return front;

  int l=third,r=n-1,startguess=2*third;
  int backlen=r-l+1;
  multiset<string> back=ask(l,r);
  string ans=front; ans.resize(n);
  for (char c='a';c<='z';c++) {
    vi front01(front.size());
    for (int i=0;i<front.size();i++) front01[i]=(front[i]==c)?1:0;
    vvi back01(backlen+1);
    for (auto &s:back) {
      int cnt=0;
      for (auto &x:s) {
        if (x==c) cnt++;
      }
      back01[s.length()].PB(cnt);
    }
    vi result=solve01(front01,back01,n,l,startguess,r,c);
    for (int pos=startguess;pos<=r;pos++) {
      if (result[pos]) ans[pos]=c;
    }
  }
  return ans;

}

int main() 
{
  int n; cin>>n;
  string final = solveWith3Queries(n);
  cout<<"! "<<final<<endl<<flush; cout.flush();
  /*int querylim=ceil(0.777*(n+1)*(n+1));
  if (queries>querylim) cout<<("Queries exceeded\n")<<endl;*/
}