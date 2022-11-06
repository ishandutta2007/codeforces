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
using namespace std;
int a[9],b[9]; bool bo[1009][1009];
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
int main(){
	int i,j,k,x,y,tx,ty,ans=inf;
	for (i=1; i<=3; i++) scanf("%d%d",&a[i],&b[i]);
	for (i=0; i<=1000; i++)
		for (j=0; j<=1000; j++){
			int tmp=0;
			for (k=1; k<=3; k++) tmp+=abs(a[k]-i)+abs(b[k]-j);
			if (tmp<ans){
				ans=tmp;
				tx=i; ty=j;
			}
		}
	for (i=1; i<=3; i++){
		for (x=tx,y=ty; x!=a[i]; x=(x>a[i]?x-1:x+1)) bo[x][y]=1;
		for (; y!=b[i]; y=(y>b[i]?y-1:y+1)) bo[x][y]=1;
		bo[x][y]=1;
	}
	printf("%d\n",ans+1);
	for (i=0; i<=1000; i++)
		for (j=0; j<=1000; j++) if (bo[i][j]) printf("%d %d\n",i,j);
	return 0;
}