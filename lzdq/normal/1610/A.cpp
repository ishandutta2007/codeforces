#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		if(n==1&&m==1) puts("0");
		else if(n==1||m==1) puts("1");
		else puts("2");
	}
	return 0;
}