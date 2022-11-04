#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s;
	cin>>n>>s;
	if(2*n>s) puts("NO");
	else{
		puts("YES");
		for(int i=1;i<=n-1;i++) printf("2 ");
		printf("%d\n",s-2*(n-1));
		puts("1");
	}
	return 0;
}