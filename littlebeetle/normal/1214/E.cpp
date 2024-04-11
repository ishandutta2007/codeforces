#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
struct p{
	int x,y;
	bool operator<(const p &k)const{
		return k.y<y;
	}
}e[N];
int n,i,id[N];
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&e[i].y),e[i].x=2*i-1;
}
void work(){
	sort(e+1,e+n+1);
	for(i=1;i<=n;i++)
		id[i]=e[i].x;
	for(i=1;i<n;i++)
		printf("%d %d\n",id[i],id[i+1]);
	for(i=1;i<=n;i++){
		printf("%d %d\n",id[i+e[i].y-1],id[i]+1);
		if(!id[i+e[i].y])
			id[i+e[i].y]=id[i]+1;
	}
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}