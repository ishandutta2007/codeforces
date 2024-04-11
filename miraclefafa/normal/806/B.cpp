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

int n,a[233][233],pass[233],rt[233],val[233][233],sol;
void dfs(int dep,int pA,int pB) {
	if (sol) return;
	if (dep==5) {
		if (pA>pB) sol=1;
	}
	rep(j,0,6) if (val[dep][j]) {
		int sco=(j+1)*500;
		int qA=pA; if (a[0][dep]!=-1) qA+=sco-sco/250*a[0][dep];
		int qB=pB; if (a[1][dep]!=-1) qB+=sco-sco/250*a[1][dep];
		dfs(dep+1,qA,qB);
	}
}
bool check(int tot) {
	rep(i,0,5) {
		rep(j,0,6) val[i][j]=0;
		if (a[0][i]==-1) {
			if (pass[i]<=tot/32) val[i][5]=1;
			else if (pass[i]<=tot/16) val[i][4]=1;
			else if (pass[i]<=tot/8) val[i][3]=1;
			else if (pass[i]<=tot/4) val[i][2]=1;
			else if (pass[i]<=tot/2) val[i][1]=1;
			else val[i][0]=1;
		} else {
			if (pass[i]<=tot/32) val[i][5]=1;
			if (pass[i]<=tot/16&&pass[i]+rt[i]>tot/32) val[i][4]=1;
			if (pass[i]<=tot/8&&pass[i]+rt[i]>tot/16) val[i][3]=1;
			if (pass[i]<=tot/4&&pass[i]+rt[i]>tot/8) val[i][2]=1;
			if (pass[i]<=tot/2&&pass[i]+rt[i]>tot/4) val[i][1]=1;
			if (pass[i]<=tot&&pass[i]+rt[i]>tot/2) val[i][0]=1;
		}
	}
	sol=0;
	dfs(0,0,0);
	return sol;
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		rep(j,0,5) {
			scanf("%d",&a[i][j]);
			if (a[i][j]!=-1) pass[j]++;
		}
	}
	rep(r,0,120*n+1) {
		rep(j,0,5) rt[j]=r;
		if (check(n+r)) {
			printf("%d\n",r);
			return 0;
		}
	}
	puts("-1");
}