#include<bits/stdc++.h>
using namespace std;
int main(){
	int _,a,b,c,d;
	for(scanf("%d",&_); _--;){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",max(max(
		min(a,b) * min(c,d),
		min(a,c) * min(b,d)),
		min(a,d) * min(b,c)));
	}
	return 0;
}