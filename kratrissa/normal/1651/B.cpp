#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n>=20){printf("NO\n");continue;}
		printf("YES\n");
		for(int i=1,pw=1;i<=n;i++)printf("%d ",pw),pw*=3;printf("\n");
	}
	return 0;
}