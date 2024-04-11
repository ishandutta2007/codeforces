#include<stdio.h>
#include<algorithm>
using namespace std;
#define uint64 unsigned long long int
uint64 a[111111],s,b[111111];
int n;
uint64 calc(uint64 x){
	for(int i=1; i<=n; i++)
		b[i] = a[i] + (uint64)i * x;
	sort(b+1,b+n+1);
	uint64 tot = 0;
	for(int i=1; i<=x; i++)
		tot += b[i];
	return tot;
}
int main(){
	scanf("%d%I64u",&n,&s);
	for(int i=1; i<=n; i++)
		scanf("%I64u",&a[i]);
	int lo = 0, hi = n;
	while(lo!=hi){
		int mi = (lo+hi+1)/2;
		if(calc(mi) <= s)
			lo = mi;
		else
			hi = mi-1;
	}
	printf("%d %I64u\n",lo,calc(lo));
	return 0;
}