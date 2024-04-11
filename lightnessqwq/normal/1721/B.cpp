#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int T,n,m,x,y,d;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&n,&m,&x,&y,&d);
		if((x-1<=d||m-y<=d)&&(n-x<=d||y-1<=d))
			puts("-1");
		else printf("%d\n",n+m-2);
	}
	return 0;
}