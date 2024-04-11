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
int rint();char rch();long long rlong();
const int mn=1e5+4;
string name[mn];
int typ[mn];
int dig2i[mn];
int i2dig[mn];
set<string> alls;
vector<int> notdone[2];
int nume=0;
int n;
vector<pair<string,string> > vans;
vector<int> avail[2];
void pre() {
  if (notdone[0].size()+notdone[1].size()==0) {
    return;
  }
  int special=-1,tt=-1;
  if (avail[0].size()+avail[1].size()==0) {
    for (int i=1;i<=n;i++) {
      string &sname=name[i];
      if (sname.length()==6) alls.insert(sname);
    }
    string randstr; randstr.resize(6);
    while(1) {
      srand(clock());
      for (int i=0;i<6;i++) {
        randstr[i]='a'+rand()%26;
      }
      if (alls.count(randstr)==0) break;
    }
    int idx=-1;
    for (int t=0;t<2;t++) {
      if (notdone[t].size()) {
        idx=notdone[t].back();tt=t;
        break;
      }
    }
    avail[1 - typ[idx]].push_back(i2dig[idx]);
    vans.PB(MP(name[idx],randstr));
    name[idx]=randstr;
    special=idx;
    vector<int> tmp=notdone[tt];
    notdone[tt].clear();
    for (auto &w:tmp) {
      if (w!=special) notdone[tt].PB(w);
    }
  }
  //printf("special:%d\n",special);
  for (int k=0;k<2;k++) {
    while (notdone[0].size() + notdone[1].size() > 0) {
      bool ch = 0;
      //printf("-------\n");
      for (int t = 0; t < 2; t++) {
        //printf("t:%d. nd:%d av:%d\n",t,notdone[t].size(),avail[t^1].size());
        //for (auto &x:notdone[t]) printf("%d ",x); printf("end nd\n");
        //for (auto &x:avail[1^t]) printf("%d ",x); printf("end av\n");
        fflush(stdout);
        if (notdone[t].size() > 0 && avail[t ^ 1].size() > 0) {
          int idx = notdone[t].back();
          notdone[t].pop_back();
          int dest = avail[t ^ 1].back();
          avail[t ^ 1].pop_back();
          if (i2dig[idx] != 0) avail[t].push_back(i2dig[idx]);
          //printf("idx:%d %s t:%d dest:%d push:%d special:%d\n",idx,name[idx].c_str(),t,dest,i2dig[idx],special);
          vans.PB(MP(name[idx], to_string(dest)));
          ch = 1;
        }
      }
    }
    if(special!=-1) {
      notdone[tt].PB(special);
      special=-1;
    }
  }
}
char tmp[10];
vector<int> otherstr[2];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
   scanf("%d\n",&n);
  for (int i=1;i<=n;i++) {
    scanf("%s %d\n", tmp, &typ[i]);
    name[i] = string(tmp);
    if (typ[i] == 1) nume++;
  }
  for (int i=1;i<=n;i++) {
    int len=name[i].length();
    int sum=0;
    for (int k=0;k<len;k++) {
      sum*=10;
      char c=name[i][k];
      if (!('0'<=c&&c<='9')) {
        sum=-1;
        break;
      }
      sum+=c-'0';
      if (sum==0) {sum=-1; break;}
    }
    //printf("i:%d sum:%d len:%d\n",i,sum,len);
    int t=typ[i];
    if (sum<=n&&sum>=1) {
      dig2i[sum]=i;
      i2dig[i]=sum;
      int st=(sum<=nume)?1:0;
      //printf("t:%d st:%d i:%d\n",t,st,i);
      if (t!=st)  {
        notdone[st].push_back(i);
      }
    }
    else otherstr[t].PB(i);
  }
  for (int x=1;x<=nume;x++) if (dig2i[x]==0) avail[1].push_back(x);
  for (int x=nume+1;x<=n;x++) {
    //printf("x:%d i2dig:%d\n",x,i2dig[x]);
    if (dig2i[x]==0) avail[0].push_back(x);
  }
  pre();
  /*for (auto &w:vans) {
    printf("premove %s %s\n",w.fst.c_str(),w.snd.c_str());
  }*/
  fflush(stdout);
  for (int t=0;t<2;t++) {
    for (auto &x: otherstr[t]) {
      //printf("x:%d t:%d\n",x,t); fflush(stdout);
      int dest = avail[t].back();
      avail[t].pop_back();
      //printf("x:%d dest:%d t:%d\n",x,dest,t); fflush(stdout);
      vans.PB(MP(name[x], to_string(dest)));
    }
  }
  printf("%d\n",(int)(vans.size()));
  for (auto &w:vans) {
    printf("move %s %s\n",w.fst.c_str(),w.snd.c_str());
  }
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}