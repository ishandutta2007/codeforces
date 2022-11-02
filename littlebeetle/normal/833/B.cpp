#include<cstdio>
const int N=140020,K=51;
int n,p,i,j,k,a[N],pre[N],loc[N],F[N][K];
int max(int x,int y){
	return x>y?x:y;
}
struct Seg{
	int Max[N],lz[N];
	void Change(int rt,int val){
		Max[rt]+=val;
		lz[rt]+=val;
	}
	void Pushdown(int rt){
		if(lz[rt]){
			Change(rt<<1,lz[rt]);
			Change(rt<<1|1,lz[rt]);
			lz[rt]=0;
		}
	}
	void Update(int rt,int l,int r,int x,int y,int z){
		if(x<=l&&r<=y){
			Change(rt,z);
			return;
		}
		Pushdown(rt);
		int mid=l+r>>1;
		if(x<=mid)Update(rt<<1,l,mid,x,y,z);
		if(y>mid)Update(rt<<1|1,mid+1,r,x,y,z);
		Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
	}
	int Query(int rt,int l,int r,int x,int y){
		if(x<=l&&r<=y)
			return Max[rt];
		Pushdown(rt);
		int mid=l+r>>1,s=0;
		if(x<=mid)s=max(s,Query(rt<<1,l,mid,x,y));
		if(y>mid)s=max(s,Query(rt<<1|1,mid+1,r,x,y));
		return s;
	}
}T[K];	
void init(){
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		pre[i]=loc[a[i]];
		loc[a[i]]=i;
	}
}
void work(){
	for(i=1;i<=n;i++){
		for(j=0;j<p;j++)
			T[j].Update(1,1,n,pre[i]+1,i,1);
		for(j=1;j<=p;j++){
			F[i][j]=T[j-1].Query(1,1,n,1,i);
			if(i<n)
			T[j].Update(1,1,n,i+1,i+1,F[i][j]);
		}
	}
	printf("%d\n",F[n][p]);
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}