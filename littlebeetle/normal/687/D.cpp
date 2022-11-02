#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
struct p{
	int x,y,z,id;
	bool operator<(const p &k)const{
		return k.z<z;
	}
}e[N];
int n,m,q,i,j,k,u,v,ans,l,r,fa[N*2];
void init(){
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z),e[i].id=i;
	sort(e+1,e+m+1);
}
int anc(int x){
	return x==fa[x]?x:fa[x]=anc(fa[x]);
}
void merge(int x,int y){
	x=anc(x);
	y=anc(y);
	if(x!=y)
		fa[x]=y;
}
void work(){
	while(q--){
		ans=-1;
		scanf("%d%d",&l,&r);
		for(i=1;i<=2*n;i++)
			fa[i]=i;
		for(i=1;i<=m;i++)
			if(l<=e[i].id&&e[i].id<=r){
				u=e[i].x;v=e[i].y;
				merge(u,v+n);
				merge(u+n,v);
				if(anc(u)==anc(u+n)){
					ans=e[i].z;
					break;
				}
			}
		printf("%d\n",ans);
	}
}
int main(){
	init();
	work();
	//while(1);
	return 0;
}