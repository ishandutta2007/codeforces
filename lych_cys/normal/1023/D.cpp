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
#define N 200009
using namespace std;

int n,m,fa[N],a[N],bg[N],ed[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int getfa(int x){ return x==fa[x]?x:fa[x]=getfa(fa[x]); }
int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for (i=1; i<=n+1; i++) fa[i]=i;
	for (i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if (!bg[a[i]]) bg[a[i]]=i; ed[a[i]]=i;	
	}
	if (!bg[m]){
		for (i=1; i<=n; i++) if (!a[i]){ a[i]=m; bg[m]=ed[m]=i; break; }
		if (i>n){ puts("NO"); return 0; }	
	}
	for (i=m; i; i--) if (bg[i])
		for (j=bg[i]; j<=ed[i]; j=getfa(j+1)){
		//	cerr<<i<<' '<<j<<'\n';
			if (a[j] && a[j]!=i){ puts("NO"); return 0; }
			a[j]=i; fa[j]=j+1;	
		}
	for (i=1; i<=n; i++) if (!a[i]) a[i]=1;
	puts("YES");
	for (i=1; i<=n; i++) printf("%d%c",a[i],i<n?' ':'\n');
	return 0;
}