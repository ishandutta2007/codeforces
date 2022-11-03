#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define N 105

int n,f[N][N];
char s[N];

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n){
		if(s[i]=='*'){
			rep(j,1,i-1) if(s[i-j]=='*'){
				f[i][j]=f[i-j][j]+1;
				if(f[i][j]==4){
					puts("yes");
					return 0;
				}
			}
		}
	}
	puts("no");
}