#include<bits/stdc++.h>
using namespace std;
int main(){
	int res=0,s,e,n;
	scanf("%d%d%d",&n,&s,&e);
	for(scanf("%d",&n); n--;){
		int x;
		scanf("%d",&x);
		if(s < x && x < e)
			res++;
	}
	printf("%d\n",res);
	return 0;
}