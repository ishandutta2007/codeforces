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

int n,m,a[100009]; map<pii,int> mp;
int main(){
	scanf("%d%d",&n,&m);
	if (m==(ll)n*(n-1)/2){ puts("NO"); return 0; }
	int i,j,x,y;
	for (i=1; i<=m; i++){
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		mp[mpr(x,y)]=1;
	}
	for (i=1; i<n; i++)
		for (j=i+1; j<=n; j++)
			if (!mp[mpr(i,j)]){
				puts("YES");
				a[i]=a[j]=1;
				int now=2;
				for (x=1; x<=n; x++) if (!a[x]) a[x]=++now;
				for (x=1; x<=n; x++) printf("%d%c",a[x]+(x==j),x<n?' ':'\n');
				for (x=1; x<=n; x++) printf("%d%c",a[x],x<n?' ':'\n');
				return 0;	
			}
	return 0;
}