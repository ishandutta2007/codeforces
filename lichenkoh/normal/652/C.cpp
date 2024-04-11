#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
#define MAXN 300004
#define MAXSEG (4*MAXN)
// specific code
const int maxn = 300004;

const int INIT_VALUE = INT_MAX/2;
const int NEUTRAL_VALUE = INT_MAX/2;
const int NEUTRAL_DELTA = 0;

int joinValues(int leftValue, int rightValue) {
  return min(leftValue, rightValue);
}

int joinDeltas(int oldDelta, int newDelta) {
  return oldDelta + newDelta;
}

int joinValueWithDelta(int value, int delta, int length) {
  return value + delta;
}

// generic code
int n;
int value[4 * maxn];
int delta[4 * maxn]; // affects only child roots

void init(int root, int left, int right) {
  if (left == right) {
    value[root] = INIT_VALUE;
    delta[root] = NEUTRAL_DELTA;
  } else {
    init(2 * root + 1, left, (left + right) / 2);
    init(2 * root + 2, (left + right) / 2 + 1, right);
    value[root] = joinValues(value[2 * root + 1], value[2 * root + 2]);
    delta[root] = NEUTRAL_DELTA;
  }
}

void init(int n) {
  ::n = n;
  init(0, 0, n - 1);
}

void pushDelta(int root, int left, int right) {
  delta[2 * root + 1] = joinDeltas(delta[2 * root + 1], delta[root]);
  delta[2 * root + 2] = joinDeltas(delta[2 * root + 2], delta[root]);
  int middle = (left + right) / 2;
  value[2 * root + 1] = joinValueWithDelta(value[2 * root + 1], delta[root], middle - left + 1);
  value[2 * root + 2] = joinValueWithDelta(value[2 * root + 2], delta[root], right - middle);
  delta[root] = NEUTRAL_DELTA;
}

int query(int a, int b, int root, int left, int right) {
  if (a > right || b < left)
    return NEUTRAL_VALUE;
  if (a <= left && right <= b)
    return value[root];
  pushDelta(root, left, right);
  return joinValues(query(a, b, root * 2 + 1, left, (left + right) / 2),
    query(a, b, root * 2 + 2, (left + right) / 2 + 1, right));
}

int query(int a, int b) {
  return query(a, b, 0, 0, n - 1);
}

void modify(int a, int b, int delta, int root, int left, int right) {
  if (a > right || b < left)
    return;
  if (a <= left && right <= b) {
    ::delta[root] = joinDeltas(::delta[root], delta);
    value[root] = joinValueWithDelta(value[root], delta, right - left + 1);
    return;
  }
  pushDelta(root, left, right);
  modify(a, b, delta, 2 * root + 1, left, (left + right) / 2);
  modify(a, b, delta, 2 * root + 2, (left + right) / 2 + 1, right);
  value[root] = joinValues(value[2 * root + 1], value[2 * root + 2]);
}

void modify(int a, int b, int delta) {
  modify(a, b, delta, 0, 0, n - 1);
}
unordered_map<ll,ll> h;
int main() {
	ios_base::sync_with_stdio(false);
	int m;
	scanf("%d %d",&n,&m);
	init(n);
	for (ll i=0;i<n;i++) {
		int pi; scanf("%d",&pi);
		h[pi]=i;
	}
	for (ll i=0;i<m;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		x=h[x]; y=h[y];
		if (x>y) swap(x,y);
		int oldv = query(x,x);
		y=min(y,oldv);
		//printf("%d-%d\n",x,y);
		modify(x,x,y-oldv);
	}
	ll y=0;
	ll ans=0;
	for (ll x=0;x<n;x++) {
		y=max(y,x);
		while(y<n) {
			ll minr = query(x,y);
			//printf("%d %d: %d\n",x,y,minr);
			if (minr<=y) break;
			y++;
		}
		y--;
		if (query(x,y)>y) {
			//printf("%d->%d:%d\n",x,y,y-x+1);
			ans+=(y-x+1);
		}
	}
	cout<<ans<<endl;
}