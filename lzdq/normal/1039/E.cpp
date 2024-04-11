#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5,B=70,MAXM=MAXN/B+5,INF=0x7fffffff;
int n,w,q,a[MAXN];
struct node{
	int k,id;
}b[MAXN];
bool operator <(node a,node b){
	return a.k<b.k;
}
int ans[MAXN];
int go[MAXN],to[MAXN],cnt[MAXN];
int lg[MAXN],mi[MAXN][17],mx[MAXN][17];
inline int rmq(int l,int r){
	int k=lg[r-l+1];
	return max(mx[l][k],mx[r-(1<<k)+1][k])-min(mi[l][k],mi[r-(1<<k)+1][k]);
}
inline bool Check(int l,int r){
	return rmq(l,r)<=w;
}
int nx[MAXM];
void Build(int x){
	int l=(x-1)*B+1,r=min(x*B,n);
	nx[x]=INF;
	for(int i=r; i>=l; i--){
		while(to[i]<=r&&Check(i,to[i])) to[i]++;
		if(to[i]<=r) go[i]=go[to[i]],cnt[i]=cnt[to[i]]+1,nx[x]=min(nx[x],rmq(i,to[i]));
		else go[i]=i,cnt[i]=0;
	}
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d%d",&n,&w,&q);
	lg[0]=-1;
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),lg[i]=lg[i>>1]+1,mi[i][0]=mx[i][0]=a[i],to[i]=i+1;
	for(int j=1; j<=lg[n]; j++)
		for(int i=1; i+(1<<j)-1<=n; i++){
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<j-1)][j-1]);
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
		}
	for(int i=1; i<=q; i++){
		scanf("%d",&b[i].k);
		b[i].k=w-b[i].k;
		b[i].id=i;
	}
	sort(b+1,b+q+1);
	for(int i=1; i<=q; i++){
		w=b[i].k;
		int u=1,res=0;
		while(u<=n){
			int t=(u+B-1)/B;
			if(nx[t]<=w) Build(t);
			res+=cnt[u];
			u=go[u];
			if(to[u]<=n&&Check(u,to[u])){
				if(to[u]+B>n||!Check(u,to[u]+B))
					while(to[u]<=n&&Check(u,to[u])) to[u]++;
				else{
					int l=to[u],r=n;
					while(l<r){
						int mid=l+r+1>>1;
						if(Check(u,mid)) l=mid;
						else r=mid-1;
					}
					to[u]=r+1;
				}
			}
			res++;
			u=to[u];
		}
		ans[b[i].id]=res-1;
	}
	for(int i=1; i<=q; i++)
		printf("%d\n",ans[i]);
	return 0;
}