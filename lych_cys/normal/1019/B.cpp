#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
using namespace std;

int n;
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int sig(int x){
	int y=x+n; if (y>2*n) y-=2*n;
	printf("? %d\n",x); fflush(stdout); int u; scanf("%d",&u);
	printf("? %d\n",y); fflush(stdout); int v; scanf("%d",&v);
	if (u==v){
		printf("! %d\n",min(x,y)); exit(0);
	}
	return u<v?-1:1;
}
int main(){
	scanf("%d",&n); n>>=1;
	if (n&1){ puts("! -1"); fflush(stdout); return 0; }
	int l=1,r=n+1,u=sig(l),mid; int v=-u;
	while (l<=r){
		mid=l+r>>1;
		if (sig(mid)==u) l=mid+1; else r=mid-1;
	}
	return 0;
}