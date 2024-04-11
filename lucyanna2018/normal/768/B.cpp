#include<stdio.h>
#include<map>
using namespace std;
#define int64 long long int
int64 n,l,r;
int64 a[99],len[99];int la;
int calc(int64 n,int i,int64 pos){
	if(pos <= len[i+1])
		return calc(n/2, i+1, pos);
	if(pos == len[i+1] + 1)
		return (int)(n%2);
	return calc(n/2, i+1, pos - (len[i+1]+1));
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&l,&r);
	la = 0;
	for(int64 x = n; x > 1; x/=2)
		a[la++] = x;
	a[la++] = 1;
	len[la] = 0;
	for(int i=la-1; i>=0; i--)
		len[i] = 2 * len[i+1] + 1;
	int64 res = 0;
	for(int64 i = l; i <= r; i++)
		res += calc(n, 0, i);
	printf("%I64d\n",res);
	return 0;
}