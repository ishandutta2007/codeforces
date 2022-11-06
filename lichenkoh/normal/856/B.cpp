// http://codeforces.com/contest/825/submission/28619641
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef struct _trie {
  struct _trie * child[26];
  int id;
} trie;
int gid;
trie * newnode() {
  trie *tr = new trie;
  memset(tr->child,0,sizeof(tr->child));
  tr->id=++gid;
  return tr;
}
void ins(trie *tr, string &s, int pos) {
  if (pos==s.length()) return;
  int c=s[pos]-'a';
  if (tr->child[c]==NULL) tr->child[c]=newnode();
  ins(tr->child[c],s,pos+1);
}
const int mn=2e6+4;

vector<int> g[mn];
bool notroot[mn];
void dfs2(trie *r, trie *rr) {
  if (r==NULL||rr==NULL) return;
  //printf("%d->%d\n",rr->id,r->id);
  if (rr->id>=2&&r->id>=2) g[rr->id].PB(r->id);
  if (rr->id>=2) notroot[r->id]=true;
  for (int c=0;c<26;c++) {
    dfs2(r->child[c],rr->child[c]);
  }
}

int dp[mn][2];
int dfs(int id, int pick) {
  if (dp[id][pick]!=-1) return dp[id][pick];
  int ans=pick;
  for (auto &y:g[id]) {
    int toadd;
    if (pick==1) {
      toadd=dfs(y,0);
    }
    else {
      toadd=max(dfs(y,0),dfs(y,1));
    }
    ans+=toadd;
  }
  return dp[id][pick]=ans;
}
void solve() {
  gid=-1;
  int n; cin>>n;
  trie * r=newnode();
  trie *rr=newnode();
  for (int c=0;c<26;c++) rr->child[c]=r;
  for (int i=0;i<n;i++) {
    string s; cin>>s; ins(r,s,0);
  }
  dfs2(r,rr);
  for (int id=0;id<=gid;id++) {
    sort(g[id].begin(),g[id].end());
    auto it=unique(g[id].begin(),g[id].end());
    g[id].resize(distance(g[id].begin(),it));
  }
  memset(dp,-1,sizeof(dp[0])*(1+gid));
  int ans=0;
  for (int id=2;id<=gid;id++) {
    if (!notroot[id]) {
      int got=max(dfs(id,0),dfs(id,1));
      //printf("id:%d. got:%d\n",id,got);
      ans+=got;
    }
  }
  printf("%d\n",ans);
  memset(notroot,0,sizeof(notroot[0])*(1+gid));
  for (int id=0;id<=gid;id++) {
    g[id].clear();
  }
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests; cin>>tests;
  for (int i=0;i<tests;i++) solve();
}