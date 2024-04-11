#include<cstdio>
#include<algorithm>
using namespace std;
const int N=800002,Inf=1<<30;
int n,m,i,j,k,a[N],b[N],d[N],x,y,Ans[N];
int D,t[N];
int val[N],pre[N];
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
void init(){
	scanf("%d",&n);
	x=1<<30;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		d[i]=i;
		x=min(x,a[i]);
		y=max(y,a[i]);
	}
}
bool cmp(int x,int y){
	return a[x]<a[y];
}
void Update(int x,int y){
	x+=D;
	while(x)
		t[x]=min(t[x],y),x>>=1;
}
int Query(int x,int y){
	int s=Inf;
	for(x+=D-1,y+=D+1;x^y^1;x>>=1,y>>=1){
		if(~x&1)s=min(s,t[x^1]);
		if(y&1)s=min(s,t[y^1]);
	}
	return s;
}
void work(){
	if(x*2>=y){
		for(i=1;i<=n;i++)
			printf("-1 ");
		return;
	}
	sort(d+1,d+n+1,cmp);
	a[0]=-1;
	for(i=1;i<=n;i++)
		b[d[i]]=b[d[i-1]]+(a[d[i]]!=a[d[i-1]]);
	m=b[d[n]];
	for(i=1;i<=n;i++)
		val[b[i]]=a[i];
	for(i=1,k=0;i<=m;i++){
		while(val[k+1]*2<val[i])
			k++;
		pre[i]=k;
	}
	for(D=1;D<m+2;D<<=1);
	for(i=1;i<D*2;i++)t[i]=Inf;
	for(i=1;i<=n;i++)
		Update(b[i],i+n);
	Ans[n+1]=Inf;
	for(i=n;i;i--){
		Ans[i]=min(Ans[i+1],Query(1,pre[b[i]]));
		Update(b[i],i);
	}
	Ans[n+1]=Ans[1]+n;
	for(i=n;i;i--)
		Ans[i]=min(Ans[i],Ans[i+1]);
	for(i=1;i<=n;i++)
		printf("%d ",Ans[i]-i);
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}