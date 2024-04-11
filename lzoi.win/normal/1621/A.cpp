#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=100;
int n,k;
char s[MAXN][MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&k);
		if(k*2-1<=n){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++)
					s[i][j]='.';
				s[i][n+1]=0;
			}
			for(int i=1; i<=k; i++)
				s[i*2-1][i*2-1]='R';
			for(int i=1; i<=n; i++)
				puts(s[i]+1);
		}else puts("-1");
	}
	return 0;
}