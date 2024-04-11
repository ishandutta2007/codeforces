#include<cstdio>
const int N=400002;
typedef long long ll;
int n,D,q,i,a[N],x,y,k,p,l,r,mid;
ll t[N],s;
void add(int x,int y){
	while(x<=D)
		t[x]+=y,x+=x&-x;
}
void init(){
	scanf("%d%d",&n,&q);
	for(D=1;D<n+3;D<<=1);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		add(i,a[i]);
	}
}
ll sum(int x){
	s=0;
	while(x)
		s+=t[x],x-=x&-x;
	return s;
}
int Get(ll x){
	l=0;r=D;
	while(l+1<r){
		mid=l+r>>1;
		if(t[mid]<x)
			x-=t[mid],l=mid;
		else
			r=mid;
	}
	return r;
}
void work(){
	while(q--){
		scanf("%d%d",&x,&y);
		add(x,y-a[x]);
		a[x]=y;
		k=0;
		while(1){
			p=Get(sum(k)*2);
			if(sum(p)==sum(p-1)*2){
				printf("%d\n",p);
				break;
			}
			if(p>n){
				printf("-1\n");
				break;
			}
			k=p;
		}
	}
}
int main(){
	init();
	work();
}