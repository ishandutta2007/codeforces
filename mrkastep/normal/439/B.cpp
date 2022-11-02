#include <stdio.h>
#include <algorithm>

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int d[100000],n,x,i;
	long long int s;
	scanf("%d%d",&n,&x);
	for(i=0;i<n;i++) scanf("%d",&d[i]);
	std::sort(d,d+n);
	s=0;
	for(i=0;i<n;i++){
		if(x-i>0){
			s=s+(long long int)((long long int)(x-i)*(long long int)d[i]);
		}
		else{
			s=s+(long long int)d[i];
		}
	}
	printf("%I64d",s);
}