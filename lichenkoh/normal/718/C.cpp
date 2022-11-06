#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define MOD 1000000007LL
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

#define MP make_pair
pll joinDeltas(pll &oldDelta, pll &newDelta);
pll getpow(ll p) {
  pll ans=MP(1LL,0LL);
  pll base=MP(1LL,1LL);
  while(p>0) {
    if(p&1)ans=joinDeltas(ans,base);
    base=joinDeltas(base,base);
    p>>=1;
  }
  //printf("p:%lld %lld %lld\n",p,thing.first,thing.second);
  return ans;
}
// specific code
const ll maxn = 100004;

const pll INIT_VALUE = MP(1LL,1LL);
const pll NEUTRAL_VALUE = MP(0LL,0LL);
pll NEUTRAL_DELTA = MP(1LL,0LL);
ll initial_array[maxn];
pll joinValues(pll leftValue, pll rightValue) {
  return MP(
    (leftValue.first + rightValue.first)%MOD,
    (leftValue.second + rightValue.second)%MOD
    );
}

pll joinDeltas(pll &oldDelta, pll &newDelta) {
  ll a=oldDelta.first,b=oldDelta.second;
  ll c=newDelta.first,d=newDelta.second;
  pll ans= MP(
    (a*c+b*d)%MOD,
    (b*c+(a-b+MOD)*d)%MOD
    );
  //printf("%lld %lld. %lld %lld. %lld %lld\n",a,b,c,d,ans.first,ans.second);
  return ans;
}

pll joinValueWithDelta(pll value, pll delta, ll length) {
  ll a=delta.first,b=delta.second;
  ll a00=a,a01=b,a10=b,a11=(a-b+MOD)%MOD;
  ll x=(a00*value.first+a01*value.second)%MOD;
  ll y=(a10*value.first+a11*value.second)%MOD;
  return MP(x,y);
}

// generic code
ll n;
pll value[4 * maxn];
pll delta[4 * maxn]; // affects only child roots

void init(ll root, ll left, ll right) {
  if (left == right) {
    pll d=getpow(initial_array[left]);
    value[root] = joinValueWithDelta(INIT_VALUE, d,1);
    delta[root] = NEUTRAL_DELTA;
  } else {
    init(2 * root + 1, left, (left + right) / 2);
    init(2 * root + 2, (left + right) / 2 + 1, right);
    value[root] = joinValues(value[2 * root + 1], value[2 * root + 2]);
    delta[root] = NEUTRAL_DELTA;
  }
}

void init(ll n) {
  ::n = n;
  init(0, 0, n - 1);
}

void pushDelta(ll root, ll left, ll right) {
  delta[2 * root + 1] = joinDeltas(delta[2 * root + 1], delta[root]);
  delta[2 * root + 2] = joinDeltas(delta[2 * root + 2], delta[root]);
  ll middle = (left + right) / 2;
  value[2 * root + 1] = joinValueWithDelta(value[2 * root + 1], delta[root], middle - left + 1);
  value[2 * root + 2] = joinValueWithDelta(value[2 * root + 2], delta[root], right - middle);
  delta[root] = NEUTRAL_DELTA;
}

pll query(ll a, ll b, ll root, ll left, ll right) {
  if (a > right || b < left)
    return NEUTRAL_VALUE;
  if (a <= left && right <= b)
    return value[root];
  pushDelta(root, left, right);
  return joinValues(query(a, b, root * 2 + 1, left, (left + right) / 2),
    query(a, b, root * 2 + 2, (left + right) / 2 + 1, right));
}

pll query(ll a, ll b) {
  return query(a, b, 0, 0, n - 1);
}

void modify(ll a, ll b, pll delta, ll root, ll left, ll right) {
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

void modify(ll a, ll b, pll delta) {
  modify(a, b, delta, 0, 0, n - 1);
}

int main() {
  ll n,m; scanf("%lld %lld",&n,&m);
  for (ll i=0;i<n;i++) {
    ll x; scanf("%lld",&x);
    x--;
    initial_array[i]=x;
  }
  init(n);
  for (ll i=0;i<m;i++) {
    ll t; scanf("%lld",&t);
    if (t==1) {
      ll l,r,x; scanf("%lld %lld %lld",&l,&r,&x);
      l--;r--;
      pll delta=getpow(x);
      modify(l,r,delta);
    }
    else {
      ll l,r; scanf("%lld %lld",&l,&r);
      l--;r--;
      pll res=query(l,r);
      printf("%lld\n",res.second);
    }
  }
}