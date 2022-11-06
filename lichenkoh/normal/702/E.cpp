#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <iostream>
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
const ll MAXN=1e5+4;
const ll INF=2e18;
ll f[MAXN],w[MAXN];
ll s[2][MAXN],m[2][MAXN],v[2][MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k; scanf("%I64d %I64d",&n,&k);
	for (ll i=0;i<n;i++) scanf("%I64d",&f[i]);
	for (ll i=0;i<n;i++) scanf("%I64d",&w[i]);
	for (ll x=0;x<n;x++) {
		v[0][x]=x;
		s[0][x]=0;
		m[0][x]=INF;
	}
	vector<ll> go;
	ll tmpk=k;
	while(tmpk>0) {
		if (tmpk%2==1) {go.PB(1); tmpk--;}
		else {go.PB(0); tmpk/=2;}
	}
	reverse(go.begin(),go.end());
	ll tmp=0;
	ll prev=0,cur=1;
	for (auto &o:go) {
		if (o==0) {
			for (ll x=0;x<n;x++) {
				s[cur][x]=s[prev][x]+s[prev][v[prev][x]];
				m[cur][x]=min(m[prev][x],m[prev][v[prev][x]]);
				v[cur][x]=v[prev][v[prev][x]];
			}
			tmp*=2;
		}
		else {
			for (ll x=0;x<n;x++) {
				s[cur][x]=s[prev][f[x]]+w[x];
				m[cur][x]=min(m[prev][f[x]],w[x]);
				v[cur][x]=f[v[prev][x]];
			}
			tmp++;
		}
		//printf("tmp:%I64d\n",tmp);
		//for (ll x=0;x<n;x++) {
		//	printf("x:%I64d s:%I64d m:%I64d v:%I64d\n",x,s[x],m[x],v[x]);
		//}
		swap(prev,cur);
	}
	assert(tmp==k);
	for (ll x=0;x<n;x++) {
		printf("%I64d %I64d\n",s[prev][x],m[prev][x]);
	}
}