#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int q,n,r,m,i,a[N],b[N],Ans;
void init(){
	scanf("%d%d",&n,&r);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	m=0;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		if(a[i]!=a[i-1])
			b[++m]=a[i];
}
int min(int x,int y){
	return x<y?x:y;
}
void work(){
	Ans=1<<30;
	for(i=0;i<m;i++)
		if(b[i]<=(m-i)*r)
			Ans=min(Ans,m-i);
	printf("%d\n",Ans);
}
int main(){
	scanf("%d",&q);
	while(q--){
		init();
		work();
	}
	return 0;
}