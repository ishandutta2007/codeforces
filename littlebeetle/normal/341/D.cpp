#include<cstdio>
const int N=2060;
int n,q,opt,X1,Y1,X2,Y2,v;
int min(int x,int y){
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
struct Segm{
	int tag[N],sum[N];
	void Update(int rt,int l,int r,int x,int y,int z){
		//printf("    %d %d %d %d %d\n",l,r,x,y,z);
		sum[rt]^=(min(y,r)-max(x,l)+1&1)*z;
		if(x<=l&&r<=y){
			tag[rt]^=z;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid)Update(rt<<1,l,mid,x,y,z);
		if(y>mid)Update(rt<<1|1,mid+1,r,x,y,z);
	}
	int Query(int rt,int l,int r,int x,int y){
		if(x<=l&&r<=y)
			return sum[rt];
		int mid=l+r>>1;
		int s=(min(y,r)-max(x,l)+1&1)*tag[rt];
		if(x<=mid)s^=Query(rt<<1,l,mid,x,y);
		if(y>mid)s^=Query(rt<<1|1,mid+1,r,x,y);
		return s;
	}
};
struct Segn{
	Segm tag[N],sum[N];
	void Update(int rt,int l,int r,int x,int y,int z,int L,int R){
		if(min(y,r)-max(x,l)+1&1)
			sum[rt].Update(1,1,n,L,R,z);
		if(x<=l&&r<=y){
			tag[rt].Update(1,1,n,L,R,z);
			return;
		}
		int mid=l+r>>1;
		if(x<=mid)Update(rt<<1,l,mid,x,y,z,L,R);
		if(y>mid)Update(rt<<1|1,mid+1,r,x,y,z,L,R);
	}
	int Query(int rt,int l,int r,int x,int y,int L,int R){
		if(x<=l&&r<=y)
			return sum[rt].Query(1,1,n,L,R);
		int mid=l+r>>1;
		int s=0;
		if(min(y,r)-max(x,l)+1&1)
			s=tag[rt].Query(1,1,n,L,R);
		if(x<=mid)s^=Query(rt<<1,l,mid,x,y,L,R);
		if(y>mid)s^=Query(rt<<1|1,mid+1,r,x,y,L,R);
		return s;
	}
}T;
void init(){
	scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
			printf("%d\n",T.Query(1,1,n,X1,X2,Y1,Y2));
		}
		else{
			scanf("%d%d%d%d%d",&X1,&Y1,&X2,&Y2,&v);
			T.Update(1,1,n,X1,X2,v,Y1,Y2);
		}
	}
}
int main(){
	init();
	return 0;
}