#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 100009
using namespace std;

int n,a[N],ans[N]; vi b[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void gg(){ puts("Impossible"); exit(0); }
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++){
		scanf("%d",&a[i]); a[i]=n-a[i];
		if (a[i]<1 || a[i]>n) gg();	
		b[a[i]].pb(i);
	}
	int now=0;
	for (i=1; i<=n; i++){
	//	cerr<<i<<' '<<b[i].size()
		if (b[i].size()%i) gg();
		int tmp=0;
		for (int p:b[i]){
			if (!tmp) now++; tmp=(tmp+1)%i;
			ans[p]=now;
		}
	}
	puts("Possible");
	for (i=1; i<=n; i++) printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}