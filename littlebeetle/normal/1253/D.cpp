#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200020;
int n,m,i,j,k,a,b;
int fa[N],cnt;
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		fa[i]=i;
}
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
void work(){
	while(m--){
		scanf("%d%d",&a,&b);
		a=p(a);b=p(b);
		if(a!=b){
			if(a<b)
				fa[a]=b;
			else
				fa[b]=a;
		}
	}
	for(i=1;i<=n;i++)
		if(i!=p(i)&&p(i)!=p(i+1)){
			a=p(i);b=p(i+1);
			if(a<b)
				fa[a]=b;
			else
				fa[b]=a;
			cnt++;
		}
	printf("%d",cnt);
}
int main(){
	init();
	work();
	//while(1);
	return 0;
}