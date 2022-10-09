#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=200111;
int w[MAXN],h[MAXN];
main(){
	int n;scanf("%d",&n);
	LL totw=0;
	LL max1=0,max2=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&h[i]);
		totw+=w[i];
		if(h[i]>=max1) max2=max1,max1=h[i];
		else if(h[i]>max2) max2=h[i];
	}
	for(int i=1;i<=n;i++){
		LL odp=(totw-w[i]);
		if(h[i]==max1) odp*=max2;
		else odp*=max1;
		printf("%I64d ",odp);
	}
	puts("");
	return 0;
}