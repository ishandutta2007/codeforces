#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=100005;

int n,k;

void solve(){
	scanf("%d%d",&n,&k);
	rep(i,1,9){
		if(i*n%10==k || i*n%10==0){
			printf("%d\n",i);
			return;
		}
	}
	puts("10");
}

int main(){
	//	freopen("1.in","r",stdin);
	//	Freopen("1.out","w",stdout);

	int ca=1;
	//scanf("%d",&ca);
	while(ca--){
		solve();
	}
}