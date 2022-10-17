#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef pair<int,int> pii;

const int N = 100100, S = 1100000;
int n;
string s[N];
char ss[S];
map<pair<int,char>, vector<int> > v;
map<int, vector<int> > vv;
vector<pii> fst,snd;

int main() {
  scanf("%d",&n);
  REP(i,n) {
    scanf("%s",ss);
    s[i] = ss;
    int cnt = 0; char last = -1;
    FORE(j,s[i]) if (*j == 'a' || *j == 'e' || *j == 'o' || *j == 'i' || *j == 'u') {
      ++cnt; last = *j;
    }
    v[make_pair(cnt, last)].push_back(i);
  }
  FORE(i,v) {
    vector<int>& w = i->second;
    while (w.size() >= 2) {
      pii p = make_pair(w[w.size()-1], w[w.size()-2]);
      w.resize(w.size()-2);
      snd.push_back(p);
    }
    FORE(j,w) vv[i->first.first].push_back(*j);
  }

  FORE(i,vv) {
    vector<int>& w = i->second;
    while (w.size() >= 2) {
      pii p = make_pair(w[w.size()-1], w[w.size()-2]);
      w.resize(w.size()-2);
      fst.push_back(p);
    }
  }

  while (fst.size() + 2 <= snd.size()) {
    fst.push_back(snd.back());
    snd.pop_back();
  }

  int ans = min(fst.size(), snd.size());
  printf("%d\n", ans);
  REP(i,ans) {
    printf("%s %s\n%s %s\n",
        s[fst[i].first].c_str(), s[snd[i].first].c_str(),
        s[fst[i].second].c_str(), s[snd[i].second].c_str());
  }
}