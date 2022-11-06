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
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

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

int readInt()
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


#define mid(L,R) ((L+R)/2)
struct Node{ int cnt , L , R;
    Node()
    {
        cnt=0;
        L = R = -1;
    }
    Node(int x,int y,int z)
    {
        L = x;
        R = y;
        cnt = z;
    }
}tree[8160001];

int G[1000001];
int A[100001],root[100001],RM[100001],B[100001],V[100001];
int gc = 0 , N;

int build(int L , int R)
{
    ++gc;
    if(L==R)
        return gc;
    int x = gc;
    tree[x] = Node(build(L,mid(L,R)),build(mid(L,R)+1,R),0);
    return x;
}


int update(int L , int R , int root , int idx , int val)
{
    if(L>idx || R<idx)
        return root;
    ++gc;
    if(L==idx&&R==idx)
    {
        tree[gc] = Node(-1,-1,tree[root].cnt+val);
        return gc;
    }
    int x = gc;
    tree[x]=Node(update(L,mid(L,R),tree[root].L,idx,val),update(mid(L,R)+1,R,tree[root].R,idx,val),tree[root].cnt+val);
    return x;
}

int query(int L , int R , int root , int qe , int qr)
{
    if(qr<L || qe>R)return 0;
    if(qe<=L && R<=qr)
        return tree[root].cnt;
    return query(L,mid(L,R),tree[root].L,qe,qr)+
            query(mid(L,R)+1,R,tree[root].R,qe,qr);
}

int go(int L , int R , int root, int lim)
{
  if (L==R) return L;
  ll right=tree[root].R;
  ll right_cnt=tree[right].cnt;
  if (lim<right_cnt) {
    return go(mid(L,R)+1,R,tree[root].R,lim);
  }
  else {
    return go(L,mid(L,R),tree[root].L, lim-right_cnt);
  }
}

/*int main()
{
    int  M , i , x , y , z;
    N  = readInt();
    memset(G,-1,sizeof(G));
    for(i=1;i<=N;++i){A[i]=readInt();}
    root[0] = build(1,N);
    for(i=1;i<=N;++i)
    {
        int p = root[i-1];
        if(G[A[i]]!=-1)
            p = update(1,N,p,G[A[i]],-1);
        root[i] = update(1,N,p,i,1);
        G[A[i]]=i;
    }
    //{
    //  int x=1,y=N;
    //  printf("%d\n",query(1,N,root[y],x,y));
    //}
    for (int k=1;k<=N;k++) {
      int ans=0;
      int y=N;
      while(y>0) {
        int l=go(1,N,root[y],k);
        //printf("k:%d y:%d l:%d\n",k,y,l);
        ans++;
        if (l==1&&query(1,N,root[y],1,y)<=k) l--;
        y=l;
      }
      printf("%d ",ans);
    }
    printf("\n");

    return 0;
}*/

void buildseg(int n) {
  // A must be one-indexed, and contain values 1<=value<=N
  N=n;
  memset(G,-1,sizeof(G));
  root[0] = build(1,N);
  for(int i=1;i<=N;++i)
  {
      int p = root[i-1];
      if(G[A[i]]!=-1)
          p = update(1,N,p,G[A[i]],-1);
      root[i] = update(1,N,p,i,1);
      G[A[i]]=i;
  }
}

void coordcompr(ll *inp, ll *tmp, int n) {
  memcpy(tmp,inp,sizeof(inp[0])*n);
  sort(tmp,tmp+n);
  vector<ll> dist;
  dist.PB(tmp[0]);
  for (int i=1;i<n;i++) {
    if (tmp[i]!=tmp[i-1]) dist.PB(tmp[i]);
  }
  int dsz=(int)dist.size();
  for (int i=0;i<n;i++) {
    int imin=0,imax=dsz;
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (dist[imid]<inp[i]) imin=imid+1;
      else imax=imid;
    }
    //printf("key:%d imin:%d\n",key,imin);
    inp[i]=imin;
  }
}

const int mn=100001;
int vmod[mn];
ll inp[mn], tmp[mn];
int main() {
  int n=readInt(),k=readInt();
  for (int i=0;i<n;i++) {
    int x=readInt();
    inp[i]=((ll)x*(ll)k+vmod[x]);
    vmod[x]++;
    if (vmod[x]>=k) vmod[x]-=k;
  }
  coordcompr(inp,tmp,n);
  for (int i=n-1;i>=0;i--) {
    A[i+1]=inp[i]+1;
  }
  A[0]=0;
  //for (int i=1;i<=n;i++) printf("%d ",A[i]);
  //printf("\n"); meow
  buildseg(n);
  int q=readInt();
  int last=0;
  for (int i=0;i<q;i++) {
    int x=readInt(),y=readInt();
    int l=x+last; l%=n; l++;
    int r=y+last; r%=n; r++;
    if (l>r) swap(l,r);
    //printf("l:%d r:%d\n",l,r);
    int ans=query(1,N,root[r],l,r);
    printf("%d\n",ans);
    last=ans;
  }
}