#include<bits/stdc++.h>
using namespace std;
bool chk(){
	int c1,c2,c3;
	scanf("%d%d%d",&c1,&c2,&c3);
	int a1,a2,a3,a4,a5;
	scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
	c1 -= a1;
	c2 -= a2;
	c3 -= a3;
	if(c1 < 0 || c2 < 0 || c3 < 0)return false;
	a4 -= min(a4, c1);
	a5 -= min(a5, c2);
	return a4 + a5 <= c3;
}
int main(){
	int _;
	for(scanf("%d",&_); _--;){
		puts(chk()?"YES":"NO");
	}
	return 0;
}