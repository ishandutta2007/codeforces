#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m;
int ans[MAXN];
void Calc(int n,int m){
	for(int i=1; i*i<=n; i++)
		if(n%i==0){
			int t=i;
			if(m%t==0) ans[++*ans]=t;
			t=n/i;
			if(m%t==0) ans[++*ans]=t;
		}
	return ;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		ans[*ans=1]=2;
		Calc(n,m-2);
		Calc(n-2,m);
		Calc(n-1,m-1);
		sort(ans+1,ans+*ans+1);
		*ans=unique(ans+1,ans+*ans+1)-ans-1;
		printf("%d",*ans);
		for(int i=1; i<=*ans; i++)
			printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}