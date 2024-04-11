#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int T,n,m,k,a[N],nxtlt[N],nxtgt[N],mx[20][N],mn[20][N],Log[N],pos[N],lp[N],gp[N];
int qmx(int l,int r){int k=Log[r-l+1];return max(mx[k][l],mx[k][r-(1<<k)+1]);}
int qmn(int l,int r){int k=Log[r-l+1];return min(mn[k][l],mn[k][r-(1<<k)+1]);}
void ul(int x,int y){for(;x<=n;x+=x&-x)lp[x]=y;}
int ql(int x){int res=n+1;for(;x;x-=x&-x)res=min(res,lp[x]);return res;}
void ug(int x,int y){for(;x<=n;x+=x&-x)gp[x]=y;}
int qg(int x){int res=n+1;for(;x;x-=x&-x)res=min(res,gp[x]);return res;}
void solve(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx[0][i]=mn[0][i]=a[i],pos[a[i]]=i;
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j<=n-(1<<i)+1;j++)
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]),mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
	for(int i=1;i<=n;i++)lp[i]=gp[i]=n+1;
	for(int i=n;i;i--){
		nxtlt[i]=ql(a[i]),nxtgt[i]=qg(n-a[i]+1),ul(a[i],i),ug(n-a[i]+1,i);
	}
	int ans=0;
	for(int i=1;i!=n;){
		ans++;
		if(a[i+1]>a[i])i=pos[qmx(i+1,nxtlt[i]-1)];
		else i=pos[qmn(i+1,nxtgt[i]-1)];
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}