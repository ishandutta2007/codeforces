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

int n,m,a[109];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void solve(int k,int l,int r){
	if (l==r){ printf("%d\n",l); fflush(stdout); return; }
	int mid=l+r>>1; printf("%d\n",mid); fflush(stdout);
	int t; scanf("%d",&t); t*=a[k];
	k=k%n+1;
	if (!t) return;
	if (t==-1) solve(k,l,mid-1); else solve(k,mid+1,r);	
}
int main(){
	scanf("%d%d",&m,&n);
	int i;
	for (i=1; i<=n; i++){
		printf("%d\n",m); fflush(stdout);
		scanf("%d",&a[i]); a[i]*=-1;
	}
	solve(1,1,m);
	return 0;
}