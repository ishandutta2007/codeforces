#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+5,blks=330,MAXM=MAXN/blks+3,INF=0x3fffffff;
int n,q,a[MAXN],b[MAXN],rk[MAXN];
int pre[MAXM][MAXN],suf[MAXM][MAXN],mi[MAXN];
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),b[i]=a[i];
	for(int i=1; i<=(n+blks-1)/blks; i++){
		int l=(i-1)*blks+1,r=min(n,i*blks);
		sort(b+l,b+r+1);
		for(int j=l; j<=r; j++)
			rk[j]=lower_bound(b+l,b+r+1,a[j])-b;
	}
	for(int i=1; i<(n+blks-1)/blks; i++){
		int l1=(i-1)*blks+1,r1=i*blks;
		for(int j=i+1; j<=(n+blks-1)/blks; j++){
			int l2=(j-1)*blks+1,r2=min(n,j*blks);
			for(int k=l1; k<=r1; k++)
				mi[k]=INF;
			for(int k=l2; k<=r2; k++)
				mi[k]=INF;
			int p1=l1,p2=l2;
			while(p1<=r1||p2<=r2){
				if(p2>r2||p1<=r1&&b[p1]<b[p2]){
					if(p2>l2) mi[p1]=min(mi[p1],b[p1]-b[p2-1]);
					if(p2<=r2) mi[p1]=min(mi[p1],b[p2]-b[p1]);
					p1++;
				}else{
					if(p1>l1) mi[p2]=min(mi[p2],b[p2]-b[p1-1]);
					if(p1<=r1) mi[p2]=min(mi[p2],b[p1]-b[p2]);
					p2++;
				}
			}
			for(int k=l1; k<=r1; k++)
				suf[j][k]=mi[rk[k]];
			for(int k=l2; k<=r2; k++)
				pre[i][k]=mi[rk[k]];
		}
	}
	for(int i=(n+blks-1)/blks; i; i--){
		int l=(i-1)*blks+1,r=min(n,i*blks);
		pre[i][l]=INF;
		for(int j=l+1; j<=r; j++){
			pre[i][j]=pre[i][j-1];
			for(int k=l; k<j; k++)
				pre[i][j]=min(pre[i][j],abs(a[j]-a[k]));
		}
		for(int j=r+1; j<=n; j++)
			pre[i][j]=min(pre[i][j],min(pre[i+1][j],pre[i][j-1]));
	}
	for(int i=1; i<=(n+blks-1)/blks; i++){
		int l=(i-1)*blks+1,r=min(n,i*blks);
		suf[i][r]=INF;
		for(int j=r-1; j>=l; j--){
			suf[i][j]=suf[i][j+1];
			for(int k=r; k>j; k--)
				suf[i][j]=min(suf[i][j],abs(a[j]-a[k]));
		}
		for(int j=l-1; j; j--)
			suf[i][j]=min(suf[i][j],min(suf[i-1][j],suf[i][j+1]));
	}
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int x=(l+blks-1)/blks,y=(r+blks-1)/blks;
		int res=INF,las=-INF;
		if(x==y){
			for(int i=(x-1)*blks+1; i<=min(n,x*blks); i++)
				mi[i]=0;
			for(int i=l; i<=r; i++)
				mi[rk[i]]++;
			for(int i=(x-1)*blks+1; i<=min(n,x*blks); i++){
				if(mi[i]) res=min(res,b[i]-las),las=b[i];
				if(mi[i]>1) res=0;
			}
		}else{
			res=min(pre[x+1][r],suf[y-1][l]);
			int l1=(x-1)*blks+1,r1=x*blks;
			int l2=(y-1)*blks+1,r2=min(n,y*blks);
			for(int i=l1; i<=r1; i++)
				mi[i]=0;
			for(int i=l2; i<=r2; i++)
				mi[i]=0;
			for(int i=l; i<=r1; i++)
				mi[rk[i]]++;
			for(int i=l2; i<=r; i++)
				mi[rk[i]]++;
			int p1=l1,p2=l2;
			while(!mi[p1]) p1++;
			while(!mi[p2]) p2++;
			while(p1<=r1||p2<=r2){
				if(p2>r2||p1<=r1&&b[p1]<b[p2]){
					res=min(res,b[p1]-las);
					if(mi[p1]>1) res=0;
					las=b[p1];
					do p1++;
					while(p1<=r1&&!mi[p1]);
				}else{
					res=min(res,b[p2]-las);
					if(mi[p2]>1) res=0;
					las=b[p2];
					do p2++;
					while(p2<=r2&&!mi[p2]);
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}