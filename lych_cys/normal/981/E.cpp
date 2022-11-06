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
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 10009
using namespace std;

int n,m,p1,p2,a[N],b[N]; bool ans[N];
vi f[N],g[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int R(){
	return abs((ll)rand()*rand()+rand())%1000000000;	
}
int calc(int x){
	for (; ; x++){
		int i;
		for (i=2; i*i<=x; i++) if (!(x%i)) break;
		if (i*i>x) return x;
	}
}
int main(){
	srand(2333666);
	p1=1000000000-R()%10000;
	p2=1000000000-R()%10000;
	n=read(); m=read();
	int i,j,x,y,z;
	for (i=1; i<=m; i++){
		scanf("%d%d%d",&x,&y,&z);
		p1^=x+y*2;
		f[x].pb(z); g[y].pb(z);
	}
	p1=calc(p1-n-m); p2=calc(p2+(n|m)); 
	a[0]=b[0]=1;
	if (p1==p2) p2=calc(p2+1);
	//cerr<<p1<<' '<<p2<<endl;
	for (i=1; i<=n; i++){
		for (int p:f[i])
			for (j=n; j>=p; j--){
				a[j]=(a[j]+a[j-p])%p1;
				b[j]=(b[j]+b[j-p])%p2;
			}
		for (j=1; j<=n; j++) ans[j]|=(a[j]>0 || b[j]>0);
		for (int p:g[i])
			for (j=p; j<=n; j++){
				a[j]=(a[j]+p1-a[j-p])%p1;
				b[j]=(b[j]+p2-b[j-p])%p2;
			}
	}
	int cnt=0;
	for (i=1; i<=n; i++) if (ans[i]) cnt++;
	printf("%d\n",cnt);
	for (i=1; i<=n; i++) if (ans[i]) printf("%d ",i); puts("");
	return 0;
}