#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n&1)
			printf("1 ");
		for(int i=1+(n&1);i<=n;i+=2)
			printf("%d %d ",i+1,i);
		puts("");
	}
	return 0;
}