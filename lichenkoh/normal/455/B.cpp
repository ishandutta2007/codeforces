#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
typedef string::iterator I;
typedef char T;
const char offset='a';
const int LOSE=0,WIN=1;
struct trie {
  struct node {
      node* children[26];
      bool force[2];
      node() {memset(children,0,sizeof children); force[0]=force[1]=0;} };
  node* root;
  trie() : root(new node()) {  }
  void insert(I begin, I end) {
      node* cur = root;
      while (true) {
          if (begin == end) {break; }
          else {
              T head = (*begin) - offset;
              node *nxt = cur->children[head];
              if (nxt==NULL) {
                node *newnode=new node();
                cur->children[head]=newnode;
                nxt=newnode;
              }
              ++begin;
              cur = nxt;
          }
        }
  }
  void dfs(node *v) {
    bool haschild=0;
    for (int c=0;c<26;c++) {
      node *child=v->children[c];
      if (child!=NULL) {
        dfs(child); haschild=1;
        for (int k=0;k<2;k++) {
          if (!(child->force[k])) v->force[k]=true;
        }
      }
    }
    if (!haschild) {
      v->force[LOSE]=true;
      v->force[WIN]=false;
    }
    dbg("v:%x LOSE:%d WIN:%d.\n",v,v->force[LOSE],v->force[WIN]);
  }
};
const int matn=2,matm=2;
typedef bool mat[matn][matn];
void matrixUnit(mat &res) {
    memset(res,0,sizeof res);
    for (ll i = 0; i < matn; i++)
        res[i][i] = 1;
}

void matrixMult(mat &res, const mat &a, const mat &b) {
    int n = matn;
    int m = matn;
    int k = matn;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
        {
          bool ans=0;
            for (ll p = 0; p < m; p++)
                ans = (ans || (a[i][p] && b[p][j]));
          res[i][j]=ans;
        }
}
void matMove(mat &dest, const mat &src) {
  int n=matn,m=matm;
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) dest[i][j]=src[i][j];
}
void matrixPow(mat &ans, const mat &a, ll p) {
  ll oldp=p;
  mat base; matMove(base,a);
  matrixUnit(ans);
  mat tmp; memset(tmp,0,sizeof tmp);
  while(p>0) {
    if (p&1) {
      matrixMult(tmp,ans,base);
      matMove(ans,tmp);
    }
    matrixMult(tmp,base,base);
    matMove(base,tmp);
    p>>=1;
  }
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,k; cin>>n>>k;
  trie t;
  for (int x=0;x<n;x++) {
    string s; cin>>s;
    t.insert(s.begin(),s.end());
  }
  t.dfs(t.root);
  mat M;
  M[0][0]=t.root->force[LOSE];
  M[1][0]=t.root->force[WIN];
  dbg("LOSE:%d WIN:%d\n",t.root->force[LOSE],t.root->force[WIN]);
  M[0][1]=!(t.root->force[LOSE]);
  M[1][1]=!(t.root->force[WIN]);
  mat res;matrixPow(res,M,k);
  //for (int i=0;i<2;i++) for (int j=0;j<2;j++) printf("i:%d j:%d res:%d\n")
  if (res[1][0]) printf("First\n");
  else printf("Second\n");
}