#include<bits/stdc++.h>
using namespace std;
bool a[1111111];
int main(){
	int n,m,k,u,v,x;
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		scanf("%d",&x);
		a[x] = true;
	}
	x=1;
	while(k--){
		if(a[x])break;
		scanf("%d%d",&u,&v);
		if(u==x)x=v;else
		if(v==x)x=u;
	}
	printf("%d\n",x);
	return 0;
}