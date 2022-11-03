#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define lb long double
#define N 105
using namespace std;

int n,a[N][N];
char c[N][N];

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	
	scanf("%d",&n);
	rep(i,1,n) scanf("%s",c[i]+1);
	rep(i,1,n) rep(j,1,n){
		int sum=0;
		if(c[i][j-1]=='o')++sum;
		if(c[i][j+1]=='o')++sum;
		if(c[i-1][j]=='o')++sum;
		if(c[i+1][j]=='o')++sum;
		if(sum&1){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	
		
}