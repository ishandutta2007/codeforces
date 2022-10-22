#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int a,b;
bool Check(int k){
	int t=(a+b+1)/2+k-a;
	if(t%2==0&&t>=0&&t/2<=k&&t/2<=(a+b+1)/2&&t/2>=k-(a+b)/2) return 1;
	t=(a+b+1)/2+k-b;
	if(t%2==0&&t>=0&&t/2<=k&&t/2<=(a+b+1)/2&&t/2>=k-(a+b)/2) return 1;
	return 0;
}
int ans[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&a,&b);
		*ans=0;
		for(int i=0; i<=a+b; i++)
			if(Check(i)) ans[++*ans]=i;
		printf("%d\n",*ans);
		for(int i=1; i<=*ans; i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}