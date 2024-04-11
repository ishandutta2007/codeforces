#include<cstdio>
const int N=1000002;
int n,x,y,l[N],r[N],val[N],i,k,t;
bool ok[N];
int main(){
	scanf("%d",&n);
	for(i=0;i<N;i++)
		l[i]=r[i]=-1;
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		r[x]=y;l[y]=x;
	}
	for(i=r[0],k=2;i&&i!=-1;i=r[i],k+=2){
		val[k]=i;
		ok[i]=1;
		t=i;
	}
	for(i=1;i<N;i++)
		if(l[i]==-1&&r[i]>=0&&!ok[i])
			break;
	for(k=1;i&&i!=-1;i=r[i],k+=2)
		val[k]=i;
	for(i=1;i<=n;i++)
		printf("%d ",val[i]);
}