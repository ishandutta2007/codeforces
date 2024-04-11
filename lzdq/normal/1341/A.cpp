#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,a,b,c,d;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
		if(n*(a-b)>c+d||n*(a+b)<c-d) puts("No");
		else puts("Yes");
	}
	return 0;
}