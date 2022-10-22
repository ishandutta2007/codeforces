#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=1005;
int n,k;
int c[MAXN][MAXN],s[MAXN][MAXN];
int F(int n,int k){
	if(n==1) return 0;
	int x=F((n+k-1)/k,k)+1;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++){
			int a=(i+k-1)/k,b=(j+k-1)/k;
			if(a==b) s[i][j]=x;
			else s[i][j]=c[a][b];
		}
	memcpy(c,s,sizeof(s));
	return x;
}
int main(){
	scanf("%d%d",&n,&k);
	printf("%d\n",F(n,k));
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			printf("%d ",c[i][j]);
	puts("");
	return 0;
}