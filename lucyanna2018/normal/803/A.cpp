#include<bits/stdc++.h>
using namespace std;
int a[111][111],n,k;
int main(){
	scanf("%d%d",&n,&k);
	if(k > n*n){
		puts("-1");
		return 0;
	}
	for(int i=1; i<=n && k>0; i++)
	for(int j=1; j<=n && k>0; j++)
		if(a[i][j] == 0){
			if(i==j){
				a[i][j] = 1;
				k--;
			}else
			if(k>=2){
				a[i][j] = a[j][i] = 1;
				k-=2;
			}
		}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			printf("%d%c",a[i][j],j<n?' ':'\n');
	return 0;
}