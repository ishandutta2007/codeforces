#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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

const int N=101000;
int n,c[N],ocr[N],nxtocr[N],cnt[N],a[N];
VI r[N];
void modify(int x,int s) {
	for (;x<=n+1;x+=x&(-x)) c[x]+=s;
}
int find(int x) {
	int p=0;
	per(i,0,20) {
		if (p+(1<<i)<=n+1&&c[p+(1<<i)]<x) {
			x-=c[p+(1<<i)];
			p+=(1<<i);
		}
	}
	return p+1;
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) ocr[i]=n+1;
	per(i,1,n+1) {
		nxtocr[i]=ocr[a[i]];
		ocr[a[i]]=i;
	}
	rep(i,1,n+1) {
		modify(ocr[i],1);
		r[1].pb(i);
	}
	rep(i,1,n+1) {
		for (auto d:r[i]) {
			int k=find(d+1);
//			printf("%d %d %d\n",i,d,k);
			cnt[d]++;
			r[k].pb(d);
		}
		modify(i,-1);
		modify(nxtocr[i],1);
	}
	rep(i,1,n+1) printf("%d ",cnt[i]);
}