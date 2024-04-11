#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int c,d;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&c,&d);
		if(c+d&1) puts("-1");
		else if(c==0&&d==0) puts("0");
		else if(c==d) puts("1");
		else puts("2");
	}
	return 0;
}