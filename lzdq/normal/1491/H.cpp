#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ctime>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,blks=330,MAXM=MAXN/blks+5;
int n,q,a[MAXN],b[MAXN],cnt[MAXM],tag[MAXM];
inline int getb(int x){
	if(x<=blks) return b[x];
	return max(b[x]-tag[(x+blks-1)/blks],1);
}
void Upd(int k){
	//if(!tag[k]) return ;
	for(int i=max((k-1)*blks,1)+1; i<=min(k*blks,n); i++){
		a[i]=max(a[i]-tag[k],1);
		if(a[i]<=(k-1)*blks) b[i]=a[i];
		else b[i]=b[a[i]];
	}
	tag[k]=0;
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i=2; i<=n; i++){
		scanf("%d",a+i);
		int l=i-(i-1)%blks;
		if(a[i]<l) b[i]=a[i];
		else b[i]=b[a[i]];
	}
	while(q--){
		int op,l,r,x,y;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&l,&r,&x);
			/*
			for(int i=l; i<=r; i++){
				a[i]=max(a[i]-x,1);
				int t=i-(i-1)%blks;
				if(a[i]<t) b[i]=a[i];
				else b[i]=b[a[i]];
			}
			continue;
			*/
			int lb=(l+blks-1)/blks,rb=(r+blks-1)/blks;
			if(lb==rb){
				for(int i=l; i<=r; i++)
					a[i]=max(a[i]-x,1);
				Upd(lb);
			}else{
				for(int i=l; i<=lb*blks; i++)
					a[i]=max(a[i]-x,1);
				Upd(lb);
				for(int i=(rb-1)*blks+1; i<=r; i++)
					a[i]=max(a[i]-x,1);
				Upd(rb);
				for(int i=lb+1; i<rb; i++){
					if(cnt[i]>n) continue;
					tag[i]+=x;
					if(cnt[i]<blks) Upd(i);
					cnt[i]+=x;
				}
			}
			//printf(" %d\n",b[3]);
		}else{
			scanf("%d%d",&x,&y);
			while((x+blks-1)/blks!=(y+blks-1)/blks||getb(x)!=getb(y)){
				if(x>y) x=getb(x);
				else y=getb(y);
				//printf("x %d y %d tx %d ty %d\n",x,y,tx,ty);
			}
			Upd((x+blks-1)/blks);
			while(x!=y){
				if(x>y) x=a[x];
				else y=a[y];
			}
			//assert((double)(clock())/CLOCKS_PER_SEC<1.5);
			printf("%d\n",x);
		}
	}
	return 0;
}