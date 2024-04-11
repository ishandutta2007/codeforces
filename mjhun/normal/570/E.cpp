#include <cstdio>
#define MOD 1000000007

inline unsigned int summod(unsigned int a,unsigned int b){
	unsigned int r=a+b;
	if(r>=MOD)r-=MOD;
	return r;
}

unsigned int dp[512][512];
char s[512][512];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s",s[i]);
	}
	for(int y2=0;y2<n;++y2){
		for(int x2=0;x2<m;++x2){
			int xy=n+m+-y2-x2-2;
			for(int y1=0;y1<n;++y1){
				int x1=xy-y1;
				if(y1>y2||x1>x2||x1<0){
					dp[x2][y1]=0;
				}
				else if(y1==y2){
					if(x1==x2){
						dp[x2][y1]=1;
					}
					else if(x1+1==x2){
						dp[x2][y1]=s[y1][x1]==s[y2][x2];
					}
					else {
						dp[x2][y1]=s[y1][x1]==s[y2][x2]&&dp[x2-1][y1];//y2
					}
				}
				else if(x1==x2){
					if(y1+1==y2){
						dp[x2][y1]=s[y1][x1]==s[y2][x2];
					}
					else {
						dp[x2][y1]=s[y1][x1]==s[y2][x2]&&dp[x2][y1+1];//y2-1
					}
				}
				else if(s[y1][x1]!=s[y2][x2]){
					dp[x2][y1]=0;
				}
				else {
					dp[x2][y1]=summod(dp[x2][y1],dp[x2][y1+1]);
					dp[x2][y1]=summod(dp[x2][y1],dp[x2-1][y1+1]);
					dp[x2][y1]=summod(dp[x2][y1],dp[x2-1][y1]);
					//*dp[y2-1][x2][y1+1] + *dp[y2-1][x2][y1] + *dp[y2][x2-1][y1+1] + dp[y2][x2-1][y1];
				}
			}
		}
	}
	printf("%d\n",dp[m-1][0]);
	return 0;
}