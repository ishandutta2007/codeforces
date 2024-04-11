#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1005;
int n,a[MAXN][MAXN],ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d",a[i]+j);
		ans=0;
		for(int i=n; i>0; i-=4)
			for(int x=1,y=i; y<=n; x+=2,y+=2){
				ans^=a[x][y];
				ans^=a[x][n-y+1];
			}
		for(int i=n-2; i>0; i-=4)
			for(int x=i,y=1; x<=n; x+=2,y+=2){
				ans^=a[x][y];
				ans^=a[x][n-y+1];
			}
		printf("%d\n",ans);
	}
	return 0;
}