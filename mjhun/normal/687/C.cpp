#include <bits/stdc++.h>
using namespace std;

int n,k,c;
bool f[512][512];

int main(){
	scanf("%d%d",&n,&k);
	f[0][0]=true;
	while(n--){
		scanf("%d",&c);
		for(int i=k;i>=c;--i){
			for(int j=i;j>=0;--j){
				f[i][j]|=f[i-c][j];
				if(c<=j)f[i][j]|=f[i-c][j-c];
			}
		}
	}
	int r=0;
	for(int i=0;i<=k;++i)if(f[k][i])r++;
	printf("%d\n",r);
	r=0;
	for(int i=0;i<=k;++i)if(f[k][i]){
		if(r)printf(" ");else r=1;
		printf("%d",i);
	}
	puts("");
	return 0;
}