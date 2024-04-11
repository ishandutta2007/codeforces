#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int f[128][2];

int main(){
	int n,k,d;
	scanf("%d%d%d",&n,&k,&d);
	f[0][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=1;++j){
			f[i][j]=0;
			for(int l=1;l<=min(i,k);++l){
				f[i][j]+=f[i-l][j||l>=d];
				f[i][j]%=MOD;
			}
		}
	}
	printf("%d\n",f[n][0]);
	return 0;
}