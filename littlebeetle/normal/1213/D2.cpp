#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4000020;
int n,x[N],k,a,l,i,ans=1<<30;
int min(int x,int y){
	return x<y?x:y;
}
struct Tire{
	int ch[N][2],sz[N],sum[N],cnt=1;
	void insert(int a,int l){
		for(int i=1,j=l;j>=0;j--){
			if(!ch[i][a>>j&1])
				ch[i][a>>j&1]=++cnt;
			i=ch[i][a>>j&1];
			sz[i]++;
			sum[i]+=j;
			if(sz[i]==k)
				ans=min(ans,sum[i]);
		}
	}
}T;
void init(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",x+i);
	sort(x+1,x+n+1);
	for(i=1;i<=n;i++){
		a=x[i];
		l=0;
		while(a>>l)l++;
		T.insert(a,l);
	}
	printf("%d",ans);
}
int main(){
	init();
//	work();
	return 0;
}