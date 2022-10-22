#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,d;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(min(a,b)>max(c,d)||max(a,b)<min(c,d)) puts("NO");
		else puts("YES");
	}
	return 0;
}