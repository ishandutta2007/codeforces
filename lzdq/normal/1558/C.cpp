#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2077;
int n,a[MAXN],w[MAXN];
int ans[MAXN*10];
inline void fuck(int x){
	ans[++*ans]=x;
	reverse(a+1,a+x+1);
	for(int i=1; i<=x; i++)
		w[a[i]]=i;
}
void Calc(){
	for(int i=1; i<=n; i++)
		if((a[i]^i)&1){
			puts("-1");
			return ;
		}
	for(int i=n; i>1; i-=2){
		fuck(w[i]);
		fuck(w[i-1]-1);
		fuck(w[i-1]+1);
		fuck(3);
		fuck(i);
	}
	printf("%d\n",*ans);
	for(int i=1; i<=*ans; i++)
		printf("%d ",ans[i]);
	puts("");
	//for(int i=1; i<=n; i++) printf("%d ",a[i]); puts("");
	return ;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		*ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),w[a[i]]=i;
		Calc();
	}
	return 0;
}