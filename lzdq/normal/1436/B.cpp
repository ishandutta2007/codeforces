#include<cstdio>
#include<cmath>
using namespace std;
int n;
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++,puts(""))
			for(int j=1; j<=n; j++){
				if(abs(i-j)<=1) printf("1 ");
				else printf("0 ");
			}
	}
	return 0;
}