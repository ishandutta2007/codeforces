#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++,puts(""))
			for(int j=1; j<=m; j++)
				if(i==1&&j==1) putchar('W');
				else putchar('B');
	}
	return 0;
}