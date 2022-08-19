#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <random>
#include <ctime>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

map<int,VI> hs;
vector<VI> v;
int n,start,x;
VI query(int p) {
	if (hs.count(p)) return hs[p];
	printf("? %d\n",p);
	fflush(stdout);
	int x,y;
	scanf("%d%d",&x,&y);
	return hs[p]=VI{x,y,p};
}
void answer(int p) {
	printf("! %d\n",p);
	fflush(stdout);
	exit(0);
}
int main() {
	mt19937 mt_rand(time(0));
	scanf("%d%d%d",&n,&start,&x);
	v.pb(query(start));
	rep(i,0,999) {
		int c=mt_rand()%n;
		if (c<0) c+=n;
		c+=1;
		v.pb(query(c));
	}
	sort(all(v));
	int sp=-1;
	per(i,0,SZ(v)) if (v[i][0]<x) {
		sp=v[i][2];
		break;
	}
	if (sp==-1) {
		answer(v[0][0]);
	}
	rep(i,0,999) {
		if (sp==-1) break;
		auto c=query(sp);
		if (c[0]>=x) {
			answer(c[0]);
		}
		sp=c[1];
	}
	answer(-1);
}