#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int main(){
	int x;
	scanf("%d%d",&n,&m);
	int res = m;
	while(n--){
		scanf("%d",&x);
		if(m%x==0)
			res = min(res, m/x);
	}
	printf("%d\n",res);
	return 0;
}