#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

using STV=ll;
using STD=ll;
class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    return x+y;
  }

  // query (or combine) operation
  STV queryOperation(STV l, STV r) {
    return min(l,r);
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    return delta;
  }

  STD initNeutralDelta() {
    return 0;
  }

  bool isNeutralDelta(STD delta) {
    return delta==0;
  }

  STV getInitValue(int i) {
  	return i;
  }

  STV getNeutralValue() {
  	return INT_MAX;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    return delta1+delta2;
  }

  // generic code

  STD _cache_neutral_delta;

  STD getNeutralDelta() {
    return _cache_neutral_delta;
  }

  vector<STV> value;
  vector<STD> delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
  int gn;

  STV joinValueWithDelta(STV value, STD delta) {
    if (isNeutralDelta(delta)) return value;
    return modifyOperation(value, delta);
  }

  void pushDelta(int i) {
    int d = 0;
    for (; (i >> d) > 0; d++) {
    }
    for (d -= 2; d >= 0; d--) {
      int x = i >> d;
      value[x >> 1] = joinNodeValueWithDelta(x >> 1, 1 << (d + 1));
      delta[x] = joinDeltas(delta[x], delta[x >> 1]);
      delta[x ^ 1] = joinDeltas(delta[x ^ 1], delta[x >> 1]);
      delta[x >> 1] = getNeutralDelta();
    }
  }

  SegmentTreeFast(int n) {
    _cache_neutral_delta = initNeutralDelta();
    gn=n;
    value.resize(2 * n);
    for (int i = 0; i < n; i++) {
      value[i + n] = getInitValue(i);
    }
    for (int i = n - 1; i > 0; --i) value[i] = queryOperation(value[i<<1], value[i<<1|1]);
    delta.resize(2 * n);
  	for (int i=0;i<2*n;i++) delta[i]=getNeutralDelta();
  }

  STV joinNodeValueWithDelta(int i, int len) {
    return joinValueWithDelta(value[i], deltaEffectOnSegment(delta[i], len));
  }

  STV query(int from, int to) {
    from += gn;
    to += gn;
    pushDelta(from);
    pushDelta(to);
    STV resl = getNeutralValue(); STV resr = getNeutralValue();
    bool found = false;
    for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
      if ((from & 1) != 0) {
        resl = found ? queryOperation(resl, joinNodeValueWithDelta(from, len)) : joinNodeValueWithDelta(from, len);
        found = true;
      }
      if ((to & 1) == 0) {
        resr = found ? queryOperation(joinNodeValueWithDelta(to, len), resr) : joinNodeValueWithDelta(to, len);
        found = true;
      }
    }
    STV res=queryOperation(resl,resr);
    if (!found) assert(0);
    return res;
  }

  void modify(int from, int to, STD delta) {
    from += gn;
    to += gn;
    pushDelta(from);
    pushDelta(to);
    int a = from;
    int b = to;
    for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
      if ((from & 1) != 0) {
        this->delta[from] = joinDeltas(this->delta[from], delta);
      }
      if ((to & 1) == 0) {
        this->delta[to] = joinDeltas(this->delta[to], delta);
      }
    }
    for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
      int k=i>>1;
      value[k] = queryOperation(joinNodeValueWithDelta(k<<1, len), joinNodeValueWithDelta((k<<1)|1, len));
    }
    for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
      int k=i>>1;
      value[k] = queryOperation(joinNodeValueWithDelta(k<<1, len), joinNodeValueWithDelta((k<<1)|1, len));
    }
  }
};



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


void go() {
	int an,bn; cin>>an>>bn;
	vpii a(an); vi ob(bn);
	ll *c = new ll[an];
	for (int i=0;i<an;i++) {
		int x; cin>>x;
		a[i]=MP(x,i);
		c[i]=x;
	}
	ll init=mergeSort(c,an);
	delete []c;
	sort(a.begin(),a.end());
	for (int i=0;i<bn;i++) cin>>ob[i];
	sort(ob.begin(),ob.end());
	vpii b;
	{
		int now=ob[0]; int cnt=0;
		for (int i=0;i<bn;i++) {
			if (ob[i]==now) cnt++;
			else {
				if (cnt>0) {
					b.PB(MP(now,cnt));
				}
				now=ob[i];
				cnt=1;
			}
		}
		if (cnt>0) {
			b.PB(MP(now,cnt));
		}
	}
	
	SegmentTreeFast seg(an+1);
	ll final=0;
	int q=0;
	for (auto &bp:b) {
		int bval=bp.fst; ll bcnt=bp.snd;
		while(q < an && a[q].fst < bval) {
			int ai=a[q].snd;
			seg.modify(ai+1,an,-1);
			seg.modify(0,ai,1);
			++q;
		}
		vi eq;
		while(q < an && a[q].fst == bval) {
			int ai=a[q].snd;
			eq.PB(ai);
			seg.modify(ai+1,an,-1);
			++q;
		}
		ll best=seg.query(0,an);
		final += best * bcnt;
		for (auto &ai:eq) {
			seg.modify(0,ai,1);
		}
	}
	printf("%lld\n",final+init);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) go();
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