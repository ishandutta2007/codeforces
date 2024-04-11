#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int x,y;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&x,&y);
		if(x>y) printf("%d\n",x+y);
		else printf("%d\n",y/x*x+y>>1);
	}
	return 0;
}