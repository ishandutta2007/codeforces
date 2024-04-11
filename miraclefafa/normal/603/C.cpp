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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int n,k,vis[N],sg[N],x,rt;
int Sg(int r) {
	if (r<=100) return sg[r];
	else if (k%2==0) {
		return 1-r%2;
	} else {
		if (r%2==0) {
			int c=Sg(r/2);
			if (c==0) return 1; else if (c==1) return 2; else return 1;
		}
		else return 0;
	}
}
int main() {
	scanf("%d%d",&n,&k);
	if (k%2==0) {
		sg[0]=0;
		rep(i,1,1001) {
			vis[sg[i-1]]=i; if (i%2==0) vis[0]=i;
			while (vis[sg[i]]==i) sg[i]++;
	//		printf("%d %d\n",sg[i],i);
			assert(Sg(i)==sg[i]);
		}
	} else {
		sg[0]=0;
		rep(i,1,1001) {
			vis[sg[i-1]]=i; if (i%2==0) vis[sg[i/2]]=i;
			while (vis[sg[i]]==i) sg[i]++;
	//		printf("%d %d\n",sg[i],i);
			assert(Sg(i)==sg[i]);
		}
	}
	rep(i,0,n) {
		scanf("%d",&x);
		rt^=Sg(x);
	}
	puts(rt?"Kevin":"Nicky");
}