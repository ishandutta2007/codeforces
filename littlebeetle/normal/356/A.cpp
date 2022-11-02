#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300002;
int n,m,i,l,r,x,fa[N],winr[N];
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
void work(int l,int r,int x){
	while((l=p(l))<=r){
		winr[l]=x;
		fa[l]=l+1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+1;i++)
		fa[i]=i;
	while(m--){
		scanf("%d%d%d",&l,&r,&x);
		work(l,x-1,x);
		work(x+1,r,x);
	}
	for(i=1;i<=n;i++)
		printf("%d ",winr[i]);
	//while(1);
}