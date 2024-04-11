#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n>m){
			puts("No");
			continue;
		}
		if(n&1){
			puts("Yes");
			for(int i=1;i<n;i++)
				printf("1 ");
			printf("%d\n",m-n+1);
			continue;
		}
		if(m&1){
			puts("No");
			continue;
		}
		puts("Yes");
		for(int i=1;i<n-1;i++)
			printf("1 ");
		printf("%d %d\n",(m-n+2)/2,(m-n+2)/2);
	}
	return 0;
}