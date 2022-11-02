#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int n,k,p[N],a[N],i,j,l,st[N],top,Lst;
int min(int x,int y){
	return x<y?x:y;
}
bool ok(){
	for(i=1;i<=n;i++){
		st[++top]=p[i];
		while(st[top]==Lst+1)
			Lst=st[top],top--;
	}
	return top==0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++)
		scanf("%d",p+i),
		a[i]=p[i];
	sort(a+1,a+k+1);
	a[k+1]=n+1;
	for(j=0;j<=k;j++){
		l=a[j+1]-a[j]-1;
		while(l)
			p[i++]=a[j]+l,l--;
	}
	if(ok()){
		for(i=1;i<=n;i++)
			printf("%d ",p[i]);
	}
	else
		printf("-1");
}