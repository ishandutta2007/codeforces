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
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=2e6+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (ll x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
ll binom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

ll starbar(ll stars, ll parts) {
  if (parts==0) {
    return (stars==0)?1:0;
  }
  if (parts<=0||stars<0) return 0;
  return binom(stars+parts-1,parts-1);
}

const int mn=1e6+3;
ll p[mn];
const int MAXN=mn;
ll t[MAXN];
ll v[MAXN];
// T[i] += value
void add(ll *t, ll i, ll value) {
  for (; i < MAXN; i |= i + 1)
    t[i] += value;
}

  // sum[0..i]
ll sum(ll *t, ll i) {
  ll res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += t[i];
  return res;
}

ll f(ll n) {
  return mul(mul(fact[n],binom(n,2)),invfact[2]);
}
ll arith(ll n) {
  return mul(mul(n,n+1),invfact[2]);
}


 
ll  _mergeSort(ll arr[], ll temp[], ll left, ll right);
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right);
 
/* This function sorts the input array and returns the
   number of inversions in the array */
ll mergeSort(ll arr[], ll array_size)
{
    ll *temp = (ll *)malloc(sizeof(ll)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
ll _mergeSort(ll arr[], ll temp[], ll left, ll right)
{
  ll mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array llo two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
 
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
 
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
 
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right)
{
  ll i, j, k;
  ll inv_count = 0;
 
  i = left; /* i is index for left subarray*/
  j = mid;  /* j is index for right subarray*/
  k = left; /* k is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
 
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }
 
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];
 
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];
 
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}

ll bp[mn];
ll vc[mn];
ll vlt[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  int n=readInt();
  for (int i=1;i<=n;i++) bp[i]=p[i]=readInt();
  ll final=0;//mergeSort(bp+1,n);
  //printf("%lld\n",final);
  for (int i=1;i<=n;i++) {
    ll x=p[i];
    ll lt=vlt[i]=x-1-sum(t,x);
    ll gt=n-i-lt;
    ll g1=mul(lt,f(n-i));
    ll g2=mul(arith(lt-1),fact[n-i]);
    ll ltans=g1+g2;
    final+=ltans;
    vc[i]=mul(fact[n-i],lt);
    //printf("i:%lld lt:%lld x:%lld g1:%lld g2:%lld\n",i,lt,x,g1,g2);
    final%=MOD;
    add(t,x,1);
  }
  vc[n]++;
  for (int i=n-1;i>=1;i--) {
    vc[i]+=vc[i+1];
    vc[i]%=MOD;
  }
  for (int i=1;i<=n;i++) {
    final+=mul(vlt[i],vc[i+1]);
    //printf("i:%lld lt %lld *vc %lld=%lld\n",i,vlt[i],vc[i+1],vlt[i]*vc[i+1]);
    final%=MOD;
  }
  final%=MOD;
  printf("%lld\n",final);
}