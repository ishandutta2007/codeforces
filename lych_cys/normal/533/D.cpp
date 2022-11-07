#include<bits/stdc++.h>
#define ll long long
#define N 100009
#define M 5000009
#define W 1000000000
#define inf 10000000000000000ll
using namespace std;

int n,tp,trtot,rt[N],a[N],q[N],ls[M],rs[M],mx[M]; ll f[N],g[N],b[N];
void ins(int &k,int p,int l,int r,int x,int y){
	k=++trtot; mx[k]=max(mx[p],y);
	if (l==r) return;
	int mid=l+r>>1;
	if (x<=mid){ rs[k]=rs[p]; ins(ls[k],ls[p],l,mid,x,y); }
	else{ ls[k]=ls[p]; ins(rs[k],rs[p],mid+1,r,x,y); }
}
int qry(int k,int l,int r,int x){
	if (!k) return -W; if (x<=l) return mx[k];	
	int mid=l+r>>1,ans=qry(rs[k],mid+1,r,x);
	if (x<=mid) ans=max(ans,qry(ls[k],l,mid,x));
	return ans;
}
int main(){
	scanf("%d",&n);
	int i;
	for (i=0; i<=n+1; i++) scanf("%d",&a[i]);
	b[0]=b[n+1]=inf;
	for (i=1; i<=n; i++){
		scanf("%lld",&b[i]); b[i]<<=1;
	}
	q[tp=1]=0; mx[0]=-W;
	ins(rt[0],rt[0],0,W,W,a[0]);
	for (i=1; i<=n+1; i++){
		for (; tp>1 && b[q[tp]]<a[i]-a[q[tp-1]]; tp--);
		g[i]=b[i]-(a[i]-a[q[tp]]);
		if (g[i]>0){
			g[i]=min((ll)W,g[i]+a[i]);
			//cerr<<i<<' '<<g[i]<<' '<<a[i]<<endl;
			ins(rt[i],rt[i-1],0,W,g[i],a[i]);	
		} else rt[i]=rt[i-1];
		q[++tp]=i;
	}
//	cerr<<tp<<endl;
	if (q[tp-1]){ puts("0"); return 0; }
	q[tp=1]=n+1;
	int ans=a[n+1]-mx[rt[n]];
	for (i=n; i; i--){
		for (; tp>1 && b[q[tp]]<a[q[tp-1]]-a[i]; tp--);
		g[i]=b[i]-(a[q[tp]]-a[i]);
		if (g[i]>0){
			//cerr<<b[i]<<endl;
			g[i]=max(0ll,a[i]-g[i]);
			//cerr<<":"<<i<<' '<<g[i]<<endl;
			ans=min(ans,a[i]-qry(rt[i-1],0,W,g[i]));
		}
		q[++tp]=i;
	}
	printf("%.10f\n",ans/2.);
	return 0;
}