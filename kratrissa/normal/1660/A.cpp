#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,a,b;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if(a==0)printf("1\n");
		else printf("%d\n",a+b*2+1);
	}
	return 0;
}