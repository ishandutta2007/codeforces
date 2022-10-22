#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,a[MAXN];
int ans[505][505];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=1; i<=n; i++){
		int x=i,y=i,k=a[i];
		while(k){
			if(y>1&&!ans[x][y-1]) ans[x][y--]=a[i];
			else ans[x++][y]=a[i];
			k--;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}